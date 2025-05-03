# Inserisci la soluzione qui...

.globl list_equal
list_equal:                                                 # int list_equal(const node_t *l1, const node_t *l2)

    movl 4(%esp), %eax                                      # const node_t *a = l1;
    movl 8(%esp), %ecx                                      # const node_t *c = l2;

T:

    testl %eax, %eax
    jz E                                                    # if (a == 0) goto E;

    testl %ecx, %ecx
    jz E                                                    # if (c == 0) goto E;

    movw (%eax), %dx                                        # short d = (*a).elem;
    cmpw %dx, (%ecx)
    je F                                                    # if (d == (*c).elem) goto F;

    xorl %eax, %eax                                         # a = 0;
    jmp R                                                   # goto R;

F:

    movl 4(%eax), %eax                                      # a = (*a).next;
    movl 4(%ecx), %ecx                                      # c = (*c).next;
    jmp T                                                   # goto T;

E:

    testl %eax, %eax
    setz %al                                                # char al = a == 0;

    testl %ecx, %ecx
    setz %ah                                                # char cl = c == 0;

    andb %ah, %al                                           # al = al & cl
    movsbl %al, %eax                                        # a = (int)al;

R:

    ret                                                     # return a;
