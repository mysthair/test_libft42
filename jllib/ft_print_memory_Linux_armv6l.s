	.arch armv6
	.eabi_attribute 27, 3
	.eabi_attribute 28, 1
	.fpu vfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"ft_print_memory.c"
	.text
	.align	2
	.global	ft_print_memory
	.type	ft_print_memory, %function
ft_print_memory:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	cmp	r1, #0
	beq	.L25
	stmfd	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
	mov	r8, r0
	mov	r6, r1
	mov	r9, r0
	mov	r7, #0
.L13:
	mov	r5, #0
.L15:
	add	r3, r5, r7
	cmp	r6, r3
	bls	.L4
.L27:
	ldrb	r4, [r9, r5]	@ zero_extendqisi2
	add	r5, r5, #1
	mov	r0, r4, lsr #4
	cmp	r0, #9
	addhi	r0, r0, #87
	addls	r0, r0, #48
	and	r4, r4, #15
	bl	ft_putchar
	cmp	r4, #9
	addhi	r0, r4, #87
	addls	r0, r4, #48
	bl	ft_putchar
	cmp	r5, #16
	beq	.L26
.L16:
	tst	r5, #1
	bne	.L15
	mov	r0, #32
	bl	ft_putchar
	add	r3, r5, r7
	cmp	r6, r3
	bhi	.L27
.L4:
	ldr	r0, .L29
	add	r5, r5, #1
	bl	ft_putstr
	cmp	r5, #16
	bne	.L16
.L26:
	mov	r0, #32
	add	r7, r7, #16
	bl	ft_putchar
	add	r5, r8, r7
	mov	r4, r9
	b	.L12
.L10:
	add	r4, r4, #1
	cmp	r4, r5
	beq	.L28
.L12:
	rsb	r3, r8, r4
	cmp	r3, r6
	bcs	.L10
	ldrb	r3, [r4]	@ zero_extendqisi2
	mov	r0, #46
	add	r4, r4, #1
	sub	r2, r3, #32
	cmp	r2, #93
	movls	r0, r3
	bl	ft_putchar
	cmp	r4, r5
	bne	.L12
.L28:
	mov	r0, #10
	bl	ft_putchar
	cmp	r6, r7
	add	r9, r9, #16
	bhi	.L13
	ldmfd	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
.L25:
	bx	lr
.L30:
	.align	2
.L29:
	.word	.LC0
	.size	ft_print_memory, .-ft_print_memory
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"  \000"
	.ident	"GCC: (Raspbian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
