/*
 * button.c
 *
 *  Created on: Oct 4, 2024
 *      Author: tuank
 */

#include "button.h"


int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;
int TimerForPressKey = 200;

int button1_flag = 0;

int isButtonPressed()
{
	if (button1_flag == 1)
	{
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subProcess()
{
	button1_flag = 1;
}

void getKeyInput()
{
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2))
	{
		if (KeyReg3 != KeyReg2)
		{
			KeyReg3 = KeyReg2;
			if (KeyReg2 == PRESSED_STATE)
			{
				//TODO
				subProcess();
				TimerForPressKey = 200;
			}
		}
		else
		{
			TimerForPressKey--;
			if (TimerForPressKey == 0)
			{
//				if (KeyReg2 == PRESSED_STATE)
//				{
//					//TODO
//					subProcess();
//				}
//				TimerForPressKey = 200;
				KeyReg3 = NORMAL_STATE;
			}

		}
	}
}


