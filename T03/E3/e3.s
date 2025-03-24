# Inserire qui la soluzione
.globl comp
comp:

    movl 4(%esp), %eax              # eax = xv
    movl 8(%esp), %ecx              # ecx = yv

    movl (%eax), %eax               # eax = *eax
    movl (%ecx), %ecx               # ecx = *ecx

    subl %ecx, %eax                 # eax -= ecx

    ret
