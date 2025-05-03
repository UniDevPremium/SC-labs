# scrivere la soluzione qui...
.globl fib
fib:                            # int fib(int n)
    # prologo callee saved e parametri
    pushl %edi
    pushl %ebx
    subl $4, %esp
    
    movl 16(%esp), %edi         # int di = n;
    movl $1, %eax               # int a = 1;
    cmpl $2, %edi               # if (di < 2)
    jl R                        # goto R;
    decl %edi                   # di--;
    movl %edi, (%esp)
    call fib                    # a = fib(di);
    movl %eax, %ebx             # int b = a;
    decl %edi                   # di--;
    movl %edi, (%esp)
    call fib                    # a = fib(di);
    addl %ebx, %eax             # a += b;

R:
    # epilogo
    addl $4, %esp
    popl %ebx
    popl %edi
    ret                         # return a;
