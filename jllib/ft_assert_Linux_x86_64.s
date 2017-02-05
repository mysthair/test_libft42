	.file	"ft_assert.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	":"
.LC1:
	.string	":assert "
.LC2:
	.string	" failed\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB3:
	.text
.LHOTB3:
	.p2align 4,,15
	.globl	ft_assert
	.type	ft_assert, @function
ft_assert:
.LFB24:
	.cfi_startproc
	testl	%edi, %edi
	je	.L6
	rep ret
	.p2align 4,,10
	.p2align 3
.L6:
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
	call	ft_putstr
	movl	$.LC0, %edi
	call	ft_putstr
	movq	%rbp, %rdi
	call	ft_putstr
	movl	$.LC1, %edi
	call	ft_putstr
	movq	%rbx, %rdi
	call	ft_putstr
	movl	$.LC2, %edi
	call	ft_putstr
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$-1, %edi
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	jmp	ft_exit
	.cfi_endproc
.LFE24:
	.size	ft_assert, .-ft_assert
	.section	.text.unlikely
.LCOLDE3:
	.text
.LHOTE3:
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
