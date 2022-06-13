#include "RIMS.h"

void main()
{
   unsigned char sound1 = 0;
   unsigned char sound2 = 0;

   while (1) { 
      sound1 = A & 0x0F; // 0000A3A2A1A0
      sound2 = A >> 4;   // A7A6A5A4A3A2A1A0 --> 0000A7A6A5A4
      B = sound1 + sound2;
   }
}