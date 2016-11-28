	.file	"strnstr.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	strnstr
	.type	strnstr, @function
strnstr:
.LFB14:
	.cfi_startproc
	xorl	%eax, %eax
	testq	%rdx, %rdx
	je	.L27
	cmpb	$0, (%rdi)
	je	.L38
	xorl	%r9d, %r9d
	.p2align 4,,10
	.p2align 3
.L9:
	cmpq	%r9, %rdx
	jbe	.L16
	movzbl	(%rsi), %eax
	testb	%al, %al
	je	.L14
	movzbl	(%rdi), %ecx
	testb	%cl, %cl
	je	.L18
	cmpb	%cl, %al
	jne	.L18
	movq	%rdx, %r10
	movl	$1, %eax
	subq	%r9, %r10
	jmp	.L6
	.p2align 4,,10
	.p2align 3
.L39:
	movzbl	(%rsi,%rax), %ecx
	testb	%cl, %cl
	je	.L14
	movzbl	(%rdi,%rax), %r8d
	addq	$1, %rax
	testb	%r8b, %r8b
	je	.L10
	cmpb	%r8b, %cl
	jne	.L10
.L6:
	cmpq	%rax, %r10
	leaq	(%rax,%r9), %rcx
	jne	.L39
.L4:
	cmpq	%rcx, %rdx
	jnb	.L40
.L8:
	addq	$1, %r9
	cmpq	%rdx, %r9
	je	.L15
	addq	$1, %rdi
	cmpb	$0, (%rdi)
	jne	.L9
.L15:
	xorl	%eax, %eax
	ret
.L40:
	movzbl	(%rsi,%rax), %ecx
	.p2align 4,,10
	.p2align 3
.L10:
	testb	%cl, %cl
	jne	.L8
	.p2align 4,,10
	.p2align 3
.L14:
	movq	%rdi, %rax
	ret
.L27:
	rep ret
.L38:
	cmpb	$0, (%rsi)
	cmove	%rdi, %rax
	ret
.L16:
	movq	%r9, %rcx
	xorl	%eax, %eax
	jmp	.L4
.L18:
	movl	%eax, %ecx
	testb	%cl, %cl
	jne	.L8
	jmp	.L14
	.cfi_endproc
.LFE14:
	.size	strnstr, .-strnstr
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
