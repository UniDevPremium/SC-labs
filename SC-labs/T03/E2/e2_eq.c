// Inserire qui il C equivalente
unsigned int fib(unsigned int n){
    unsigned int edx = n, ecx = 0, eax = 1;
    if (edx != 0) goto F1;
    eax = ecx;
    goto E;

F1:
    if(edx != 1) goto F2;
    goto E;

F2:
    if (edx <= 1) goto E;
    ecx += eax;
    ecx += eax;
    eax = -eax;
    eax += ecx;
    ecx -= eax;
    edx--;
    goto F2;

E:
    return eax;
}