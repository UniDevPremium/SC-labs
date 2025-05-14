# Inserire qui la soluzione
.globl fib
fib:

    movl 4(%esp), %edx              # edx = n
    xorl %ecx, %ecx                 # ecx = 0
    movl $1, %eax                   # eax = 1

    testl %edx, %edx                 # if (edx != 0) goto F1
    jnz F1
    movl %ecx, %eax                 # eax = ecx
    jmp E

F1:

    cmpl $1, %edx                   # if (edx - 1 != 0) goto F2
    jnz F2
    jmp E

F2:

    cmpl $1, %edx                   # if (edx - 1 <= 0) goto E
    jbe E
    addl %eax, %ecx                 # ecx += eax;
    addl %eax, %ecx                 # ecx += eax;
    negl %eax                       # eax = -eax;
    addl %ecx, %eax                 # eax += ecx;
    subl %eax, %ecx                 # ecx -= eax;
    decl %edx                       # edx--;
    jmp F2

E:
    ret
