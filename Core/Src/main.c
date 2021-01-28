/**
  ******************************************************************************
 * @file main.c
 * @brief main file, Blink led  for stm32f407vg using register access
 *
 * @author Mouadh Dahech
 * @date January , 2021
 *
  ******************************************************************************
*/ 
#include "main.h"

void GPIO_config(void);

void delay_ms(int ms);


int main(void){
	
  SystemClock();
  Tim6Config();
  PWM_Config();

  while(1)
  {
    TIM4->CCR1 = 100;
    msdelay(2000);
    TIM4->CCR1 = 250;
    msdelay(2000);
    TIM4->CCR1 = 500;
    msdelay(2000);
    TIM4->CCR1 = 800;
    msdelay(2000);
  }
  return 0;
}

