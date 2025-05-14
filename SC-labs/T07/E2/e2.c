// Scrivere la soluzione qui...
#include <stdio.h>
#include "e2.h"

int onEdge(int i, int j, int h, int w, int k){
    int n = k / 2;
    if (
        (i - n < 0) ||
        (i + n >= h) ||
        (j - n < 0) ||
        (j + n >= w)
    ) return 1; // è sul bordo
    return 0; // non è sul bordo
}

unsigned int getBoxMean(int i, int j, int w, int k, unsigned char* in){
    unsigned int res = 0;
    int n = (k / 2);
    for(int r = -n; r <= n; r++){
        for (int c = -n; c <= n; c++){
            res += (unsigned int)in[(i+r)*w + (j+c)];
        }
    }
    res /= (k * k);
    return res;
}

void blur5(unsigned char* in, unsigned char* out, int w, int h){
    int i = 0, j = 0;
    // int c = 0;
    for (; i < h; i++){
        for (j = 0; j < w; j++){
            // calcola la media dei valori
            unsigned int mean;
            if(onEdge(i, j, h, w, 5)) {
                // c++;
                mean = (int)in[i*w + j];
            } else {
                // mean = 0;
                // for(int m = -2; m <= 2; m++){
                //     for (int n = -2; n <= 2; n++){
                //         mean += (int)in[(i+m)*w + (j+n)];
                //     }
                // }
                // mean /= 25;
                mean = getBoxMean(i, j, w, 5, in);
            }
            out[i*w + j] = (unsigned char)mean;
        }
    }
    // printf("Sul bordo %d.\n", c);
}

