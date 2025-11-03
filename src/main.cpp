#include <stdint.h>
#include "stm32f767xx.h"

void _init(void) {}

#define LED_PIN 0

int main(void)
{
  /* Enable Port A clock */
  //*RCC_AHB1ENR |= (1 << RCC_AHB1ENR_GPIOAEN);

  /* Enable PORTA clock */
  RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOBEN_Pos);

  // do two dummy reads after enabling the peripheral clock, as per the errata
  volatile uint32_t dummy;
  dummy = RCC->AHB1ENR;
  dummy = RCC->AHB1ENR;

  /* Mode of the GPIO Pin*/
  //*GPIOA_MODER |= (1 << GPIO_MODER_MODER5);
  GPIOB->MODER |= (1 << GPIO_MODER_MODER0_Pos);
  
  while(1)
  {
    //*GPIOA_ODR ^= (1 << LED_PIN);
    GPIOB->ODR ^= (1 << LED_PIN);
    for (uint32_t i = 0; i < 1000000; i++);
  }
  return 0;
}