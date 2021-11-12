/*
 * display.c
 *
 *  Created on: Oct 6, 2021
 *      Author: win 10
 */
#include "display.h"
#include "main.h"
#include "timer.h"
#include "SEG7.h"



enum LightState{RED,YELLOW,GREEN};
//Xử lí 2 led 7 doan thứ nhất
void display_1st_2SEG(int num){
	if(num==-1){
		_7SEG_D(-1);
	}
	if (num>=1 && num<=9){
		int flag =flag_timer_7SEG();
		if( flag == 3){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
			_7SEG_D(0);
		}
		if( flag == 2) {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
			_7SEG_D(num);
		}
		if( flag == 1){
			setTimer_7SEG(500) ;
		}
	}
	if ( num>9 ){
		int flag =flag_timer_7SEG();
		int chuc=num/10;
		int donvi=num%10;
		if( flag == 3){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
			_7SEG_D(chuc);
		}
		if( flag == 2) {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
			_7SEG_D(donvi);
		}
		if( flag == 1){
			setTimer_7SEG(500) ;
		}
	}
}
//Xử lí 2 led 7 đoạn thứ 2
void display_2nd_2SEG(int num){
	if(num==-1){
			_7SEG_N(-1);
		}
		if (num>=1 && num<=9){
			int flag =flag_timer_7SEG();
			if( flag == 3){
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
				_7SEG_N(0);
			}
			if( flag == 2) {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
				_7SEG_N(num);
			}
			if( flag == 1){
				setTimer_7SEG(500) ;
			}
		}
		if ( num>9 ){
			int flag =flag_timer_7SEG();
			int chuc=num/10;
			int donvi=num%10;
			if( flag == 3){
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
				_7SEG_N(chuc);
			}
			if( flag == 2) {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
				_7SEG_N(donvi);
			}
			if( flag == 1){
				setTimer_7SEG(500) ;
			}
		}

}

//Xử lí hiện thị đèn giao thông ( RED GREEN YELLOW )
void display_TrafficLight(int red, int green, int yellow){
//MOD=2 RED
	if (red==-1&&green==0&&yellow==0){
		int flag =flag_timer3();
		if( flag == 1){
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2|GPIO_PIN_5);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4, 1);
			setTimer3(500) ;
		}
	}
//	MOD = 3 YELLOW
	if (yellow==-1&&green==0&&red==0){
		int flag =flag_timer3();
		if( flag == 1){
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1|GPIO_PIN_4);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_5, 1);
			setTimer3(500) ;
		}
	}
//	MOD = 4 GREEN
	if(green==-1&&red==0&&yellow==0){
		int flag =flag_timer3();
		if( flag == 1){
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0|GPIO_PIN_3);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4|GPIO_PIN_5, 1);
			setTimer3(500) ;
		}
	}

	if ((green+yellow)==red){
		static int time_D=0;
		static int time_N=0;
		static enum LightState state_D=RED;
		static enum LightState state_N=GREEN;
		//	Hiển thị đèn theo chiều doc/////////////////////////////////////////////////////////////
		switch(state_D){
		case RED:  	// RED=On ; YELLOW=Off ; GREEN=Off
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5, 0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3|GPIO_PIN_4, 1);
			display_1st_2SEG(red-time_D); // hien thi thoi gian tuong ung
			if(flag_timer0()==1){
				if (++time_D==red){
					state_D=GREEN;
					time_D=0;
				}
				setTimer0(1000);
			}
		break;
		case GREEN:  	// RED=Off ; YELLOW=Off ; GREEN=On
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3, 0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4|GPIO_PIN_5, 1);
			display_1st_2SEG(green-time_D); // hien thi thoi gian tuong ung
			if(flag_timer0()==1){
				if (++time_D==green){
					state_D=YELLOW;
					time_D=0;
				}
				setTimer0(1000);
			}
		break;
		case YELLOW:  	// RED=On ; YELLOW=Off ; GREEN=Off
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, 0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3|GPIO_PIN_5, 1);
			display_1st_2SEG(yellow-time_D); // hien thi thoi gian tuong ung
			if(flag_timer0()==1){
				if (++time_D==yellow){
					state_D=RED;
					time_D=0;
				}
				setTimer0(1000);
			}
		break;
		}
		//	Hiển thị đèn theo chieu ngang/////////////////////////////////////////////////////////
		switch(state_N){
		case RED:  	// RED=On ; YELLOW=Off ; GREEN=Off
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2, 0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0|GPIO_PIN_1, 1);
			display_2nd_2SEG(red-time_N); // hien thi thoi gian tuong ung
			if(flag_timer1()==1){
				if (++time_N==red){
					state_N=GREEN;
					time_N=0;
				}
				setTimer1(1000);
			}
		break;
		case GREEN:  	// RED=Off ; YELLOW=Off ; GREEN=On
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0, 0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1|GPIO_PIN_2, 1);
			display_2nd_2SEG(green-time_N); // hien thi thoi gian tuong ung
			if(flag_timer1()==1){
				if (++time_N==green){
					state_N=YELLOW;
					time_N=0;
				}
				setTimer1(1000);
			}
		break;
		case YELLOW:  	// RED=On ; YELLOW=Off ; GREEN=Off
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1, 0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0|GPIO_PIN_2, 1);
			display_2nd_2SEG(yellow-time_N); // hien thi thoi gian tuong ung
			if(flag_timer1()==1){
				if (++time_N==yellow){
					state_N=RED;
					time_N=0;
				}
				setTimer1(1000);
			}
		break;
		}
	}
//	Nếu 3 thời gian xảy ra đụng độ với nhau////////////////////////////////////////////////////////
	else if (red!=-1&&green!=-1&&yellow!=-1){
		int flag =flag_timer_7SEG();
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_0,1);

			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
			_7SEG_D(8);
			_7SEG_N(8);

	}
}


