# scrivere la soluzione qui...
.globl f
f:
    movl 4(%esp), %eax
    movl 4(%esp), %ecx
    addl 8(%esp), %eax
    subl 8(%esp), %ecx
    imull %ecx, %eax
    ret
