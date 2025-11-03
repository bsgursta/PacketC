//used to program BuyDisplay OLEDs

#include <lcd.h>
#include "main.h"
#include "stm32f7xx_hal.h"

HAL_StatusTypeDef lcd_transfer(uint8_t data){
	//pull CS low
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);

	//transmit the data

	HAL_StatusTypeDef status = HAL_SPI_Transmit(&hspi2, &data, 1, 1000);
	if (status == HAL_OK){

	}
	//pull CS high
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);

	return HAL_OK;

}

//Reset lcd settings
HAL_StatusTypeDef lcd_reset(void){
	//pull RES pin down
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);

	//pull RES pin up
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);

	return HAL_OK;
}

//turn LCD on to match RAM data
HAL_StatusTypeDef  onLCD(void){

	//lcd on data
	uint8_t data = 0xAF;

	//pull A0 low (PD7)
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);


	return lcd_transfer(data);

}

//force all pixels on screen to turn on
HAL_StatusTypeDef  lcd_ALLpixels(void){

	//lcd on data
	uint8_t data = 0xA5;

	//pull A0 low (PD7)
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);


	return lcd_transfer(data);

}

//only display pixels saved in RAM when lcd ON
HAL_StatusTypeDef  lcd_RAMpixels(void){

	//lcd on data
	uint8_t data = 0xA4;

	//pull A0 low (PD7)
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);


	return lcd_transfer(data);
}


//turn lcd OFF
HAL_StatusTypeDef  offLCD(void){

	//lcd off data
	uint8_t data = 0xAE;

	//pull A0 low (PD7)
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);

	return lcd_transfer(data);
}




//set page(horizontal) addressing after R/W a byte of SPI data
HAL_StatusTypeDef setPageaddressing(){
	uint8_t data = 0x20;

	//pull A0 low (PD7)
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);

	return lcd_transfer(data);
}

//set vertical addressing after R/W a byte of SPI data
HAL_StatusTypeDef setVerticaladdressing(){

	uint8_t data = 0x21;

	//pull A0 low (PD7)
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);


	return lcd_transfer(data);
}


//set the page address for writing pixels
//page number must be between 0-15
HAL_StatusTypeDef  lcd_setpage_address(int page_num){

	//convert int to uint8
	uint8_t pg_num = page_num;
	//data byte for page address
	uint8_t data = 0xB0 | pg_num;

	//pull A0 low (PD7)
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);

	return lcd_transfer(data);
}

//set the column address for writing pixels
// must be between 0 and 127, there are 128 columns
HAL_StatusTypeDef  lcd_setcolumn_address(int column_num){

	if(column_num >= 128 || column_num < 0){
		return HAL_ERROR;
	}

	uint8_t num_conv = (uint8_t) column_num;

	uint8_t high_address = 0b00010000;
	uint8_t low_address = 0x00;

	high_address = high_address | ((num_conv >> 4) & 0x0F);
	low_address = low_address | (num_conv & 0x0F);

	//pull A0 low (PD7)
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);

	if(lcd_transfer(high_address) != HAL_OK){
		return HAL_ERROR;
	}
	if(lcd_transfer(low_address) != HAL_OK){
		return HAL_ERROR;
	}

	return HAL_OK;
}

HAL_StatusTypeDef lcd_writeRAM(uint8_t data){
	//pull A0 high
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);

	HAL_StatusTypeDef status = lcd_transfer(data);

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);

	return status;
}

//initialize SPI protocol with 4 wire setup
//includes SCL,SI,A0, and /CS
//Pins: PB10 -> SCK, PC3 -> SI(MOSI), RES -> PC0, A0(D/C) -> PD7, CS -> PD6
HAL_StatusTypeDef lcd_4SPI_init(){
	//pull CS high
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);

	//pull RES pin up
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);

	//dummy transmission for SPI

	onLCD();
	offLCD();

	//this is the column where the lcd starts
	lcd_setcolumn_address(32);

	return HAL_OK;

}

//set the entirety of the screen to 0, wiping the screen.
HAL_StatusTypeDef  clearLCD(void){

	int errors = 0;

	for(int a = 0; a < 16; a++){
		lcd_setpage_address(a);
		lcd_setcolumn_address(0);

		for(int i = 0; i < 128; i++){
			//starting point for my LCD
			if(i == 32){
				__NOP();
			}

			//ending point of my LCD
			if(i == 97){
				__NOP();
			}

			if(lcd_writeRAM(0x00) != HAL_OK){
				errors += 1;
			}
			//HAL_Delay(10);
		}
	}

	if(errors == 0){
		return HAL_OK;
	}
	else{
		return HAL_ERROR;
	}
}

//fill the LCD with 1 bits, making it turn off. Include delay for visual assistance
HAL_StatusTypeDef  fillLCD(void){

	int errors = 0;

	for(int a = 0; a < 16; a++){
		lcd_setpage_address(a);
		lcd_setcolumn_address(0);

		for(int i = 0; i < 128; i++){
			if(lcd_writeRAM(0xFF) != HAL_OK){
				errors +=1;
			}
			//HAL_Delay(5);
		}
	}

	if(errors == 0){
		return HAL_OK;
	}
	else{
		return HAL_ERROR;
	}
}

//print HELLO message
HAL_StatusTypeDef lcd_printHELLO(void){
	int errors = 0;

	lcd_setpage_address(1);
	lcd_setcolumn_address(32);

	//H
	if(lcd_writeRAM(0x7F) != HAL_OK){
		errors += 1;
	}
	if(lcd_writeRAM(0x08) != HAL_OK){
		errors += 1;
	}
	if(lcd_writeRAM(0x08) != HAL_OK){
		errors += 1;
	}
	if(lcd_writeRAM(0x7F) != HAL_OK){
		errors += 1;
	}

	//space
	if(lcd_writeRAM(0x00) != HAL_OK){
		errors += 1;
	}

	//E
	if(lcd_writeRAM(0x7F) != HAL_OK){
		errors += 1;
	}
	if(lcd_writeRAM(0x49) != HAL_OK){
		errors += 1;
	}
	if(lcd_writeRAM(0x49) != HAL_OK){
		errors += 1;
	}
	if(lcd_writeRAM(0x41) != HAL_OK){
		errors += 1;
	}
	//space
	if(lcd_writeRAM(0x00) != HAL_OK){
		errors += 1;
	}

	//L
	for(int i = 0; i < 2; i++){
		if(lcd_writeRAM(0x7F) != HAL_OK){
			errors += 1;
		}
		if(lcd_writeRAM(0x40) != HAL_OK){
			errors += 1;
		}
		if(lcd_writeRAM(0x40) != HAL_OK){
			errors += 1;
		}
		if(lcd_writeRAM(0x40) != HAL_OK){
			errors += 1;
		}
		//space
		if(lcd_writeRAM(0x00) != HAL_OK){
			errors += 1;
		}
	}

	//O
	if(lcd_writeRAM(0x7F) != HAL_OK){
		errors += 1;
	}
	if(lcd_writeRAM(0x41) != HAL_OK){
		errors += 1;
	}
	if(lcd_writeRAM(0x41) != HAL_OK){
		errors += 1;
	}
	if(lcd_writeRAM(0x7F) != HAL_OK){
		errors += 1;
	}


	if(errors == 0){
		return HAL_OK;
	}
	else{
		return HAL_ERROR;
	}
}
