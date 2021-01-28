/**
  ******************************************************************************
 * @file RCC_config.c
 * @brief source file for clock configuration stm32f407VG
 *
 * @author Mouadh Dahech
 * @date January , 2021
 *
  ******************************************************************************
*/ 
#include "RCC_Config.h"
/*************>>>>>>> STEPS FOLLOWED <<<<<<<<************
 * 
	1. ENABLE HSI and wait for the HSI to become Ready
	2. Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
	3. Configure the FLASH PREFETCH and the LATENCY Related Settings
	4. Configure the PRESCALARS HCLK, PCLK1, PCLK2
	5. Configure the MAIN PLL
	6. Enable the PLL and wait for it to become ready
	7. Select the Clock Source and wait for it to be set
	
	********************************************************/
void SystemClock(void)
{

//1. ENABLE HSI and wait for the HSI to become Ready	
RCC->CR |= RCC_CR_HSION;
while(!(RCC->CR &= RCC_CR_HSIRDY));	

//2. Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
RCC->APB1ENR |= RCC_APB1ENR_PWREN;
PWR->CR |= PWR_CR_VOS;	
	
//3. Configure the FLASH PREFETCH and the LATENCY Related Settings	
FLASH->ACR |= FLASH_ACR_ICEN | FLASH_ACR_DCEN |FLASH_ACR_PRFTEN |FLASH_ACR_LATENCY_0WS;	
	
//4. Configure the PRESCALARS HCLK, PCLK1, PCLK2	
RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;
RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;

//5. Select the Clock Source and wait for it to be set	
RCC->CFGR |= RCC_CFGR_SWS_HSI;
while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);	
}