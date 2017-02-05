	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_ft_putaddr_fd
	.align	4, 0x90
_ft_putaddr_fd:                         ## @ft_putaddr_fd
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
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	pushq	%rax
Ltmp3:
	.cfi_offset %rbx, -56
Ltmp4:
	.cfi_offset %r12, -48
Ltmp5:
	.cfi_offset %r13, -40
Ltmp6:
	.cfi_offset %r14, -32
Ltmp7:
	.cfi_offset %r15, -24
	movl	%esi, %r14d
	movq	%rdi, %r15
	testq	%r15, %r15
	je	LBB0_18
## BB#1:
	movq	%r15, %rbx
	shrq	$24, %rbx
	movq	%r15, %r12
	shrq	$16, %r12
	leaq	L_.str.1(%rip), %rdi
	movl	%r14d, %esi
	callq	_ft_putstr_fd
	movq	%r15, %rax
	shrq	$28, %rax
	andb	$15, %al
	movzbl	%bl, %ecx
	cmpl	$159, %ecx
	movb	$87, %cl
	ja	LBB0_3
## BB#2:
	movb	$48, %cl
LBB0_3:
	addb	%al, %cl
	movsbl	%cl, %edi
	movl	%r14d, %esi
	callq	_ft_putchar_fd
	andb	$15, %bl
	movzbl	%bl, %eax
	cmpl	$9, %eax
	movb	$87, %al
	ja	LBB0_5
## BB#4:
	movb	$48, %al
LBB0_5:
	movq	%r15, %r13
	shrq	$8, %r13
	addb	%bl, %al
	movsbl	%al, %edi
	movl	%r14d, %esi
	callq	_ft_putchar_fd
	movq	%r15, %rax
	shrq	$20, %rax
	andb	$15, %al
	movzbl	%r12b, %ecx
	cmpl	$159, %ecx
	movb	$87, %cl
	ja	LBB0_7
## BB#6:
	movb	$48, %cl
LBB0_7:
	addb	%al, %cl
	movsbl	%cl, %edi
	movl	%r14d, %esi
	callq	_ft_putchar_fd
	andb	$15, %r12b
	movzbl	%r12b, %eax
	cmpl	$9, %eax
	movb	$87, %al
	ja	LBB0_9
## BB#8:
	movb	$48, %al
LBB0_9:
	addb	%r12b, %al
	movsbl	%al, %edi
	movl	%r14d, %esi
	callq	_ft_putchar_fd
	movq	%r15, %rax
	shrq	$12, %rax
	andb	$15, %al
	movzbl	%r13b, %ecx
	cmpl	$159, %ecx
	movb	$87, %cl
	ja	LBB0_11
## BB#10:
	movb	$48, %cl
LBB0_11:
	addb	%al, %cl
	movsbl	%cl, %edi
	movl	%r14d, %esi
	callq	_ft_putchar_fd
	andb	$15, %r13b
	movzbl	%r13b, %eax
	cmpl	$9, %eax
	movb	$87, %al
	ja	LBB0_13
## BB#12:
	movb	$48, %al
LBB0_13:
	addb	%r13b, %al
	movsbl	%al, %edi
	movl	%r14d, %esi
	callq	_ft_putchar_fd
	movb	%r15b, %al
	shrb	$4, %al
	movzbl	%r15b, %ecx
	cmpl	$159, %ecx
	movb	$87, %cl
	ja	LBB0_15
## BB#14:
	movb	$48, %cl
LBB0_15:
	addb	%al, %cl
	movsbl	%cl, %edi
	movl	%r14d, %esi
	callq	_ft_putchar_fd
	andb	$15, %r15b
	movzbl	%r15b, %eax
	cmpl	$9, %eax
	movb	$87, %al
	ja	LBB0_17
## BB#16:
	movb	$48, %al
LBB0_17:
	addb	%r15b, %al
	movsbl	%al, %edi
	movl	%r14d, %esi
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	jmp	_ft_putchar_fd          ## TAILCALL
LBB0_18:
	leaq	L_.str(%rip), %rdi
	movl	%r14d, %esi
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	jmp	_ft_putstr_fd           ## TAILCALL
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"NULL"

L_.str.1:                               ## @.str.1
	.asciz	"0x"


.subsections_via_symbols
