int count(const char *s1){
    int eax = 0;
    int ecx = (int)s1;

T:
    if(!*(char*)ecx) goto E;
    eax++;
    ecx++;
    goto T;
E:
    return eax;
}