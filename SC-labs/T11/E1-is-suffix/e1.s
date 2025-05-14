# scrivere la soluzione qui...
.globl is_suffix
is_suffix:

    pushl %esi
    pushl %edi

#   const char* ecx = s1;
#   const char* edx = s2;
    movl 12(%esp), %ecx
    movl 16(%esp), %edx

#   const char* esi = ecx;
#   const char* edi = edx;
    movl %ecx, %esi
    movl %edx, %edi

L1:
#   if(*esi == '\0') goto L2;
    movb (%esi), %al
    testb %al, %al
    je L2

#   esi++;
    incl %esi
#   goto L1;
    jmp L1

L2:
#   if(*edi == '\0') goto L3;
    movb (%edi), %al
    testb %al, %al
    je L3

#   edi++;
    incl %edi
#   goto L2;
    jmp L2

L3:
#   if(ecx - esi == 0) goto R;
    cmpl %ecx, %esi
    je R
#   if(edx - edi == 0) goto R;
    cmpl %edx, %edi
    je R

#   esi--;
#   edi--;
    decl %esi
    decl %edi

#   const char al = *esi;
    movb (%esi), %al
#   if(al - *edi != 0) goto R;
    cmpb %al, (%edi)
    jne R

#   goto L3;
    jmp L3

R:
#   if(ecx - esi == 0) goto R1
    cmpl %ecx, %esi
    jne R0
    movl $1, %eax
#   goto R2;
    jmp R1;

R0: xorl %eax, %eax

R1: 
#   if(*esi - *edi == 0) goto R3;
    movb (%esi), %cl
    movb (%edi), %dl
    cmpb %cl, %dl
    jne R2
    movl $1, %ecx
    jmp R3

R2: xorl %ecx, %ecx

R3:
    andl %ecx, %eax

#   return eax
    popl %edi
    popl %esi

    ret
