# instructions for floating point arithmetic (for INTEL _not_ ARM)

#				%xmm0		#xmm1
# double f(double a, double b);
	.globl _Z1fdd	# "_Z[length of function name: "1"][function name: "f"][type of inputs: double "d", double "d"]
_Z1fdd:
	# %xmm0, %xmm1 (%xmm2, %xmm3) are the first two registers when dealing with floating point
	movsd 	%xmm1, %xmm2   	# temp = b
	addsd	%xmm0, %xmm2	# temp = a + b
	subsd	%xmm0, %xmm1	# b = (a - b)
	mulsd	%xmm2, %xmm1	# xmm1 = (a + b)(a - b)
	movsd 	%xmm1, %xmm0	# xmm0 = xmm1 , put final answer into xmm0
	ret

#					#rcx		%rdx (or %edx)
# double sum(double arr[], int len);
	.globl _Z3sumPdi # "_Z[length of function name: "3"][function name: "sum"][type of inputs:  pointer double "Pd" , integer "i"]"
_Z3sum:
	xorpd 	%xmm0, %xmm0
LOOP:
	movsd 	(%rcx), %xmm1
	addsd	%xmm1, %xmm0
	addq	$8, %rcx
	sub 	$1, rdx
	jne 	LOOP
	ret
