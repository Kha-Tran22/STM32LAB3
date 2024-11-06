/*
 * 7seg.h
 *
 *  Created on: Nov 1, 2024
 *      Author: tuank
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "global.h"

void display_number_horizontal(int number);
void display_number_vertical(int number);

void enable_horizontal(int index);
void enable_vertical(int index);

void update_7seg_horizontal(int index);
void update_7seg_vertical(int index);

void clear_all_7seg();

void update_buffer_horizontal();
void update_buffer_vertical();

#endif /* INC_LED7_SEGMENT_H_ */
