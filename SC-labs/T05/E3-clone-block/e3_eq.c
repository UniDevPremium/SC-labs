#include <stdlib.h>
#include <string.h>

void* clone(const void* src, int n){
    const void* si = src;
    int b = n;
    void* a = malloc(b);
    void* di = a;
    a = 0;
    if (di == 0) goto R;
    memcpy(di, si, b);
    a = di;

R:
    return a;
}