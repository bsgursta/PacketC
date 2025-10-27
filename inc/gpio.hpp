/* HAVE REGISTER VALUES BE VOLATILE */
//Used for reintializing peripherals
#define RCC_AHB1RSTR_OFFSET (0x10U)
#define RCC_AHB1ENR ((volatile uint32_t*) (RCC_BASE + RCC_AHB1ENR_OFFSET))