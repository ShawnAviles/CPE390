# Notes:
# 	Fastest way to reset a value (set it to 0) - XOR the value with itself
#	Moving it takes longer

	.globl main
main:
	mov		$2,		%eax	# immediate mode eax = 5
	mov		$5,		%rsi 	# rsi = 5
	mov		$rdi,	%eax	# rdi = 7
	andq	$rsi,	%r9		# r9 = rax
	mov		%rdi, 	%r9		# r9 = rax + rdi
	orq		
	ret						# return the caller, end the program