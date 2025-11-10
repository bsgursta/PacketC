#pragma once

#include <stdint.h>

/* MODER */
#define GPIO_INPUT_MODE  (00U)
#define GPIO_OUTPUT_MODE (01U)
#define GPIO_ALT_MODE    (10U)
#define GPIO_ANALOG_MODE (11U)

/* OTYPER */
#define GPIO_OUTPUT_PUSHPULL (0U)
#define GPIO_OUTPUT_OPENDRAIN (1U)

/* OSPEEDR */
#define GPIO_LOWSPEED       (00U)
#define GPIO_MEDIUMSPEED    (01U)
#define GPIO_HIGHSPEED      (10U)
#define GPIO_VERYHIGHSPEED  (11U)

/* GPIO Prototypes */
StatusType gpioMODERset(GPIO_TypeDef*, uint8_t,uint8_t);
StatusType gpioOTYPERset(GPIO_TypeDef*, uint8_t, uint8_t);
StatusType gpioOSPEEDRset(GPIO_TypeDef*, uint8_t, uint8_t);
