# Scrivere la soluzione qui...
.globl lcm
lcm:                                            # int lcm(int x, int y)
    pushl %esi
    pushl %edi
    pushl %ebx

    movl 16(%esp), %esi                          # int si = x;
    movl 20(%esp), %edi                          # int di = y;
    movl %edi, %ecx                              # int c = di;

    cmpl %esi, %edi
    cmova %esi, %ecx                            # if (si - di > 0) c = si;

L:
    movl %ecx, %eax                             # a = c;
    movl %eax, %edx
    sarl $31, %edx
    idivl %esi                                  # int d = a % si;
    testl %edx, %edx
    setzb %bl                                   # char bl = d == 0;

    movl %ecx, %eax                             # a = c;
    movl %eax, %edx
    sarl $31, %edx
    idivl %edi                                  # d = a % di;
    testl %edx, %edx
    setzb %bh                                   # char bh = d == 0;

    andb  %bh, %bl                              # bl = bl & bh;
    testb %bl, %bl                              
    jz F                                        # if (bl == 0) goto F;
    jmp R                                       # goto R;

F:

    incl %ecx                                   # c++;
    jmp L                                       # goto L;

R:
    movl %ecx, %eax                             # a = c;
    popl %ebx
    popl %edi
    popl %esi
    ret
