/*
 * processing.c
 *
 *  Created on: Oct 6, 2021
 *      Author: win 10
 */

#include "processing.h"
#define timeRespone 	100

enum fsmState{STATE_1,STATE_2,STATE_3,STATE_4} fsmState;


void fsm_for_processing(){

	static int red=5,green=3,yellow=2,mod=2,counter_to_set=1;
	static enum fsmState Main_State=STATE_2;
	switch(Main_State){

	case STATE_1:
		display_TrafficLight(red, green, yellow); //hien thi den bth

		//display_1st_2SEG();  đã gọi trong hàm display_TrafficLight(red, green, yellow)
		//display_2nd_2SEG();

		if (flag_timer2()){
			if (is_button_pressed(0)||is_button_pressed_1s(0)){
				counter_to_set=1;
				mod++;
				Main_State=STATE_2;
			}
			setTimer2(timeRespone);
		}
	break;

	case STATE_2:
		display_1st_2SEG(mod); //State for red
		display_TrafficLight(-1, 0, 0);// chop nhay led
		display_2nd_2SEG(counter_to_set); // hien thi thoi gian muon set cho den tuong ung
		if (flag_timer2()){
			if (is_button_pressed(0)||is_button_pressed_1s(0)){
				counter_to_set=1;
				mod++;
				Main_State=STATE_3;
			}
			if (is_button_pressed(1) ){
				counter_to_set++;
				if (counter_to_set>99) counter_to_set=0;
			}
			if (is_button_pressed(2)){
				red=counter_to_set;
			}
			setTimer2(timeRespone);

		}
	break;

	case STATE_3: // State for yellow
		display_1st_2SEG(mod);
		display_TrafficLight(0, 0, -1);// chop nhay led
		display_2nd_2SEG(counter_to_set); // hien thi thoi gian muon set cho den tuong ung
		if (flag_timer2()){
			if (is_button_pressed(0)||is_button_pressed_1s(0)){
				counter_to_set=1;
				mod++;
				Main_State=STATE_4;
			}
			if (is_button_pressed(1)){
				counter_to_set++;
			}
			if (is_button_pressed(2)){
				yellow=counter_to_set;
			}
			setTimer2(timeRespone);

		}
	break;
	case STATE_4:	//State for green
		display_1st_2SEG(mod);
		display_TrafficLight(0, -1, 0);// chop nhay led
		display_2nd_2SEG(counter_to_set); // hien thi thoi gian muon set cho den tuong ung
		if (flag_timer2()){
			if (is_button_pressed(0)||is_button_pressed_1s(0)){
				counter_to_set=1;
				mod=1;
				Main_State=STATE_1;
			}
			if (is_button_pressed(1)){
				counter_to_set++;
			}
			if (is_button_pressed(2)){
				green=counter_to_set;
			}
			setTimer2(timeRespone);

		}
	break;

	}
}
