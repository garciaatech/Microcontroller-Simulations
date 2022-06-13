/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/19/2019 22:14:39 PST
*/

#include "rims.h"

/*Define user variables and functions for this state machine here.*/
//HW6
//Anaisy Garcia
//PID: 5734454
//EEL 4730
unsigned char Cnt;
unsigned char SM1_Clk;
void TimerISR() {
   SM1_Clk = 1;
}
 
enum SM1_States { SM1_Wait, SM1_filter, SM1_Action } SM1_State;
 
TickFct_State_machine_1() {
   switch(SM1_State) { 
  	case -1:
     	SM1_State = SM1_Wait;
     	break;
     	case SM1_Wait:
     	if (A0) {
        	SM1_State = SM1_filter;
     	}
     	break;
  	case SM1_filter:
     	if (!A0) {
        	SM1_State = SM1_Wait;
     	}
     	else if (Cnt >3&&A0) {
        	SM1_State = SM1_Action;
     	}
     	break;
  	case SM1_Action:
     	if (!A0) {
        	SM1_State = SM1_Wait;
     	}
     	break;
  	default:
     	SM1_State = SM1_Wait;
   } 
 
   switch(SM1_State) {
  	case SM1_Wait:
     	B0=0;
     	Cnt=0;
     	break;
  	case SM1_filter:
     	Cnt++;
     	break;
  	case SM1_Action:
     	B0=1;
     	break;
  	default: 
  	break;
   } 
}
int main() {
 
   const unsigned int periodState_machine_1 = 50;
   TimerSet(periodState_machine_1);
   TimerOn();
  
   SM1_State = -1; 
   B = 0;
 
   while(1) {
  	TickFct_State_machine_1();
  	while(!SM1_Clk);
  	SM1_Clk = 0;
   } 
}