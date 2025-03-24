# scrivere la soluzione qui...
.globl find
find:

    movl 4(%esp), %eax                  # int eax = (int)v;
    movl 8(%esp), %ecx                  # int ecx = n;
    movl 12(%esp), %edx                 # int edx = x;

T:
    cmpl $0, %ecx                       # if (n <= 0) goto ZERO;
    jle ZERO
    cmpl (%eax), %edx                   # if (*(int*)eax == edx) goto UNO;
    je UNO
    addl $4, %eax                       # eax += sizeof(int);
    decl %ecx                           # n--;
    jmp T                               # goto T;

ZERO:
    xorl %eax, %eax                     # eax = 0;
    jmp END                             # goto END;

UNO:
    movl $1, %eax                       # eax = 1;

END:
    ret                                 # return eax;
