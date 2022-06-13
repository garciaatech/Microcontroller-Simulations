/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/19/2019 23:6:25 PST
*/

#include "rims.h"

/*Define user variables and functions for this state machine here.*/
//HW6
//Anaisy Garcia
//PID: 5734454
//EEL 4730
unsigned char sh;
unsigned char TimerFlag = 0;
void TimerISR() {
   TimerFlag = 1;
}
enum SM1_States { SM1_Sample, SM1_HeaterOn } SM1_State;

TickFct_State_machine_1() {
  
static unsigned char samplea7a4, samplea3a0; 
   switch(SM1_State) { 
      case -1:
         SM1_State = SM1_Sample;
         break;
      case SM1_Sample:
         if (samplea7a4 < samplea3a0) {
            SM1_State = SM1_HeaterOn;
            sh = 1;
         }
         break;
      case SM1_HeaterOn:
         if (samplea7a4 >= samplea3a0) {
            SM1_State = SM1_Sample;
            sh = 0;
         }
         break;
      default:
         SM1_State = SM1_Sample;
      } 

   switch(SM1_State) { 
      case SM1_Sample:
         samplea7a4 = (A & 0xF0)>>4;
         samplea3a0 = A &0x0F;
         B0 = 0;
         break;
      case SM1_HeaterOn:
         samplea7a4 =( A & 0xF0)>>4;
         samplea3a0 = A &0x0F;
         B0 =1;
         break;
      default: 
         break;
   } 
}

enum SM2_States { SM2_Off, SM2_On, SM2_IntState } SM2_State;

TickFct_State_machine_2() {
   
   switch(SM2_State) { 
      case -1:
         SM2_State = SM2_IntState;
         break;
      case SM2_Off:
         if (sh ) {
            SM2_State = SM2_On;
         }
         else if (!sh) {
            SM2_State = SM2_IntState;
         }
         break;
      case SM2_On:
         if (sh) {
            SM2_State = SM2_Off;
         }
         else if (!sh) {
            SM2_State = SM2_IntState;
         }
         break;
      case SM2_IntState:
         if (sh) {
            SM2_State = SM2_Off;
         }
         break;
      default:
         SM2_State = SM2_IntState;
      } 

   switch(SM2_State) { 
      case SM2_Off:
         B1 = 0;
         break;
      case SM2_On:
         B1 = 1;
         break;
      case SM2_IntState:
         B1 = 0;
         break;
      default: 
         break;
   } 
}
int main() {
   B = 0; 
   TimerSet(300);
   TimerOn();
   SM1_State = -1;
   SM2_State = -1;
   while(1) {
      TickFct_State_machine_1();
      TickFct_State_machine_2();
      while (!TimerFlag);
      TimerFlag = 0;
   }
}
