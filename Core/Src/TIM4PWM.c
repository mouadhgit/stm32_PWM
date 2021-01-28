/**
  ******************************************************************************
 * @file TIM4PWM.c
 * @brief TIM4PWM 
 *
 * @author Mouadh Dahech
 * @date January , 2021
 *
  ******************************************************************************
*/ 

#include "TIM4PWM.h"

void PWM_Config()
{
  //1. active the clock 
  RCC->APB1ENR |= RCC_APB1ENR_TIM4EN ;
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

  //2. GPIOD PIN_13 Alternate function 
  GPIOD->MODER = 0 ;
  GPIOD->MODER |= (1<<25);

  //3.AF TIM8
  GPIOD->AFR[1] = 0x00020000;    

  // Enable channel 1 compare register
  TIM4->CCER |= (1<<0);
  TIM4->CR1  |= TIM_CR1_ARPE;

  //4. PWM Mode 1 
  TIM4->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 |  TIM_CCMR1_OC1PE;

  // 1khz frq 
  TIM4->PSC  = 320;
  TIM4->ARR  = 1000;

  //duty cycle: 0--1000; 
  TIM4->CCR1 = 0;   // 0 degree
  
  TIM4->EGR |= TIM_EGR_UG;
  TIM4->CR1 |= TIM_CR1_CEN;


}

/**
 ********************************Function To Control Servo Motor angel 0--180 degree*********************** 
 *           
 *  Frequancy = 50 HZ  ==> T = 20ms
 *  Using TIM4->CCR1 Ton control the duty cycle (20 ==> 0 degree && 200 ==> 180 degree)
 *                            
 */
void Servo(unsigned int deg)
{
   unsigned int CCR1_VAL;

  if(deg > 180)
    deg = 180;
  if(deg < 0)
    deg = 0;  
 
  CCR1_VAL = (200*deg)/180;

  if(CCR1_VAL < 20)
    CCR1_VAL = 20;
  if (CCR1_VAL > 200)
    CCR1_VAL = 200;
  if (CCR1_VAL == 100)
    CCR1_VAL = 70;

  TIM4->CCR1 = CCR1_VAL;

  return 0;
}   