# instructions for floating point arithmetic (for INTEL _not_ ARM)

#				%xmm0		#xmm1
# double f(double a, double b);
	.globl _Z1fdd	# "_Z[length of function name: "1"][function name: "f"][type of inputs: double "d", double "d"]
_Z1fdd:
	# %xmm0, %xmm1 (%xmm2, %xmm3) are the first two registers when dealing with floating point
	movsd 	%xmm1, %xmm2   	# temp = b
	addsd	%xmm0, %xmm2	# temp = a + b
	subsd	%xmm0, %xmm1	# b = (a - b), xmm1 = xmm0-xmm1
	mulsd	%xmm2, %xmm0	# xmm1 = (a + b)(a - b)
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

# pointer, int registers: rcx, rdx, rsi, rdi
# double registers: xmm0 - xmm3

#					#rcx	%rdx (or %edx)	%xmm0
# double sub(double arr[], int len, double v);
	.globl _Z3subPdid
_Z3subPdid:
	leaq 	(%rcx, %rdx, 8), %rdi	# rdi = 1st addresss past the end
LOOP2:
	movsd 	(%rcx), %xmm1	# load each element
	movsd 	%xmm0, %xmm2	# xmm2 = xmm0 = v, saves v for later
	subsd	%xmm1, %xmm2	# xmm2 = xmm1 - xmm2 = x[i] - v
	movsd	%xmm2, (%rcx)	# store it back in memory
	addq 	$8, %rcx		# move to next number in array
	cmpq	%rcx, %rdi		# compare rcx == rdi, (changes some comparison register bit)
	jne 	LOOP2 			# jump back to loop2 if rcx != rdx



