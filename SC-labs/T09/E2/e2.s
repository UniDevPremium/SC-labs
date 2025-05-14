.globl crc32b
crc32b:

    pushl %ebx
    pushl %esi
    pushl %edi
    pushl %ebp
    subl $12, %esp

    xorl %ebx, %ebx
    notl %ebx
    movl %ebx, %ebp
    movl 32(%esp), %esi
    movl 36(%esp), %edi

L:
    cmpl $0, %edi
    jle E
    movsbl (%esi), %edx
    incl %esi
    xorl %ebp, %edx
    andl $0xFF, %edx
    movl %edx, 4(%esp)
    leal 8(%esp), %edx
    movl %edx, (%esp)
    call get_constant
    sarl $8, %ebp
    xorl 8(%esp), %ebp
    decl %edi
    jmp L

E:
    xorl %ebx, %ebp
    movl %ebp, %eax
    addl $12, %esp
    popl %ebp
    popl %edi
    popl %esi
    popl %ebx
    ret
