	.globl	main
	.type	main, @function
main:
	mov	$1, %rax
	mov	$2, %rbx
	add	%rbx, %rax
	ret
