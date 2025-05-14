# scrivere la soluzione qui...
.globl clone
clone:                              # void* clone(const void* src, int n)
    # prologo
    pushl %esi
    pushl %edi
    pushl %ebx
    subl $12, %esp

    movl 28(%esp), %esi
    movl 32(%esp), %ebx

    movl %ebx, (%esp)
    call malloc
    movl %eax, %edi
    xorl %eax, %eax

    testl %edi, %edi
    je R

    movl %edi, (%esp)
    movl %esi, 4(%esp)
    movl %ebx, 8(%esp)
    call memcpy
    movl %edi, %eax

R:
    # epilogo
    addl $12, %esp
    popl %ebx
    popl %edi
    popl %esi
    ret
