int find(int* v, int n, int x) {
    int eax = (int)v;
    int ecx = n;
    int edx = x;

T:
    if (n <= 0) goto ZERO;
    if (*(int*)eax == edx) goto UNO;
    eax += sizeof(int);
    n--;
    goto T;

ZERO:
    eax = 0;
    goto END;

UNO:
    eax = 1;

END:
    return eax;
}