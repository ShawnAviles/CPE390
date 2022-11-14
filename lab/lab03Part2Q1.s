# Shawn Aviles & Thomas Byrnes
	.globl main
main:
	mov	$6, %rcx
	mov	$7, %rdx
	call	f
	ret

f:
	leaq 	(%rcx, %rdx), %r8 	# (add) r8 = rcx + rdx = 6 + 7 = 13
	shr	$1, %r8					# (logical shift right) r8 >> 1, r8 = r8 / 2 = (rcx + rdx) / 2 = 13 / 2
	mov 	%r8, %rax			# move quotient from r8 to rax to be returned
	ret							# returns value in rax 