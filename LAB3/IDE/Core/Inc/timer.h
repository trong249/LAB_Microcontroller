/*
 * timer.h
 *
 *  Created on: Oct 1, 2021
 *      Author: win 10
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "input_reading.h"

//Su dung timer 0 cho đèn theo chiều dọc
void setTimer0( int duration );
void timer_run0();
int flag_timer0();

//Su dung timer 1 cho đèn theo chiều ngang
void setTimer1( int duration );
void timer_run1();
int flag_timer1();

//Su dụng timer 2 để xử lí nút nhấn
void setTimer2( int duration );
void timer_run2();
int flag_timer2();

//Su dung timer 3 cho chop nhay led
void setTimer3( int duration );
void timer_run3();
int flag_timer3();

void setTimer_7SEG( int duration );
void timer_run_7SEG();
int flag_timer_7SEG();

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim );
#endif /* INC_TIMER_H_ */
