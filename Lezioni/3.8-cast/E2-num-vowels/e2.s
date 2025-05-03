// Scrivi la soluzione qui...
.globl num_vowels                       # int num_vowels(char *s)
num_vowels:
    # PROLOGO
    pushl %ebx
    pushl %edi
    subl $4, %esp
    # STACK
    # s     4B
    # ret add
    # ebx
    # edi
    # param 4B

    movl 16(%esp), %ebx                 # char* b = s;
    xorl %edi, %edi                     # int di = 0;

T:
    cmpb $0, (%ebx)                     # if(*b == 0)
    je R                                # goto R;
    movsbl (%ebx), %eax                 # int a = *b;
    movl %eax, (%esp)                   # param
    call is_vowel                       # a = is_vowel(a);
    addl %eax, %edi                     # di += a;
    incl %ebx                           # b++;
    jmp T                               # goto T;

R:
    movl %edi, %eax                     # a = di;

    # EPILOGO
    addl $4, %esp
    pushl %edi
    pushl %ebx

    ret
