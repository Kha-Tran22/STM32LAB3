/*
 * traffic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: tuank
 */

#include "traffic.h"


void INIT_ON()
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
}

void RED_ON()
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
}

void GREEN_ON()
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
}

void YELLOW_ON()
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
}
