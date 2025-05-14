.globl g
g:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    xorl %ecx, %ecx
    xorl %edx, %edx
    addl 8(%esp), %eax
    ret
