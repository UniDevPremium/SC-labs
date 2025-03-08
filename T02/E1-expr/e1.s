# scrivere la soluzione qui...
.globl f    # int f()
f:          #
    # x > eax   # int x
    movl $2, %eax   # x = 2
    addl $3, %eax   # x += 3
    # y > ecx       # int y
    movl $4, %ecx   # y = 4
    subl $2, %ecx   # y -= 2
    imull %ecx, %eax    # x *= y
    movl $2, %ecx   # y = 2
    addl $3, %ecx   # y += 3
    subl %ecx, %eax # x -= y
    imull $3, %eax  # x *= 3
    incl %eax       # x++
    ret             # ret
