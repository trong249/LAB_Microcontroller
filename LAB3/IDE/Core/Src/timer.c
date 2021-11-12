/*
 * timer.c
 *
 *  Created on: Oct 1, 2021
 *      Author: win 10
 */
#include"main.h"
#include "input_reading.h"
#ifndef SRC_TIMER_C_
#define SRC_TIMER_C_
#define TIMER_CYCLE 	10
///////////////////////////////////////////////////////////////////////////////////////////
static int timer_counter0;
static int timer_flag0 = 0;
void setTimer0( int duration ){
	timer_counter0 = duration / TIMER_CYCLE ;
	timer_flag0 = 0;
}
void timer_run0(){
	if( timer_counter0 > 0){
		timer_counter0 --;
		if( timer_counter0 == 0)	timer_flag0 = 1;
	}
}
int flag_timer0(){
	if (timer_flag0==1)
		return 1;
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
static int timer_counter1;
static int timer_flag1 = 0;
void setTimer1( int duration ){
	timer_counter1 = duration / TIMER_CYCLE ;
	timer_flag1 = 0;
}
void timer_run1(){
	if( timer_counter1 > 0){
		timer_counter1 --;
		if( timer_counter1 == 0)	timer_flag1 = 1;
	}
}
int flag_timer1(){
	if (timer_flag1==1)
		return 1;
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
static int timer_counter2;
static int timer_flag2 = 0;
void setTimer2( int duration ){
	timer_counter2 = duration / TIMER_CYCLE ;
	timer_flag2 = 0;
}
void timer_run2(){
	if( timer_counter2 > 0){
		timer_counter2 --;
		if( timer_counter2 == 0)timer_flag2 = 1;
	}
}
int flag_timer2(){
	if (timer_flag2==1)
		return 1;
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
static int timer_counter3;
static int timer_flag3 = 0;
void setTimer3( int duration ){
	timer_counter3 = duration / TIMER_CYCLE ;
	timer_flag3 = 0;
}
void timer_run3(){
	if( timer_counter3 > 0){
		timer_counter3 --;
		if( timer_counter3 == 0)  timer_flag3 = 1;
	}
}
int flag_timer3(){
	if (timer_flag3==1) return 1;
	return -1;
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
static int timer_counter_7SEG;
static int timer_flag_7SEG = 0;
void setTimer_7SEG( int duration ){
	timer_counter_7SEG = duration / TIMER_CYCLE ;
	timer_flag_7SEG = 0;
}
void timer_run_7SEG(){
	if( timer_counter_7SEG > 0){
		timer_counter_7SEG --;
		if( timer_counter_7SEG == 49) timer_flag_7SEG = 3;
		if( timer_counter_7SEG == 25) timer_flag_7SEG = 2;
		if( timer_counter_7SEG == 0)  timer_flag_7SEG = 1;
	}
}
int flag_timer_7SEG(){
	if (timer_flag_7SEG==3) return 3;
	if (timer_flag_7SEG==2) return 2;
	if (timer_flag_7SEG==1) return 1;
	return -1;
}
///////////////////////////////////////////////////////////////////////////////////////////

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ){
	timer_run0();
	timer_run1();
	timer_run2();
	timer_run3();
	timer_run_7SEG();
	if (htim->Instance==TIM2){
		button_reading();
	}
}
#endif /* SRC_TIMER_C_ */
