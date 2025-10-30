#include "stdint.h"

#define PERIPHERAL_BLOCK2_BASE (0x40000000U)
#define AHB1_BASE (PERIPHERAL_BLOCK2_BASE + 0x20000U)

/* Peripheral Bases*/
#define GPIOA_BASE (AHB1_BASE + 0x0U)
#define GPIOB_BASE (AHB1_BASE + 0x400U)
#define RCC_BASE (AHB1_BASE + 0x3800U)

/* HAVE REGISTER VALUES BE VOLATILE */
//Used for reintializing peripherals
#define RCC_AHB1ENR_OFFSET (0x30U)
#define RCC_AHB1ENR ((volatile uint32_t*) (RCC_BASE + RCC_AHB1ENR_OFFSET))
#define RCC_AHB1ENR_GPIOAEN (0x00U)
#define RCC_AHB1ENR_GPIOBEN (0x01U)

/* PORT A PIN 5*/
#define GPIO_MODER_OFFSET (0x00U)

#define GPIOA_MODER ((volatile uint32_t*) (GPIOA_BASE + GPIO_MODER_OFFSET))
#define GPIOB_MODER ((volatile uint32_t*) (GPIOB_BASE + GPIO_MODER_OFFSET))

#define GPIO_MODER_MODER0 (0U)
#define GPIO_MODER_MODER5 (10U)
#define GPIO_ODR_OFFSET (0x14U)

/* Set value of register */
#define GPIOA_ODR ((volatile uint32_t*) (GPIOA_BASE + GPIO_ODR_OFFSET))
#define GPIOB_ODR ((volatile uint32_t*) (GPIOB_BASE + GPIO_ODR_OFFSET))

#define LED_PIN 0

void _init(void) {}

int main(void)
{
  /* Enable Port A clock */
  //*RCC_AHB1ENR |= (1 << RCC_AHB1ENR_GPIOAEN);

  /* Enable PORTA clock */
  *RCC_AHB1ENR |= (1 << RCC_AHB1ENR_GPIOBEN);

  // do two dummy reads after enabling the peripheral clock, as per the errata
  volatile uint32_t dummy;
  dummy = *(RCC_AHB1ENR);
  dummy = *(RCC_AHB1ENR);

  /* Mode of the GPIO Pin*/
  //*GPIOA_MODER |= (1 << GPIO_MODER_MODER5);
  *GPIOB_MODER |= (1 << GPIO_MODER_MODER0);
  
  while(1)
  {
    //*GPIOA_ODR ^= (1 << LED_PIN);
    *GPIOB_ODR ^= (1 << LED_PIN);
    for (uint32_t i = 0; i < 1000000; i++);
  }
  return 0;
}