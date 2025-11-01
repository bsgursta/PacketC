//Main stack pointer initialized at the end of SRAM
#include "stdint.h"
//#include "system_stm32f7xx.h"
//#include "stm32f7xx.h"

#define __weak __attribute__((weak))

extern uint32_t _estack;
extern void __libc_init_array();
extern int main();

/* SRAM 1, includes DTCM */
#define SRAM1_START (0x20000000U)
#define SRAM1_SIZE  (496U * 1024U)
#define SRAM1_END (SRAM1_START + SRAM1_SIZE)

/* SRAM 2 */
#define SRAM2_START (0x2007C000U)
#define SRAM2_SIZE (16U * 1024U)
#define SRAM2_END (SRAM2_START + SRAM2_SIZE)

/* Initialize SP after SRAM2 */
#define STACK_POINTER_INIT_ADDRESS (SRAM2_END)

//Look at data sheet for the number of vectors
#define ISR_VECTOR_SIZE_WORDS 128

extern uint32_t _sidata;  //start of init data
extern uint32_t  _sdata;  //start of data
extern uint32_t  _edata;  //end of data
extern uint32_t  _sbss;   //start of bss
extern uint32_t  _ebss;   //end of bss
extern uint32_t  _estack; //top of stack

extern void __libc_init_array();

//void SystemInit(void) {
  
//}

/*Stuff before the main function*/
void Reset_Handler() {
  uint32_t *dataInit = &_sidata;
  uint32_t *data = &_sdata;

  /*Loop till target pointer reaches end of data*/
  while(data < &_edata) {
    *data++ = *dataInit++;
  }

  uint32_t *bss = &_sbss;
  while(bss < &_ebss) {
    *bss++ = 0;
  }

  SystemInit();
  /*Intialize all c++ objects */
  __libc_init_array();
  main();

  //catch returning from main
  while(1);
}

/*Catch INT calls that are not implemented*/
void Default_Handler(void) {
  while(1);
}

void HardFault_Handler(void) {
  while(1);
  //MAYBE IMPLEMENT RECOVEREY
}

/*Weak definitions of interrupt handlers*/
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

/* External Interrupts */
void WWDG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*DMA1 Stream 1*/
void DMA1_Stream2_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*DMA1 Stream 2*/
void DMA1_Stream3_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*DMA1 Stream 3*/
void DMA1_Stream4_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*DMA1 Stream 4*/
void DMA1_Stream5_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*DMA1 Stream 5*/
void DMA1_Stream6_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*DMA1 Stream 6*/
void ADC_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*ADC1, ADC2 and ADC3s*/
void CAN1_TX_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*CAN1 TX*/
void CAN1_RX0_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*CAN1 RX0*/
void CAN1_RX1_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*CAN1 RX1*/
void CAN1_SCE_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*CAN1 SCE*/
void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*External Line[9:5]s*/
void TIM1_BRK_TIM9_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM1 Break and TIM9*/
void TIM1_UP_TIM10_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM1 Update and TIM10*/
void TIM1_TRG_COM_TIM11_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM1 Trigger and Commutation and TIM11*/
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM1 Capture Compare*/
void TIM2_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM2*/
void TIM3_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM3*/
void TIM4_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM4*/
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*I2C1 Event*/
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*I2C1 Error*/
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*I2C2 Event*/
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*I2C2 Error*/
void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*SPI1*/
void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*SPI2*/
void USART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*USART1*/
void USART2_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*USART2*/
void USART3_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*USART3*/
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*External Line[15:10]s*/
void RTC_Alarm_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*RTC Alarm (A and B) through EXTI Line*/
void OTG_FS_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*USB OTG FS Wakeup through EXTI line*/
void TIM8_BRK_TIM12_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM8 Break and TIM12*/
void TIM8_UP_TIM13_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM8 Update and TIM13*/
void TIM8_TRG_COM_TIM14_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM8 Trigger and Commutation and TIM14*/
void TIM8_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*TIM8 Capture Compare*/
void DMA1_Stream7_IRQHandler(void) __attribute__((weak, alias("Default_Handler"))); /*DMA1 Stream7*/
void FMC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SDMMC1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ETH_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ETH_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN2_TX_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN2_RX0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN2_RX1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN2_SCE_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DCMI_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RNG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART8_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SAI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LTDC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LTDC_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2D_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SAI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void QUADSPI_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LPTIM1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CEC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C4_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C4_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPDIF_RX_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SDMMC2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN3_TX_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN3_RX0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN3_RX1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN3_SCE_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void JPEG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void MDIOS_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

