.globl f

f:									# int f(int x, int y){
	movl 4(%esp), %eax
	movl 8(%esp), %ecx

	addl %ecx, %eax					# z += y;
	cmpl $15, %eax					# if (z <= 15) goto E;
	jle ZERO
	movl $1, %eax
	jmp END

ZERO:
	xorl %eax, %eax					
	
END:
	ret
