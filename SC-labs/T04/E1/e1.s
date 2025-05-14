.globl count

count:

    movl 4(%esp), %ecx
    xorl %eax, %eax

T:
    cmpb $0, (%ecx)
    je E
    incl %eax
    incl %ecx
    jmp T

E:
    ret
