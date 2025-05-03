# Scrivi la soluzione qui...
.globl f
f:

    # STACK
    # y     4B  +32 
    # x     4B  +28
    # ret   4B  +24
    # d     4B  +20
    # r     4B  +16
    # p4    4B  +12
    # p3    4B  +8
    # p2    4B  +4
    # p1    4B  < ESP  
    # TOT   4*6 = 24B
    subl $24, %esp

    # passa parametri
    leal 20(%esp), %eax     # leggo indirizzo &d
    movl %eax, (%esp)       # passo parametro &d

    leal 16(%esp), %eax     # leggo indirizzo &r
    movl %eax, 4(%esp)      # passo parametro &r

    movl 28(%esp), %eax     # leggo parametro x
    movl %eax, 8(%esp)      # passo parametro x

    movl 32(%esp), %eax     # leggo parametro y
    movl %eax, 12(%esp)     # passo parametro y

    call get_div_rem

    movl 20(%esp), %eax

    addl $24, %esp

    ret