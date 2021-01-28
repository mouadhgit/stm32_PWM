
/**
  ******************************************************************************
 * @file TIM_Config.h
 * @brief timer Configuration for stm32f407vg 
 *
 * @author Mouadh Dahech
 * @date January , 2021
 *
  ******************************************************************************
*/ 

#include "TIM_Config.h"
void Tim6Config()
{
 //1. Enable the clock for TIM6
  RCC->APB1ENR |= (1<<4);

 //2. Set the prescaler to 15 to run the counter with 1MHZ freq so 1 us for each tick
  TIM6->PSC = 15;

 //3. Max value 
  TIM6->ARR = 0xffff;

 //4. Active counter up 
  TIM6->CR1 |= (1<<0);
  while(!(TIM6->SR & (1<<0)));
}

void usdelay(uint16_t us)
{
 TIM6->CNT = 0;
 while(TIM6->CNT < us);
}

void msdelay(uint16_t ms)
{
  for(uint16_t i = 0; i<ms; i++)
  {
    usdelay(1000);
  }  
}