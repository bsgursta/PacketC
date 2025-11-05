/* GPIO DRIVER FOR STM32 Microcontroller */
/* Initially developed for F7 family/M7 */

#include "gpio.hpp"
#include "macros.hpp"
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
StatusType gpioMODERset(GPIO_TypeDef *port, uint8_t pin,uint8_t mode) {
    //check pin valid
    if(!checkPinValid(pin)) return STATUS_ERR;
    port->MODER |= (mode << (2*pin));

    //add check to make sure pin was set
    return STATUS_OK;
}

/* GPIOx_OTYPER 
        USE CASE: change output type: push/pull (SPI) OR open_drain (I2C)
*/
StatusType gpioOTYPERset(GPIO_TypeDef *port, uint8_t pin, uint8_t out_type) {
        if(!checkPinValid(pin)) return STATUS_ERR;
        port->OTYPER |= (out_type << pin);
        return STATUS_OK;
}

/* GPIOx_OSPEEDR
        USE CASE: Configure I/O output speed
*/
StatusType gpioOSPEEDRset(GPIO_TypeDef *port, uint8_t pin, uint8_t speed) {
        if(!checkPinValid(pin)) return STATUS_ERR;
        port->OTYPER |= (speed << (2*pin));
        return STATUS_OK;
} 

/*  GPIOx_PUPDR
        USE CASE: Configure I/O default logic
*/

/*  GPIOx_IDR
        USE CASE: Read bits from corresponding input port/pin
*/
StatusType gpioIDRread() {}


//CONSIDER : maybe make two separate functions
/*  GPIOx_ODR
        USE CASE: Set output state and read its state 
*/
StatusType gpioODRreadwrite() {}

/*  GPIOx_BSRR
        USE CASE: Reset OR Set/Reset Pins
*/
StatusType gpioBSRRset() {}

/*  GPIOx_LCKR
        USE CASE: Lock all/specific registers to values
*/

StatusType gpioLCKRset() {}

/*  GPIOx_AFRH & GPIOx_AFRGL
        USE CASE: Set specific uses for alternative functions
*/
StatusType gpioAFRHLset() {}
