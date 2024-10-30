/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: tuank
 */

#include "fsm_automatic.h"

void fsm_automatic_run()
{
	switch (status)
	{
		case INIT:
			INIT_ON();
			status = AUTO_RED;
			setTimer(0, 5000);
			break;
		case AUTO_RED:
			RED_ON();

			if (timer_flag[0] == 1)
			{
				setTimer(0, 3000);
				status = AUTO_GREEN;
			}

			if (isButtonPressed() == 1)
			{
				status = MAN_RED;
				setTimer(0, 10000);
			}
			break;
		case AUTO_GREEN:
			GREEN_ON();
			if (timer_flag[0] == 1)
			{
				setTimer(0, 2000);
				status = AUTO_YELLOW;
			}

			if (isButtonPressed() == 1)
			{
				status = MAN_GREEN;
				setTimer(0, 10000);
			}
			break;
		case AUTO_YELLOW:
			YELLOW_ON();
			if (timer_flag[0] == 1)
			{
				setTimer(0, 5000);
				status = AUTO_RED;
			}

			if (isButtonPressed() == 1)
			{
				status = MAN_YELLOW;
				setTimer(0, 10000);
			}
			break;
		default:
			break;
	}
}
