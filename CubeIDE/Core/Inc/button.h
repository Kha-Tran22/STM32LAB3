/*
 * button.h
 *
 *  Created on: Oct 4, 2024
 *      Author: tuank
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKeyInput();
int isButtonPressed();

#endif /* INC_BUTTON_H_ */
