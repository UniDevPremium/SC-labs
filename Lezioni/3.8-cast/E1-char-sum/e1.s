# Scrivere soluzione qui...
.globl f
f:                              # int f(char *p, char *q) {
    movl 4(%esp), %eax
    movl 8(%esp), %ecx

    movsbl (%eax), %eax         # a = (int)*p
    movsbl (%ecx), %ecx         # c = (int)*q

    addl %ecx, %eax             # a += c
    
    ret
