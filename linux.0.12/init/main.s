	.file	"main.c"
	.text
.globl printk
	.type	printk, @function
printk:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	ret
	.size	printk, .-printk
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
.L4:
	jmp	.L4
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
