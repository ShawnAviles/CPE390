	leaq 	(%rxc, %rdx), %rax
	leaq 	(%rxc, %rdx, 4), %rax	# rax = rcx + (rdx << 2)
	leaq 	(%rxc, %rdx, 8), %rax	# rax = rcx + (rdx << 3)

	# 99 * 99
	imulq 	%rcx, $rax  			# rax = rax * rcx
	
	# x = x * 5 (%rcx = x)
	imulq	%5, $rxc				# rcx = rcx * 5 		(slower)
	leaq	(%rcx, %rcx, 4), %rcx	# rcx = rcx + rcx * 4	(faster)

	# x << 3 
	shlq	$3, %rxc

	# x * 16 (g++ -o2 (optimizer))
	shlq	$4, %rcx

	# x / 16 (g++ -o2 (optimizer))
	shrq	$4, %rcx

	# x mod 64 		x % 64
	# 101011100
	# 101011101
	# 101011110
	# 101011111
	# 101100000
	# only works if its a power of 2
	# you need the last n bits to get the value, 
	# so we use a bitmask to AND it with the value
	# Note: don't have to append "q" or "l" (at least for the purpose of this class)
	andq	$0x3F, %rcx 
	ret


	# count from 0 to 9
f:
	xor		%rax, %rax 		# (same as: mov $0, %r8, but faster) but using XOR is how zero-ing a register should be done
loop:						# the "." doesn't matter in the name
	addq	$1, %rax
	cmpq	$10, %rax
	jl		loop			# jump if less than
	ret

	# count down from 9 to 0
g: 
	mov 	$10, %rax		# rax = 10
loop2:
	subq  	$1, %rax
	cmpq 	$0, %rax
	jb		loop2			# jump if bigger
	ret

# 
	addq	(%rcx), %rax	# load from memory location rcx into rax
