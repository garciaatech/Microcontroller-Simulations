/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/12/2019 22:34:13 PST
*/

#include "rims.h"

/*Define user variables and functions for this state machine here.*/
//HW4
//Anaisy Garcia
//PID: 5734454
//EEL 4730

unsigned char k, i;
unsigned char SM1_Clk;
void TimerISR() {
   SM1_Clk = 1;
}
 
enum SM1_States { SM1_Initial, SM1_AllBlink, SM1_Shift1, SM1_Shift2 } SM1_State;
 
TickFct_State_machine_1() {
   switch(SM1_State) { 
  	case -1:
     	SM1_State = SM1_Initial;
     	break;
     	case SM1_Initial:
     	if (!A1&&A0) {
        	SM1_State = SM1_AllBlink;
     	}
     	else if (A1&&A0) {
        	SM1_State = SM1_Shift1;
     	}
     	break;
  	case SM1_AllBlink:
     	if (!A0) {
            SM1_State = SM1_Initial;
     	}
     	else if (k==50) {
        	SM1_State = SM1_AllBlink;
        	k=0;
     	}
     	else if (A1&&A0) {
        	SM1_State = SM1_Shift1;
        	i=0;
     	}
     	break;
  	case SM1_Shift1:
     	if (!A0) {
        	SM1_State = SM1_Initial;
     	}
     	else if (i==7) {
        	SM1_State = SM1_Shift2;
        	i=0;
     	}
     	else if (!A1&&A0) {
        	SM1_State = SM1_AllBlink;
        	k=0;
     	}
     	break;
  	case SM1_Shift2:
     	if (!A1&&A0) {
        	SM1_State = SM1_AllBlink;
        	k=0;
     	}
     	else if (i==7) {
        	SM1_State = SM1_Shift1;
        	i=0;
     	}
     	else if (!A0) {
        	SM1_State = SM1_Initial;
     	}
     	break;
  	default:
     	SM1_State = SM1_Initial;
   } 
 
   switch(SM1_State) { 
  	case SM1_Initial:
     	B0=0;
     	k=0;
     	i=0;
     	break;
  	case SM1_AllBlink:
         B=(B|~(0x00))*(k%2);
     	k++;
     	break;
  	case SM1_Shift1:
         B=0x80>>i;
     	i++;
     	break;
  	case SM1_Shift2:
         B=0x01<<i;
     	i++;
     	break;
  	default: 
  	break;
   }
 
}
 
int main() {
 
   const unsigned int periodState_machine_1 = 1000; 
   TimerSet(periodState_machine_1);
   TimerOn();
  
   SM1_State = -1; // Initial state
   B = 0; 
 
   while(1) {
      TickFct_State_machine_1();
  	while(!SM1_Clk);
  	SM1_Clk = 0;
   } 
}
