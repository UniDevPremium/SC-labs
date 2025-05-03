# scrivere la soluzione qui...
.globl counteq                  # int counteq(short* v1, short* v2, int n)
counteq:
    # prologo
    pushl %edi
    pushl %esi
    pushl %ebx
    
    movl 16(%esp), %edi         # int di = (int)v1;
    movl 20(%esp), %esi         # int si = (int)v2;
    movl 24(%esp), %edx         # int d = n;
    xorl %eax, %eax             # int a = 0;
    
    decl %edx                   # d--;

T:
    testl %edx, %edx            # if (d < 0)
    jl R                        # goto R;
    movw (%edi, %edx, 2), %cx   # short c = *(short*)(di + d * sizeof(short));
    movw (%esi, %edx, 2), %bx   # short b = *(short*)(si + d * sizeof(short));
    cmpw %cx, %bx
    sete %cl                    # char cl = c == b;
    movsbl %cl, %ecx             # int cc = (int)cl;
    addl %ecx, %eax             # a += cc;
    decl %edx                   # d--;
    jmp T                       # goto T;

R:
    # epilogo
    popl %ebx
    popl %esi
    popl %edi
    ret                         # return a;
