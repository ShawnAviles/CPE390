	.globl main
main:
	mov 	%9, %rcx
	mov		$11, %rdx

	mov1 	%rcx, %r8
	andq	%rdx, %r8				# r8 = rcx AND rdx

	movq 	%rcx, %r9
	orq	 	%rdx, %r9

	movq 	%rcx, %r10
	xorq 	%rdx, %r10

	leaq 	(%rcx, %rdx), %r11 	# add

	movq 	%rcx, %r11			# slower add
	addq 	$rdx, %r11

	shl1 $2, %r11 				# logical shift left
	shr1 $1, %r11 				# logical shift right

	negq %r11					# negate (two's complement)


