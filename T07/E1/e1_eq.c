#include "e1.h"

int binsearch(int *v, int n, int x){

    int *b = v;
    int di = n; // j
    int si = x;

    int c = 0; // i

L:
    if (c - di >= 0) goto F;
    int a = di;
    a += c;
    a /= 2;
    if (b[a] == si) goto T;
    if (b[a] - si <= 0) goto I;
    di = a;
    goto L;

I:
    c = a;
    c++;
    goto L;

T:
    a = 1;
    goto R;

F:
    a = 0;

R:
    return a;
}