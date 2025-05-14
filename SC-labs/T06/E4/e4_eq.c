// Scrivere il C equivalente qui...
#include "e4.h"

int lcm(int x, int y){
    int si = x;
    int di = y;
    int c = di;
    
    if (si - di > 0) c = si;

    int a;

L:
    a = c;
    int d = a % si;
    char bl = d == 0;
    a = c;
    d = a % di;
    char bh = d == 0;
    bl = bl & bh;
    if (bl == 0) goto F;
    goto R;
    
F:
    c++;
    goto L;

R:
    a = c;
    return a;

}