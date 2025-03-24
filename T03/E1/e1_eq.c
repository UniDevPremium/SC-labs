// Inserire qui il C equivalente
int min(int x, int y, int z){
    int a;
    if (x - y >= 0) goto E;
    if (x - z >= 0) goto F;
    a = x;
    goto S;

E:
    if(y - z >= 0) goto F;
    a = y;
    goto S;

F:
    a = z;

S:
    return a;
}