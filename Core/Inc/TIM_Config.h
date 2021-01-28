/**
  ******************************************************************************
 * @file TIM_Config.h
 * @brief TIM_Config header file
 *
 * @author Mouadh Dahech
 * @date January , 2021
 *
  ******************************************************************************
*/ 

#ifndef __TIM_Config__
#define __TIM_Config__

#include "stm32f4xx.h"

void Tim6Config();
void usdelay(uint16_t us);
void msdelay(uint16_t ms);

#endif