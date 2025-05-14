# scrivere la soluzione qui...
.globl f        # int f(int x)
f:
    movl 4(%esp), %eax  # x > eax
    movl 4(%esp), %ecx  # y > ecx = x
    imull 4(%esp), %eax    # x *= x
    imull $2, %eax      # x *= 2
    imull $7, %ecx      # y *= 7
    incl %ecx           # y++
    subl %ecx, %eax     # x -= y
    ret
