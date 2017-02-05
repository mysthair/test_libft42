	.file	"ft_print_memory.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"  "
	.section	.text.unlikely,"ax",@progbits
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	ft_print_memory
	.type	ft_print_memory, @function
ft_print_memory:
.LFB27:
	.cfi_startproc
	testq	%rsi, %rsi
	je	.L52
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movq	%rdi, %r14
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rsi, %r13
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L47:
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L3:
	leaq	(%r12,%rbx), %rax
	cmpq	%rax, %r13
	jbe	.L5
.L72:
	movzbl	(%r14,%rbx), %ebp
	movl	%ebp, %edx
	shrb	$4, %dl
	leal	48(%rdx), %eax
	leal	87(%rdx), %edi
	cmpb	$10, %dl
	cmovb	%eax, %edi
	movsbl	%dil, %edi
	call	ft_putchar
	movl	%ebp, %eax
	andl	$15, %eax
	leal	87(%rax), %edi
	leal	48(%rax), %edx
	cmpb	$10, %al
	cmovb	%edx, %edi
	movsbl	%dil, %edi
	call	ft_putchar
.L10:
	addq	$1, %rbx
	cmpq	$16, %rbx
	jne	.L45
	movl	$32, %edi
	call	ft_putchar
	cmpq	%r12, %r13
	ja	.L56
.L11:
	leaq	1(%r12), %rax
	cmpq	%rax, %r13
	ja	.L57
.L13:
	leaq	2(%r12), %rax
	cmpq	%rax, %r13
	ja	.L58
.L15:
	leaq	3(%r12), %rax
	cmpq	%rax, %r13
	ja	.L59
.L17:
	leaq	4(%r12), %rax
	cmpq	%rax, %r13
	ja	.L60
.L19:
	leaq	5(%r12), %rax
	cmpq	%rax, %r13
	ja	.L61
.L21:
	leaq	6(%r12), %rax
	cmpq	%rax, %r13
	ja	.L62
.L23:
	leaq	7(%r12), %rax
	cmpq	%rax, %r13
	ja	.L63
.L25:
	leaq	8(%r12), %rax
	cmpq	%rax, %r13
	ja	.L64
.L27:
	leaq	9(%r12), %rax
	cmpq	%rax, %r13
	ja	.L65
.L29:
	leaq	10(%r12), %rax
	cmpq	%rax, %r13
	ja	.L66
.L31:
	leaq	11(%r12), %rax
	cmpq	%rax, %r13
	ja	.L67
.L33:
	leaq	12(%r12), %rax
	cmpq	%rax, %r13
	ja	.L68
.L35:
	leaq	13(%r12), %rax
	cmpq	%rax, %r13
	ja	.L69
.L37:
	leaq	14(%r12), %rax
	cmpq	%rax, %r13
	ja	.L70
.L39:
	leaq	15(%r12), %rax
	cmpq	%rax, %r13
	ja	.L71
.L41:
	movl	$10, %edi
	addq	$16, %r12
	addq	$16, %r14
	call	ft_putchar
	cmpq	%r12, %r13
	ja	.L47
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_restore 12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_restore 13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_restore 14
	.cfi_def_cfa_offset 8
.L52:
	rep ret
	.p2align 4,,10
	.p2align 3
.L45:
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	.cfi_offset 6, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	.cfi_offset 14, -16
	testb	$1, %bl
	jne	.L3
	movl	$32, %edi
	call	ft_putchar
	leaq	(%r12,%rbx), %rax
	cmpq	%rax, %r13
	ja	.L72
	.p2align 4,,10
	.p2align 3
.L5:
	movl	$.LC0, %edi
	call	ft_putstr
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L71:
	movzbl	15(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L42
	movl	$46, %edi
	call	ft_putchar
	jmp	.L41
	.p2align 4,,10
	.p2align 3
.L56:
	movzbl	(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L12
	movl	$46, %edi
	call	ft_putchar
	leaq	1(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L13
	.p2align 4,,10
	.p2align 3
.L57:
	movzbl	1(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L14
	movl	$46, %edi
	call	ft_putchar
	leaq	2(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L15
	.p2align 4,,10
	.p2align 3
.L58:
	movzbl	2(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L16
	movl	$46, %edi
	call	ft_putchar
	leaq	3(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L17
	.p2align 4,,10
	.p2align 3
.L59:
	movzbl	3(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L18
	movl	$46, %edi
	call	ft_putchar
	leaq	4(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L19
	.p2align 4,,10
	.p2align 3
.L60:
	movzbl	4(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L20
	movl	$46, %edi
	call	ft_putchar
	leaq	5(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L21
	.p2align 4,,10
	.p2align 3
.L61:
	movzbl	5(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L22
	movl	$46, %edi
	call	ft_putchar
	leaq	6(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L23
	.p2align 4,,10
	.p2align 3
.L62:
	movzbl	6(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L24
	movl	$46, %edi
	call	ft_putchar
	leaq	7(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L25
	.p2align 4,,10
	.p2align 3
.L63:
	movzbl	7(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L26
	movl	$46, %edi
	call	ft_putchar
	leaq	8(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L27
	.p2align 4,,10
	.p2align 3
.L64:
	movzbl	8(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L28
	movl	$46, %edi
	call	ft_putchar
	leaq	9(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L29
	.p2align 4,,10
	.p2align 3
.L65:
	movzbl	9(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L30
	movl	$46, %edi
	call	ft_putchar
	leaq	10(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L31
	.p2align 4,,10
	.p2align 3
.L66:
	movzbl	10(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L32
	movl	$46, %edi
	call	ft_putchar
	leaq	11(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L33
	.p2align 4,,10
	.p2align 3
.L67:
	movzbl	11(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L34
	movl	$46, %edi
	call	ft_putchar
	leaq	12(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L35
	.p2align 4,,10
	.p2align 3
.L68:
	movzbl	12(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L36
	movl	$46, %edi
	call	ft_putchar
	leaq	13(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L37
	.p2align 4,,10
	.p2align 3
.L69:
	movzbl	13(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L38
	movl	$46, %edi
	call	ft_putchar
	leaq	14(%r12), %rax
	cmpq	%rax, %r13
	jbe	.L39
	.p2align 4,,10
	.p2align 3
.L70:
	movzbl	14(%r14), %eax
	leal	-32(%rax), %edx
	cmpb	$94, %dl
	jbe	.L40
	movl	$46, %edi
	call	ft_putchar
	jmp	.L39
.L42:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L41
.L22:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L21
.L12:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L11
.L40:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L39
.L38:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L37
.L16:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L15
.L20:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L19
.L18:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L17
.L14:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L13
.L24:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L23
.L28:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L27
.L26:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L25
.L36:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L35
.L34:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L33
.L32:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L31
.L30:
	movsbl	%al, %edi
	call	ft_putchar
	jmp	.L29
	.cfi_endproc
.LFE27:
	.size	ft_print_memory, .-ft_print_memory
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
