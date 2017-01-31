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
	.file	"ft_putaddr_fd.c"
	.text
	.align	2
	.global	ft_putaddr_fd
	.type	ft_putaddr_fd, %function
ft_putaddr_fd:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, lr}
	sub	sp, sp, #12
	cmp	r0, #0
	str	r0, [sp, #4]
	beq	.L12
	ldr	r0, .L13
	mov	r6, r1
	bl	ft_putstr_fd
	add	r7, sp, #4
	add	r5, sp, #6
.L8:
	ldrb	r4, [r5, #-1]!	@ zero_extendqisi2
	mov	r1, r6
	mov	r3, r4, lsr #4
	cmp	r3, #9
	add	r0, r3, #48
	addhi	r0, r3, #87
	bl	ft_putchar_fd
	and	r3, r4, #15
	cmp	r3, #9
	add	r0, r3, #48
	mov	r1, r6
	addhi	r0, r3, #87
	bl	ft_putchar_fd
	cmp	r5, r7
	bne	.L8
	add	sp, sp, #12
	@ sp needed
	ldmfd	sp!, {r4, r5, r6, r7, pc}
.L12:
	ldr	r0, .L13+4
	bl	ft_putstr_fd
	add	sp, sp, #12
	@ sp needed
	ldmfd	sp!, {r4, r5, r6, r7, pc}
.L14:
	.align	2
.L13:
	.word	.LC1
	.word	.LC0
	.size	ft_putaddr_fd, .-ft_putaddr_fd
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"NULL\000"
	.space	3
.LC1:
	.ascii	"0x\000"
	.ident	"GCC: (Raspbian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
