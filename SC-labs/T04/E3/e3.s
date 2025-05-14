// scrivere la soluzione qui...
.globl my_strcmp
my_strcmp:

    movl 4(%esp), %eax                          # int eax = (int)s1;
    movl 8(%esp), %ecx                          # int ecx = (int)s2;

T:
    cmpb $0, (%eax)                             # if(*(char*)eax == '\0') goto R;
    je R
    movb (%ecx), %dl                            # if(*(char*)eax != *(char*)ecx) goto R;
    cmpb %dl, (%eax)
    jne R
    incl %eax                                   # eax++;
    incl %ecx                                   # ecx++;
    jmp T                                       # goto T;

R:
    movb (%eax), %al                            # char al = *(char*)eax;
    subb (%ecx), %al                            # al -= *(char*)ecx;
    ret                                         # return al;
