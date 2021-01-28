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
    // servo motor test
    
    Servo(0);
    msdelay(1000);

    Servo(90);
    msdelay(1000);       

    Servo(180);
    msdelay(1000);
  }
  return 0;
}

