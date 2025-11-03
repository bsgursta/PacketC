#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f7xx_hal.h"

//4-wire SPI

HAL_StatusTypeDef lcd_4SPI_init(void);
HAL_StatusTypeDef lcd_reset(void);

HAL_StatusTypeDef lcd_transfer(uint8_t data);

HAL_StatusTypeDef  clearLCD(void);
HAL_StatusTypeDef  fillLCD(void);

HAL_StatusTypeDef  onLCD(void);
HAL_StatusTypeDef  lcd_ALLpixels(void);
HAL_StatusTypeDef  offLCD(void);
HAL_StatusTypeDef  lcd_RAMpixels(void);

HAL_StatusTypeDef  lcd_setcolumn_address(int column_num);
HAL_StatusTypeDef  lcd_setpage_address(int page_num);

HAL_StatusTypeDef setPageaddressing(void);
HAL_StatusTypeDef setVerticaladdressing(void);

HAL_StatusTypeDef lcd_writeRAM(uint8_t data);

//printing commands
HAL_StatusTypeDef lcd_printHELLO(void);




#endif /* INC_LCD_H_ */
