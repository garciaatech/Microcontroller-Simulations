#include "RIMS.h"

// Set B to 00000000 when A1A0=00, to 01010101 when A1A0=01, 
// to 10101010 when A1A0=10, and to 11111111 when A1A0=11
void main()
{
   while (1) { 
      if (!A1 && !A0) {
         B = 0x00; // 0000 0000
      }
      else if (!A1 && A0) {
         B = 0x55; // 0101 0101
      }
      else if (A1 && !A0) {
         B = 0xAA; // 1010 1010
      }
      else if (A1 && A0) {
         B = 0xFF; // 1111 1111
      }
   }
}