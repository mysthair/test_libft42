	.file	"ft_putaddr_fd.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"NULL"
.LC1:
	.string	"0x"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	ft_putaddr_fd
	.type	ft_putaddr_fd, @function
ft_putaddr_fd:
.LFB26:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movl	%esi, %ebp
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	testq	%rdi, %rdi
	movq	%rdi, 8(%rsp)
	je	.L12
	leaq	8(%rsp), %r13
	leaq	4(%rsp), %r12
	movl	$.LC1, %edi
	call	ft_putstr_fd
.L8:
	movzbl	3(%r13), %ebx
	movl	%ebp, %esi
	movl	%ebx, %edx
	shrb	$4, %dl
	leal	48(%rdx), %eax
	leal	87(%rdx), %edi
	cmpb	$10, %dl
	cmovb	%eax, %edi
	movsbl	%dil, %edi
	call	ft_putchar_fd
	movl	%ebx, %eax
	movl	%ebp, %esi
	andl	$15, %eax
	leal	87(%rax), %edi
	leal	48(%rax), %edx
	cmpb	$10, %al
	cmovb	%edx, %edi
	subq	$1, %r13
	movsbl	%dil, %edi
	call	ft_putchar_fd
	cmpq	%r13, %r12
	jne	.L8
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	.cfi_restore_state
	movl	$.LC0, %edi
	call	ft_putstr_fd
	addq	$24, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE26:
	.size	ft_putaddr_fd, .-ft_putaddr_fd
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
