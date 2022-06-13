#include "rims.h"

void main()
{
   while (1) { 
      unsigned char i, val;
val = A0;  
for (i = 0; i < 4; i++) {
   B = SetBit(B, i, val);
}
   }
}
