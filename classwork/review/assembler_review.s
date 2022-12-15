sub 	%rcx, %rdx	# rdx = rdx - rcx
cmp 	%rcx, %rdx	# compute rdx -rcx
# sets z flag (zero flag), n flag (negative flag), c flag (carry flag), v flag (overflow)
# compare sets the z flag to 1 if the rdx - rcx

tst 	$1, %rcx 	# and $1 with rdx, pretty much checks for if its off or even
jne 	ODD			

# adding floating points 
addsd