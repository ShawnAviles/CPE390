
	.globl _Z3f1ay
_Z3f1ay:	
	# write a function that counts from 0 to n (which is in %rdi)
	xor %rax, rax 		# clear rax, rax = 0
	top1:
	inc %rax			# increment rdi by 1
	cmp	%rax, %rdi		# compares rax to see if its equal to rdi
	jne top1			# jump if (rax) not equal (to rdi), then jump to top
	ret					# return rax

	.globl _Z3f1by
_Z3f1by:
	# write a function that counts from n down to 1
	mov %rdi, %rax		# rax = rdi = n
	top2:
	dec %rax		# decrement rax by 1
	cmp	$1, %rax		# compares rax to see if its equal to 1
	jne top2			# jump if (rax) not equal (1), then jump to top2
	ret

	.globl _Z3f1cy
_Z3f1cy:
	# Write a function that counts from n down to 1 without using the compare (sub will do!)
	mov %rdi, %rax		# rax = rdi = n
	top3:
	sub $1, %rax		# decrement rax by 1, sub automattically compares against 0?
	jg  top3			# jump if (rax > 0), jump to top3
	ret

	.globl _Z3f2ay
_Z3f2ay:
	# write a function that sums the numbers from 1 to n (which is in %rdi)
	# answers should be returned in %rax
	xor %rax, %rax		# clear rax, rax = 0
	mov $0, %rsi		# rsi = 0
	top4:
	inc %rsi			# increment rsi by 1
	add %rsi, %rax		# rax = rax + rsi
	cmp %rsi, %rdi		# compares rsi (our counter) to see if its equal to rdi (n)
	jne top4
	ret

	.globl _Z3f2by
_Z3f2by:
	# write a function that computes n factorial (products 1 to n)
	xor %rax, %rax		# clear rax, rax = 0;
	inc %rax	 		# rax = 0+1 by default (so we can multiply ti)
	inc %rdi			# rdi = n + 1 (so we can decrement as our first step in the loop)
	top5:
	dec %rdi			# decrement rdi by 1
	mul %rdi 			# rax = rax * rdi (multiplies rax by default which is 64-bit register)
	cmp $1, %rdi		# compare rdi with 1
	jne top5			# jump to top5 if rdi != 0
	ret

