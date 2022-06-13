/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/19/2019 23:24:37 PST
*/

#include "rims.h"

/*Define user variables and functions for this state machine here.*/
//HW7
//Anaisy Garcia
//PID: 5734454
//EEL 4730
unsigned char TimerFlag = 0;
void TimerISR() {
   TimerFlag = 1;}
enum SM1_States { SM1_DeOFF, SM1_DeON, SM1_StandBy } SM1_State;

TickFct_State_machine_1() {
   
unsigned char count, cnt;
   switch(SM1_State) { 
      case -1:
         SM1_State = SM1_DeOFF;
         break;
      case SM1_DeOFF:
         if (A0) {
            SM1_State = SM1_DeON;
         }
         break;
      case SM1_DeON:
         if (count >=2) {
            SM1_State = SM1_StandBy;
         }
         break;
      case SM1_StandBy:
         if (!A0) {
            SM1_State = SM1_DeOFF;
         }
         break;
      default:
         SM1_State = SM1_DeOFF;
      }

   switch(SM1_State) { 
      case SM1_DeOFF:
         B0 = 0;
         
         
         
         break;
      case SM1_DeON:
         B0 = 1;
         
         count++;
         break;
      case SM1_StandBy:
         B0 = 0;
         count = 0;
         
         break;
      default: 
         break;
   }
}

enum SM2_States { SM2_BlinkOn, SM2_BlinkOff } SM2_State;

TickFct_State_machine_2() {
   
   switch(SM2_State) {
      case -1:
         SM2_State = SM2_BlinkOn;
         break;
      case SM2_BlinkOn:
         if (1) {
            SM2_State = SM2_BlinkOff;
         }
         break;
      case SM2_BlinkOff:
         if (1
) {
            SM2_State = SM2_BlinkOn;
         }
         break;
      default:
         SM2_State = SM2_BlinkOn;
      } 

   switch(SM2_State) { 
      case SM2_BlinkOn:
         B1 =1;
         break;
      case SM2_BlinkOff:
         B1 = 0;
         break;
      default: 
         break;
   } 
}
int main() {
   B = 0; 
   TimerSet(500);
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
