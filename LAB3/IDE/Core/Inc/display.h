/*
 * display.h
 *
 *  Created on: Oct 6, 2021
 *      Author: win 10
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

void display_1st_2SEG(int num); // hien thi 2 led 7 doan thu 1 voi gia tri dua vao tuong ung
void display_2nd_2SEG(int num); // hien thi 2 led 7 doan thu 2 voi gia tri dua vao tuong ung


/* hien thi den giao led theo tung thoi gian va goi lai 2 ham tren
 neu thoi gian truyen vao la k hop li( red!=yellow+green )
 den se tat/ cac led 7 doan se hien thi so 8 */
void display_TrafficLight(int red, int green, int yellow);


#endif /* INC_DISPLAY_H_ */
