/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/12/2019 22:3:58 PST
*/

#include "rims.h"

/*Define user variables and functions for this state machine here.*/
//HW5
//Anaisy Garcia
//PID: 5734454
//EEL 4730

unsigned char k, i;
unsigned char SM1_Clk;
void TimerISR() {
   SM1_Clk = 1;
}

enum SM1_States { SM1_Initial, SM1_On, SM1_Off } SM1_State;

TickFct_State_machine_1() {
   switch(SM1_State) { 
      case -1:
         SM1_State = SM1_Initial;
         break;
         case SM1_Initial: 
         if (A0) {
            SM1_State = SM1_On;
         }
         break;
      case SM1_On: 
         if (!A0) {
            SM1_State = SM1_Initial;
         }
         else if (k==8) {
            SM1_State = SM1_Off;
            i=0;
         }
         break;
      case SM1_Off: 
         if (!A0) {
            SM1_State = SM1_Initial;
         }
         else if (i==2) {
            SM1_State = SM1_On;
            k=0;
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
      case SM1_On:
         B0=1;
         k++;
         break;
      case SM1_Off:
         B0=0;
         i++;
         break;
      default: 
      break;
   } 

}

int main() {

   const unsigned int periodState_machine_1 = 100;
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
