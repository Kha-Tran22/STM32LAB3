/*
 * fsm_setting.c
 *
 *  Created on: Nov 1, 2024
 *      Author: tuank
 */

#include "fsm_setting.h"

void fsm_setting_run()
{
	switch (status_horizontal_traffic)
	{
		case INIT_MODE:
			status_horizontal_traffic = MODE1;
			setTimer(0, 3000);

			break;
		case MODE1:
			if (timer_flag[0] == 1)
			{
				status_horizontal_traffic = INIT;
				status_vertical_traffic = INIT;
			}
			if (isButtonPressed(1) == 1)
			{
				status_horizontal_traffic = MODE2;
				setTimer(1, 10000);
			}
			setTimer(2, 250);

			break;
		case MODE2:
			red_duration_tmp = red_duration;
			if (timer_flag[2] == 1)
			{
				custom_red_mode();
				setTimer(2, 250);
			}
			if (isButtonPressed(1) == 1)
			{
				status_horizontal_traffic = MODE3;
				setTimer(1, 10000);
			}
			if (isButtonPressed(2) == 1)
			{
				red_duration_tmp++;
				if (red_duration_tmp > 99)
					red_duration_tmp = 0;
			}
			if (isButtonPressed(3) == 1)
			{
				red_duration = red_duration_tmp;
				status_horizontal_traffic = MODE1;
			}
			if (timer_flag[1] == 1)
			{
				status_horizontal_traffic = MODE1;
			}
			setTimer(2, 250);

			break;
		case MODE3:
			green_duration_tmp = green_duration;
			if (timer_flag[2] == 1)
			{
				custom_green_mode();
				setTimer(2, 250);
			}
			if (isButtonPressed(1) == 1)
			{
				status_horizontal_traffic = MODE4;
				setTimer(1, 10000);
			}
			if (isButtonPressed(2) == 1)
			{
				// Tang thoi gian green
				green_duration_tmp++;
				if (green_duration_tmp > 99)
					green_duration_tmp = 0;

			}
			if (isButtonPressed(3) == 1)
			{
				green_duration = green_duration_tmp;
				status_horizontal_traffic = MODE1;
			}
			if (timer_flag[1] == 1)
			{
				status_horizontal_traffic = MODE1;
			}
			setTimer(2, 250);

			break;
		case MODE4:
			yellow_duration_tmp = yellow_duration;
			if (timer_flag[2] == 1)
			{
				custom_yellow_mode();
				setTimer(2, 250);
			}
			if (isButtonPressed(1) == 1)
			{
				status_horizontal_traffic = MODE1;
				setTimer(1, 10000);
			}
			if (isButtonPressed(2) == 1)
			{
				// Tang thoi gian yellow
				yellow_duration_tmp++;
				if (yellow_duration_tmp > 99)
					yellow_duration_tmp = 0;
			}
			if (isButtonPressed(3) == 1)
			{
				yellow_duration = red_duration_tmp;
				status_horizontal_traffic = MODE1;
			}
			if (timer_flag[1] == 1)
			{
				status_horizontal_traffic = MODE1;
			}

			break;
		default:
			break;
	}
}
