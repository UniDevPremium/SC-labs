# Inserisci qui la soluzione...

.globl list_add_first
list_add_first:                                     # int list_add_first(node_t **l, short elem)

    pushl %esi
    pushl %ebx
    subl $4, %esp

    movl 16(%esp), %esi                             # node_t **si = l;
    movl (%esi), %ebx                               # node_t *b = *si; 

    movl $8, (%esp)                                 # param sizeof(node_t)
    call malloc                                     # node_t *a = malloc(sizeof(node_t));

    testl %eax, %eax                                # if (a != NULL)
    jne T                                           # goto T;

    movl $-1, %eax
    jmp R                                           # return -1;

T:

    movl 20(%esp), %edx                              # short d = elem;
    movw %dx, (%eax)                                # (*a).elem = d;
    movl %ebx, 4(%eax)                              # (*a).next = b;
    movl %eax, (%esi)                               # *si = a;
    xorl %eax, %eax
    jmp R                                           # return 0;


R:

    addl $4, %esp
    popl %ebx
    popl %esi

    ret
