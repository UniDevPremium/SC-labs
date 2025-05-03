.globl count_digits
count_digits:

    movl 4(%esp), %ecx
    xorl %eax, %eax

L:

    movsbl (%ecx), %edx
    testl %edx, %edx
    jz R
    cmpl $48, %edx
    jl N
    cmpl $57, %edx
    jg N
    incl %eax

N:

    incl %ecx
    jmp L

R: ret
