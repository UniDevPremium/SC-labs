// Inserire qui il C equivalente
int comp(const void* xv, const void* yv){
    int eax = (int)xv;
    int ecx = (int)yv;

    eax = *(int*)eax;
    ecx = *(int*)ecx;

    eax -= ecx;
    return eax;
}