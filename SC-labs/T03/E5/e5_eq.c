int f(int x, int y){
    int eax = x;
    int ecx = y;
    eax += ecx;
    if (eax - 15 <= 0) goto ZERO;
    eax = 1;
    goto END;

ZERO:
    eax = 0;

END:
    return eax;
}