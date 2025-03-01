// Inserire la soluzione qui...
#include <stdio.h>
#include "e1.h"

void uint2bin(unsigned x, char bin[32]){
    for(int i = 1; i <= 32; i++){
        bin[32-i] = (x & 1) ? '1' : '0';
        x = x >> 1;
    }
}