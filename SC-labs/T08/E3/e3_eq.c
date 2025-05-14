int count_digits(const char *s) {
    const char* ecx = s;
//     int cnt = 0;
    int eax = 0;
//     while (*s) {
L:
    const int edx = (int)*ecx;
    if(edx == 0) goto R;
//         if (*s >= '0' && *s <= '9') cnt++;
//         // codici ASCII dei caratteri ‘0’ e ‘9’ sono 48 e 57
    if(edx < 48) goto N;
    if(edx > 57) goto N;
    eax++;
//         s++;
//     }
N:
    ecx++;
    goto L;
//     return cnt;
R:
    return eax;
}