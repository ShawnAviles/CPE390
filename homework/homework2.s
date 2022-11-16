# 1. Write an assembler function that computes the following:
# Given two 64-bit numbers a,b
# Compute the average of the two

# Assumptions: 
# two numbers a, b inside of rcx, rdx
# we don't cast anything into a larger datatype - using uint64_t instead of double
function1:
	leaq 	(%rcx, %rdx), %r8 	# (add) r8 = rcx + rdx
	shrq	$1, %r8				# (logical shift right) r8 >> 1, r8 = r8 / 2 = (rcx + rdx) / 2
	movq 	%r8, %rax			# move quotient from r8 to rax to be returned
	ret							# return value in rax 
	

# 3. Write an assembler function that computes the following:
# Given: 3 64-bit variables a,b,c
# Return the biggest of the 3

# Assumptions
# a, b, c are inside of rcx, rdx, rdi (respectively) when this funciton is called
# values of a, b, c are all different numbers
function2:
	
	

