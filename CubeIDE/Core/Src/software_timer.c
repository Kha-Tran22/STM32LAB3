/*
 * software_timer.c
 *
 *  Created on: Oct 2, 2024
 *      Author: tuank
 */

#include "software_timer.h"

int timer_flag[10] = {0};
int timer_counter[10] = {0};


void setTimer(int index, int duration)
{
	timer_counter[index] = duration / TICK;
	timer_flag[index] = 0;
}

void timerRun()
{
	for (int i = 0; i < 4; i++)
	{
		if (timer_counter[i] >= 0)
		{
			timer_counter[i]--;
			if (timer_counter[i] <= 0)
			{
				timer_flag[i] = 1;
			}
		}
	}
}

