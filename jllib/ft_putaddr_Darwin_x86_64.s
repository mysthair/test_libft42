	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_ft_putaddr
	.align	4, 0x90
_ft_putaddr:                            ## @ft_putaddr
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
	movl	$1, %esi
	popq	%rbp
	jmp	_ft_putaddr_fd          ## TAILCALL
	.cfi_endproc


.subsections_via_symbols
