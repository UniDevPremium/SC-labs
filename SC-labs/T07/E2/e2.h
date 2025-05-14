#ifndef __BLUR5__
#define __BLUR5__

void blur5(unsigned char* in, unsigned char* out, int w, int h);
int onEdge(int i, int j, int h, int w, int k);
unsigned int getBoxMean(int i, int j, int w, int k, unsigned char* in);

#endif

