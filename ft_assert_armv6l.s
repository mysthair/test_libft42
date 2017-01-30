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
	.file	"ft_assert.c"
	.text
	.align	2
	.global	ft_assert
	.type	ft_assert, %function
ft_assert:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	cmp	r0, #0
	bxne	lr
	stmfd	sp!, {r3, r4, r5, lr}
	mov	r0, r1
	mov	r4, r3
	mov	r5, r2
	bl	ft_putstr
	ldr	r0, .L5
	bl	ft_putstr
	mov	r0, r5
	bl	ft_putstr
	ldr	r0, .L5+4
	bl	ft_putstr
	mov	r0, r4
	bl	ft_putstr
	ldr	r0, .L5+8
	bl	ft_putstr
	mvn	r0, #0
	ldmfd	sp!, {r3, r4, r5, lr}
	b	ft_exit
.L6:
	.align	2
.L5:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.size	ft_assert, .-ft_assert
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	":\000"
	.space	2
.LC1:
	.ascii	":assert \000"
	.space	3
.LC2:
	.ascii	" failed\012\000"
	.ident	"GCC: (Raspbian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
