.globl binsearch
binsearch:                                                  # int binsearch(int *v, int n, int x){

    pushl %ebx
    pushl %edi
    pushl %esi

    movl 16(%esp), %ebx                                     # int *b = v;
    movl 20(%esp), %edi                                     # int di = n;
    movl 24(%esp), %esi                                     # int si = x;

    xorl %ecx, %ecx                                         # int c = 0;

L:
    cmpl %edi, %ecx
    jge F                                                   # if (c - di >= 0) goto F;

    movl %edi, %eax                                         # int a = di;
    addl %ecx, %eax                                         # a += c;
    sarl $1, %eax                                           # a /= 2;

    cmpl %esi, (%ebx, %eax, 4)
    je T                                                    # if (b[a] == si) goto T;

    cmpl %esi, (%ebx, %eax, 4)
    jle I                                                   # if (b[a] - si <= 0) goto I;

    movl %eax, %edi                                         # di = a;
    jmp L                                                   # goto L;

I:
    movl %eax, %ecx                                         # c = a;
    incl %ecx                                               # c++;
    jmp L                                                   # goto L;

T:
    xorl %eax, %eax
    incl %eax                                               # a = 1;
    jmp R                                                   # goto R,

F:
    xorl %eax, %eax                                         # a = 0;

R:
    popl %esi
    popl %edi
    popl %ebx

    ret
