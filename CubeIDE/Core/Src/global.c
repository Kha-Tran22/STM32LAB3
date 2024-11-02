/*
 * global.c
 *
 *  Created on: Oct 30, 2024
 *      Author: tuank
 */

#include "global.h"


int status_horizontal_traffic = INIT;
int status_vertical_traffic = INIT;

int red_duration = 5;
int	green_duration = 3;
int	yellow_duration = 2;

int red_duration_tmp = 0;
int	green_duration_tmp = 0;
int	yellow_duration_tmp = 0;

int index_buffer_horizontal = 0;
int index_buffer_vertical = 0;

int led_buffer_horizontal[2] = {0,5};
int led_buffer_vertical[2] = {0,3};

int counter_horizontal = 5;
int counter_vertical = 3;

