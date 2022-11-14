# Shawn Aviles & Thomas Byrnes
	.globl	main
main:
	mov     $3, %rcx
	mov 	$1, %rdx
	mov	    $1, %rsi
	call		maskandcompare

	mov 	$3, %rcx
	mov 	$1, %rdx 
	mov     $0, %rsi 
	call	maskandcompare

	mov 	$16, %rcx
	mov 	$15, %rdx
	mov	    $0, %rsi
	call	maskandcompare
	ret

maskandcompare:
	mov %rcx, %r8		# move rcx into r8
	and %rdx, %r8		# and rdx and rcx, store in r8
	cmp %rsi, %r8		# compare rsi and (rdx & rcx), store in r8
	je true				# jump to true tag if rsi == r8
	mov $0,  %rax		# set rax to 0 if false
	ret					# return when false
true:
	mov $1, %rax		# set rax to 1 if rsi == r8
	ret					# return when true
