	.file	"ft_assert.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	":"
.LC1:
	.string	":assert "
.LC2:
	.string	" failed\n"
	.text
	.p2align 4,,15
	.globl	ft_assert
	.type	ft_assert, @function
ft_assert:
.LFB4:
	.cfi_startproc
	testl	%edi, %edi
	je	.L7
	rep ret
	.p2align 4,,10
	.p2align 3
.L7:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rsi, %rdi
	movq	%rcx, %rbx
	movq	%rdx, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	ft_putstr@PLT
	leaq	.LC0(%rip), %rdi
	call	ft_putstr@PLT
	movq	%rbp, %rdi
	call	ft_putstr@PLT
	leaq	.LC1(%rip), %rdi
	call	ft_putstr@PLT
	movq	%rbx, %rdi
	call	ft_putstr@PLT
	leaq	.LC2(%rip), %rdi
	call	ft_putstr@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$-1, %edi
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	jmp	ft_exit@PLT
	.cfi_endproc
.LFE4:
	.size	ft_assert, .-ft_assert
	.ident	"GCC: (Debian 6.3.0-18) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
