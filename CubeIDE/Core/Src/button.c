/*
 * button.c
 *
 *  Created on: Oct 4, 2024
 *      Author: tuank
 */

#include "button.h"
#include "main.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

void getKeyInput()
{
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
}
