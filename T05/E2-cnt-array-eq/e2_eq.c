int counteq(short* v1, short* v2, int n) {
    int di = (int)v1;
    int si = (int)v2;
    int d = n;
    d--;

    int a = 0;
    
T:
    if (d < 0) goto R;
    short c = *(short*)(di + d * sizeof(short));
    short b = *(short*)(si + d * sizeof(short));
    char cl = c == b;
    int cc = (int)cl;
    a += cc;
    d--;
    goto T;

R:
    return a;
}