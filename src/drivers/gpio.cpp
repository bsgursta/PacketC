/* GPIO DRIVER FOR STM32 Microcontroller */
/* Initially developed for F7 family/M7 */

#include "gpio.hpp"
#include "stm32f767xx.h"

/* TEMP USEFUL FUNCTIONS */

//Check if pin is valid
int checkPinValid(uint8_t pin_num) {
    if(pin_num > 15 || pin_num < 0) {
        return 0;
    }
    return 1;
}


// The following functions have functionality for PORTS A-K

/* GPIOx_MODER
    USE CASE: configre gpio input/output, alternate function(Serial protocol), analog mode
*/
void gpioMODERset(GPIO_TypeDef *port, uint8_t pin,uint8_t mode) {
    //check pin valid
    if(!checkPinValid(pin)) return 0; //SWAP TO WHATEVER I DECIDE
    port->MODER |= (mode << (2*pin));
    return 1; //SWAP TO VALUE
}

/* GPIOx_OTYPER 
        USE CASE: change output type: push/pull (SPI) OR open_drain (I2C)
*/
void gpioOTYPERset() {}

/* GPIOx_OSPEEDR
        USE CASE: Configure I/O output speed
*/
void gpioOSPEEDRset() {}

/*  GPIOx_PUPDR
        USE CASE: Configure I/O default logic
*/

/*  GPIOx_IDR
        USE CASE: Read bits from corresponding input port/pin
*/
void gpioIDRread() {}


//CONSIDER : maybe make two separate functions
/*  GPIOx_ODR
        USE CASE: Set output state and read its state 
*/
void gpioODRreadwrite() {}

/*  GPIOx_BSRR
        USE CASE: Reset OR Set/Reset Pins
*/
void gpioBSRRset() {}

/*  GPIOx_LCKR
        USE CASE: Lock all/specific registers to values
*/

void gpioLCKRset() {}

/*  GPIOx_AFRH & GPIOx_AFRGL
        USE CASE: Set specific uses for alternative functions
*/
void gpioAFRHLset() {}
