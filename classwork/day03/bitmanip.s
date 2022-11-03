# Notes:
# 	Fastest way to reset a value (set it to 0) - XOR the value with itself
#	Moving it takes longer

	.globl main
main:
	mov		$2,		%eax	# immediate mode eax = 5
	mov		$5,		%rsi 	# rsi = 5
	mov		$rdi,	%eax	# rdi = 7
