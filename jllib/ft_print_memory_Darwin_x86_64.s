	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_ft_print_memory
	.align	4, 0x90
_ft_print_memory:                       ## @ft_print_memory
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
	subq	$24, %rsp
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
	movq	%rsi, %r12
	movq	%rdi, -64(%rbp)         ## 8-byte Spill
	xorl	%r15d, %r15d
	testq	%r12, %r12
	je	LBB0_22
	.align	4, 0x90
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_2 Depth 2
                                        ##     Child Loop BB0_14 Depth 2
	movq	%r15, -48(%rbp)         ## 8-byte Spill
	movq	-64(%rbp), %rax         ## 8-byte Reload
	leaq	(%rax,%r15), %r13
	movq	%r13, -56(%rbp)         ## 8-byte Spill
	xorl	%r14d, %r14d
	.align	4, 0x90
LBB0_2:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	leaq	(%r15,%r14), %rbx
	movl	%r14d, %eax
	andl	$1, %eax
	testq	%r14, %r14
	je	LBB0_5
## BB#3:                                ##   in Loop: Header=BB0_2 Depth=2
	testq	%rax, %rax
	jne	LBB0_5
## BB#4:                                ##   in Loop: Header=BB0_2 Depth=2
	movl	$32, %edi
	callq	_ft_putchar
LBB0_5:                                 ##   in Loop: Header=BB0_2 Depth=2
	cmpq	%r12, %rbx
	jae	LBB0_11
## BB#6:                                ##   in Loop: Header=BB0_2 Depth=2
	movq	%r12, %r15
	movzbl	(%r13,%r14), %r12d
	movb	%r12b, %bl
	movb	%bl, %al
	shrb	$4, %al
	cmpl	$159, %r12d
	movb	$87, %r13b
	movb	$87, %cl
	ja	LBB0_8
## BB#7:                                ##   in Loop: Header=BB0_2 Depth=2
	movb	$48, %cl
LBB0_8:                                 ##   in Loop: Header=BB0_2 Depth=2
	addb	%al, %cl
	movsbl	%cl, %edi
	callq	_ft_putchar
	andb	$15, %bl
	andl	$15, %r12d
	cmpl	$9, %r12d
	ja	LBB0_10
## BB#9:                                ##   in Loop: Header=BB0_2 Depth=2
	movb	$48, %r13b
LBB0_10:                                ##   in Loop: Header=BB0_2 Depth=2
	addb	%bl, %r13b
	movsbl	%r13b, %edi
	callq	_ft_putchar
	movq	%r15, %r12
	movq	-48(%rbp), %r15         ## 8-byte Reload
	movq	-56(%rbp), %r13         ## 8-byte Reload
	jmp	LBB0_12
	.align	4, 0x90
LBB0_11:                                ##   in Loop: Header=BB0_2 Depth=2
	leaq	L_.str(%rip), %rdi
	callq	_ft_putstr
LBB0_12:                                ##   in Loop: Header=BB0_2 Depth=2
	incq	%r14
	cmpq	$16, %r14
	jne	LBB0_2
## BB#13:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	$32, %edi
	callq	_ft_putchar
	xorl	%ebx, %ebx
	.align	4, 0x90
LBB0_14:                                ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	leaq	(%r15,%rbx), %rax
	cmpq	%r12, %rax
	jae	LBB0_20
## BB#15:                               ##   in Loop: Header=BB0_14 Depth=2
	movsbl	(%r13,%rbx), %eax
	cmpl	$32, %eax
	jl	LBB0_18
## BB#16:                               ##   in Loop: Header=BB0_14 Depth=2
	movzbl	%al, %ecx
	cmpl	$127, %ecx
	je	LBB0_18
## BB#17:                               ##   in Loop: Header=BB0_14 Depth=2
	movsbl	%al, %edi
	jmp	LBB0_19
	.align	4, 0x90
LBB0_18:                                ##   in Loop: Header=BB0_14 Depth=2
	movl	$46, %edi
LBB0_19:                                ##   in Loop: Header=BB0_14 Depth=2
	callq	_ft_putchar
LBB0_20:                                ##   in Loop: Header=BB0_14 Depth=2
	incq	%rbx
	cmpq	$16, %rbx
	jne	LBB0_14
## BB#21:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	$10, %edi
	callq	_ft_putchar
	addq	$16, %r15
	cmpq	%r12, %r15
	jb	LBB0_1
LBB0_22:
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"  "


.subsections_via_symbols
