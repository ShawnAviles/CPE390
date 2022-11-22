# code for stack.cc

	.globl copy
	# rcx points to source
	# rdx points to destination 
	# rsi is the number of 64-bit
copy:
	movq	(%rcx), $r9
	movq	%r9, (%rdx)
	addq 	$8, %rcx		# need to move forward by 8 bytes to get to next one
	addq	$8, %rdx
	subq 	$1, rsi
	cmp 	$0, %rsi
	jne		copy
	ret