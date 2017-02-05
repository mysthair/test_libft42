	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_ft_assert
	.align	4, 0x90
_ft_assert:                             ## @ft_assert
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
Ltmp3:
	.cfi_offset %rbx, -32
Ltmp4:
	.cfi_offset %r14, -24
	movq	%rcx, %r14
	movq	%rdx, %rbx
	testl	%edi, %edi
	je	LBB0_2
## BB#1:
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
LBB0_2:
	movq	%rsi, %rdi
	callq	_ft_putstr
	leaq	L_.str(%rip), %rdi
	callq	_ft_putstr
	movq	%rbx, %rdi
	callq	_ft_putstr
	leaq	L_.str.1(%rip), %rdi
	callq	_ft_putstr
	movq	%r14, %rdi
	callq	_ft_putstr
	leaq	L_.str.2(%rip), %rdi
	callq	_ft_putstr
	movl	$-1, %edi
	popq	%rbx
	popq	%r14
	popq	%rbp
	jmp	_ft_exit                ## TAILCALL
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	":"

L_.str.1:                               ## @.str.1
	.asciz	":assert "

L_.str.2:                               ## @.str.2
	.asciz	" failed\n"


.subsections_via_symbols
