// inserire il C equivalente qui...
#include "e1.h"

int is_suffix(const char* s1, const char* s2){

    const char* ecx = s1;
    const char* edx = s2;
    const char* esi = ecx;
    const char* edi = edx;

L1: //  while(*esi) esi++;
    if(*esi == '\0') goto L2;
    esi++;
    goto L1;

L2: //  while(*edi) edi++;
    if(*edi == '\0') goto L3;
    edi++;
    goto L1;

L3: //  while (ecx != esi && edx != edi && *(--esi) == *(--edi));
    if(ecx - esi == 0) goto R;
    if(edx - edi == 0) goto R;
    esi--;
    edi--;
    const char al = *esi;
    if(al - *edi != 0) goto R;
    goto L3;
    
R:

    int eax, edxx;
    if(ecx - esi == 0) goto R1;
    eax = 0;
    goto R2;
R1:
    eax = 1;
R2:
    if(*esi - *edi == 0) goto R3;
    edxx = 0;
    goto R4;
R3:
    edxx = 1;
R4:
    eax = eax & edxx;
    return eax;
}