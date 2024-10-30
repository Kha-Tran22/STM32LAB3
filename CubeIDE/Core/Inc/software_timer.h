/*
 * software_timer.h
 *
 *  Created on: Oct 2, 2024
 *      Author: tuank
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TICK 10
extern int timer_flag[10];

void setTimer(int index, int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
