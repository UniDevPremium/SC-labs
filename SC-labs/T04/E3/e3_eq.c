char my_strcmp(const char* s1, const char* s2){
    int eax = (int)s1;
    int ecx = (int)s2;

T:
    if(*(char*)eax == '\0') goto R;
    if(*(char*)eax != *(char*)ecx) goto R;
    eax++;
    ecx++;
    goto T;

R:
    char al = *(char*)eax;
    al -= *(char*)ecx;
    return al;
}