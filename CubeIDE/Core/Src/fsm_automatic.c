/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: tuank
 */

#include "fsm_automatic.h"

void fsm_automatic_run()
{
	switch (status_horizontal_traffic)
	{
	case INIT:
		status_horizontal_traffic = AUTO_RED;
		setTimer(0, red_duration * 1000); // Thoi gian chuyen trang thai led giao thong

		counter_horizontal = red_duration - 1;
		update_buffer_horizontal();
		setTimer(1, 500);  // Quet led
		setTimer(2, 1000); // giam counter led 7 doan
		timer_flag[1] = 1;
		break;
	case AUTO_RED:
		red_on_horizontal();

		if (timer_flag[1] == 1)
		{
			update_7seg_horizontal(index_buffer_horizontal++);
			if (index_buffer_horizontal >= 2)
				index_buffer_horizontal = 0;
			setTimer(1, 500);
		}

		if (timer_flag[0] == 1)
		{
			setTimer(0, green_duration * 1000);
			status_horizontal_traffic = AUTO_GREEN;

			counter_horizontal = green_duration;
			update_buffer_horizontal();
		}

		if (timer_flag[2] == 1)
		{
			counter_horizontal--;
			update_buffer_horizontal();
			setTimer(2, 1000);
		}

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = INIT_MODE;
			status_vertical_traffic = INIT_MODE;
		}

		break;
	case AUTO_GREEN:
		green_on_horizontal();

		if (timer_flag[1] == 1)
		{
			update_7seg_horizontal(index_buffer_horizontal++);
			if (index_buffer_horizontal >= 2)
				index_buffer_horizontal = 0;
			setTimer(1, 500);
		}

		if (timer_flag[0] == 1)
		{
			setTimer(0, yellow_duration * 1000);
			status_horizontal_traffic = AUTO_YELLOW;

			counter_horizontal = yellow_duration;
			update_buffer_horizontal();
		}

		if (timer_flag[2] == 1)
		{
			counter_horizontal--;
			update_buffer_horizontal();
			setTimer(2, 1000);
		}

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = INIT_MODE;
			status_vertical_traffic = INIT_MODE;
		}
		break;
	case AUTO_YELLOW:
		yellow_on_horizontal();

		if (timer_flag[1] == 1)
		{
			update_7seg_horizontal(index_buffer_horizontal++);
			if (index_buffer_horizontal >= 2)
				index_buffer_horizontal = 0;
			setTimer(1, 500);
		}

		if (timer_flag[0] == 1)
		{
			setTimer(0, red_duration * 1000);
			status_horizontal_traffic = AUTO_RED;

			counter_horizontal = red_duration;
			update_buffer_horizontal();
		}

		if (timer_flag[2] == 1)
		{
			counter_horizontal--;
			update_buffer_horizontal();
			setTimer(2, 1000);
		}

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = INIT_MODE;
			status_vertical_traffic = INIT_MODE;
		}
		break;
	default:
		break;
	}

	switch (status_vertical_traffic)
	{
	case INIT:
		status_vertical_traffic = AUTO_GREEN;
		setTimer(3, green_duration * 1000);

		counter_vertical = green_duration - 1;
		update_buffer_vertical();
		setTimer(4, 500);  // Quet led
		setTimer(5, 1000); // giam counter led 7 doan
		timer_flag[4] = 1;
		break;
	case AUTO_RED:
		red_on_vertical();
		if (timer_flag[4] == 1)
		{
			update_7seg_vertical(index_buffer_vertical++);
			if (index_buffer_vertical >= 2)
				index_buffer_vertical = 0;
			setTimer(4, 500);
		}

		if (timer_flag[3] == 1)
		{
			setTimer(3, green_duration * 1000);
			status_vertical_traffic = AUTO_GREEN;

			counter_vertical = green_duration;
			update_buffer_vertical();
		}

		if (timer_flag[5] == 1)
		{
			counter_vertical--;
			update_buffer_vertical();
			setTimer(5, 1000);
		}

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = INIT_MODE;
			status_vertical_traffic = INIT_MODE;
		}

		break;
	case AUTO_GREEN:
		green_on_vertical();
		if (timer_flag[4] == 1)
		{
			update_7seg_vertical(index_buffer_vertical++);
			if (index_buffer_vertical >= 2)
				index_buffer_vertical = 0;
			setTimer(4, 500);
		}

		if (timer_flag[3] == 1)
		{
			setTimer(3, yellow_duration * 1000);
			status_vertical_traffic = AUTO_YELLOW;

			counter_vertical = yellow_duration;
			update_buffer_vertical();
		}

		if (timer_flag[5] == 1)
		{
			counter_vertical--;
			update_buffer_vertical();
			setTimer(5, 1000);
		}

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = INIT_MODE;
			status_vertical_traffic = INIT_MODE;
		}
		break;
	case AUTO_YELLOW:
		yellow_on_vertical();
		if (timer_flag[4] == 1)
		{
			update_7seg_vertical(index_buffer_vertical++);
			if (index_buffer_vertical >= 2)
				index_buffer_vertical = 0;
			setTimer(4, 500);
		}

		if (timer_flag[3] == 1)
		{
			setTimer(3, red_duration * 1000);
			status_vertical_traffic = AUTO_RED;

			counter_vertical = red_duration;
			update_buffer_vertical();
		}

		if (timer_flag[5] == 1)
		{
			counter_vertical--;
			update_buffer_vertical();
			setTimer(5, 1000);
		}

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = INIT_MODE;
			status_vertical_traffic = INIT_MODE;
		}
		break;
	default:
		break;
	}
}
