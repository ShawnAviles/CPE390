# 1. Write an assembler function that computes the following:
# Given two 64-bit numbers a,b
# Compute the average of the two

# assuming two numbers a, b passed to rcx, rdx
.function1
	leaq 	(%rcx, %rdx), %r8 	# (add) r8 = rcx + rdx
	shr		$1, %r8				# (logical shift right) r8 >> 1, r8 = r8 / 2 = (rcx + rdx) / 2
	mov 	%r8, %rax			# move quotient from r8 to rax to be returned
	ret							# returns value in rax 
	

# 3. Write an assembler function that computes the following:
# Given: 3 64-bit variables a,b,c
# Return the biggest of the 3

