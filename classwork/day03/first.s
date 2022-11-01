# Notes; 
# 	Immeidate Mode "$2" means that the value that need is in the current bits (don't go seaerching somewhere else for it), its essentially a constant

# Run: g++ first.s 

# Look at Instrucitons: gdb a
# Command: layout asm

# Display the registers
# Command: layout reg

# Breakpoint main
# Command: b main

	.globl main
main:
	mov		$5,		%eax	# immediate mode eax = 5
	addl	$6,		%eax 	# immediate mod, eax = eax + 5
	mov		$7,		%eax	# rdi = 7
	movq	%rax,	%r9		# r9 = rax
	addq	%rdi, 	%r9		# r9 = rax + rdi
	ret						# return the caller, end the program