__attribute__((section(".isr_vector")))
const void (* const g_pfnVectors[])(void) = {
  (const void (*)(void)) &_estack,
  Reset_Handler,
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0,
  0,
  0,
  0,
  SVC_Handler,
  DebugMon_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler,
  WWDG_IRQHandler,
  PVD_IRQHandler,              
  TAMP_STAMP_IRQHandler,             
  RTC_WKUP_IRQHandler,               
  FLASH_IRQHandler,                  
  RCC_IRQHandler,                    
  EXTI0_IRQHandler,                  
  EXTI1_IRQHandler,                  
  EXTI2_IRQHandler,                  
  EXTI3_IRQHandler,                  
  EXTI4_IRQHandler,                  
  DMA1_Stream0_IRQHandler,          
  DMA1_Stream1_IRQHandler,          
  DMA1_Stream2_IRQHandler,          
  DMA1_Stream3_IRQHandler,        
  DMA1_Stream4_IRQHandler,   
  DMA1_Stream5_IRQHandler,  
  DMA1_Stream6_IRQHandler,       
  ADC_IRQHandler,                
  CAN1_TX_IRQHandler,           
  CAN1_RX0_IRQHandler,    
  CAN1_SCE_IRQHandler,     
  EXTI9_5_IRQHandler,            
  TIM1_BRK_TIM9_IRQHandler,      
  TIM1_UP_TIM10_IRQHandler,          
  TIM1_TRG_COM_TIM11_IRQHandler,  
  TIM1_CC_IRQHandler,              
  TIM2_IRQHandler,           
  TIM3_IRQHandler,      
  TIM4_IRQHandler,         
  I2C1_EV_IRQHandler,          
  I2C1_ER_IRQHandler,             
  I2C2_EV_IRQHandler,           
  I2C2_ER_IRQHandler,          
  SPI1_IRQHandler,                  
  SPI2_IRQHandler,            
  USART1_IRQHandler,           
  USART2_IRQHandler,                
  USART3_IRQHandler,             
  EXTI15_10_IRQHandler,           
  RTC_Alarm_IRQHandler,             
  OTG_FS_WKUP_IRQHandler,         
  TIM8_BRK_TIM12_IRQHandler,     
  TIM8_UP_TIM13_IRQHandler,         
  TIM8_TRG_COM_TIM14_IRQHandler,     
  TIM8_CC_IRQHandler,              
  DMA1_Stream7_IRQHandler,           
  FMC_IRQHandler,                  
  SDMMC1_IRQHandler,                 
  TIM5_IRQHandler,                   
  SPI3_IRQHandler,                   
  UART4_IRQHandler,                  
  UART5_IRQHandler,                 
  TIM6_DAC_IRQHandler,               
  TIM7_IRQHandler,                   
  DMA2_Stream0_IRQHandler,           
  DMA2_Stream1_IRQHandler,           
  DMA2_Stream2_IRQHandler,           
  DMA2_Stream3_IRQHandler,      
  DMA2_Stream4_IRQHandler,          
  ETH_IRQHandler,                
  ETH_WKUP_IRQHandler,              
  CAN2_TX_IRQHandler,              
  CAN2_RX0_IRQHandler,            
  CAN2_RX1_IRQHandler,             
  CAN2_SCE_IRQHandler,          
  OTG_FS_IRQHandler,                
  DMA2_Stream5_IRQHandler,        
  DMA2_Stream6_IRQHandler,           
  DMA2_Stream7_IRQHandler,          
  USART6_IRQHandler,                
  I2C3_EV_IRQHandler,                
  I2C3_ER_IRQHandler,               
  OTG_HS_EP1_OUT_IRQHandler,         
  OTG_HS_EP1_IN_IRQHandler,          
  OTG_HS_WKUP_IRQHandler,            
  OTG_HS_IRQHandler,                 
  DCMI_IRQHandler,                   
  0,                                /* CRYP*/
  RNG_IRQHandler,                   
  FPU_IRQHandler,               
  UART7_IRQHandler,                
  UART8_IRQHandler,              
  SPI4_IRQHandler,               
  SPI5_IRQHandler,           
  SPI6_IRQHandler,                 
  SAI1_IRQHandler,                
  LTDC_IRQHandler,               
  LTDC_ER_IRQHandler,             
  DMA2D_IRQHandler,            
  SAI2_IRQHandler,                  
  QUADSPI_IRQHandler,             
  LPTIM1_IRQHandler,               
  CEC_IRQHandler,               
  I2C4_EV_IRQHandler,        
  I2C4_ER_IRQHandler,           
  SPDIF_RX_IRQHandler,            
  0,                           /* DSI host*/ 
  DFSDM1_FLT0_IRQHandler,           
  DFSDM1_FLT1_IRQHandler,           
  DFSDM1_FLT2_IRQHandler,        
  DFSDM1_FLT3_IRQHandler,           
  SDMMC2_IRQHandler,               
  CAN3_TX_IRQHandler,               
  CAN3_RX0_IRQHandler,              
  CAN3_RX1_IRQHandler,               
  CAN3_SCE_IRQHandler,              
  JPEG_IRQHandler,               
  MDIOS_IRQHandler,                 
};