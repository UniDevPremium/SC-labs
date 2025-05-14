# Inserire qui la soluzione
.globl min
min:

    movl 4(%esp), %eax          # eax = x
    movl 8(%esp), %ecx          # ecx = y
    movl 12(%esp), %edx         # edx = x
    
    cmpl %ecx, %eax             # if (x - y >= 0) goto E
    jge E
    cmpl %edx, %eax             # if (x - z >= 0) goto F
    jge F
    jmp S                       # a = x; goto S

E:

    cmpl %edx, %ecx             # if (y - z >= 0) goto F
    jge F
    movl %ecx, %eax             # a = y
    jmp S

F:

    movl %edx, %eax             # a = z

S:

    ret
