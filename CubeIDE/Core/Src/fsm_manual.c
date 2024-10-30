/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: tuank
 */

#include "fsm_manual.h"

void fsm_manual_run()
{
	switch (status)
	{
		case MAN_RED:
			RED_ON();

			if (isButtonPressed() == 1)
			{
				status = MAN_GREEN;
				setTimer(0, 10000);
			}

			if(timer_flag[0] == 1)
			{
				status = AUTO_RED;
				setTimer(0, 5000);
			}
			break;
		case MAN_GREEN:
			GREEN_ON();

			if (isButtonPressed() == 1)
			{
				status = MAN_YELLOW;
				setTimer(0, 10000);
			}

			if (timer_flag[0] == 1)
			{
				status = AUTO_GREEN;
				setTimer(0, 3000);
			}
			break;
		case MAN_YELLOW:
			YELLOW_ON();

			if (isButtonPressed() == 1)
			{
				status = MAN_RED;
				setTimer(0, 10000);
			}

			if (timer_flag[0] == 1)
			{
				status = AUTO_YELLOW;
				setTimer(0, 2000);
			}
			break;
		default:
			break;
	}
}
