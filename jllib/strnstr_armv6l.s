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
	.file	"strnstr.c"
	.text
	.align	2
	.global	strnstr
	.type	strnstr, %function
strnstr:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	cmp	r2, #0
	beq	.L10
	ldrb	r3, [r0]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L29
	stmfd	sp!, {r4, r5, r6, r7, r8, lr}
	sub	r8, r2, #1
	add	r8, r0, r8
	mov	r7, #0
.L8:
	cmp	r2, r7
	bls	.L15
	ldrb	r3, [r1]	@ zero_extendqisi2
	cmp	r3, #0
	ldmeqfd	sp!, {r4, r5, r6, r7, r8, pc}
	ldrb	ip, [r0]	@ zero_extendqisi2
	adds	lr, ip, #0
	movne	lr, #1
	cmp	r3, ip
	movne	lr, #0
	cmp	lr, #0
	beq	.L9
	mov	lr, r0
	mov	r5, r1
	mov	ip, #0
	b	.L6
.L30:
	ldrb	r3, [r5, #1]!	@ zero_extendqisi2
	cmp	r3, #0
	ldmeqfd	sp!, {r4, r5, r6, r7, r8, pc}
	ldrb	r4, [lr, #1]!	@ zero_extendqisi2
	adds	r6, r4, #0
	movne	r6, #1
	cmp	r3, r4
	movne	r6, #0
	cmp	r6, #0
	beq	.L9
.L6:
	add	ip, ip, #1
	cmp	lr, r8
	add	r3, r7, ip
	bne	.L30
.L4:
	cmp	r2, r3
	bcs	.L31
	add	r7, r7, #1
	cmp	r7, r2
	beq	.L14
.L32:
	ldrb	r3, [r0, #1]!	@ zero_extendqisi2
	cmp	r3, #0
	bne	.L8
	mov	r0, r3
	ldmfd	sp!, {r4, r5, r6, r7, r8, pc}
.L31:
	ldrb	r3, [r1, ip]	@ zero_extendqisi2
.L9:
	cmp	r3, #0
	ldmeqfd	sp!, {r4, r5, r6, r7, r8, pc}
	add	r7, r7, #1
	cmp	r7, r2
	bne	.L32
.L14:
	mov	r0, #0
	ldmfd	sp!, {r4, r5, r6, r7, r8, pc}
.L10:
	mov	r0, r2
	bx	lr
.L29:
	ldrb	r3, [r1]	@ zero_extendqisi2
	cmp	r3, #0
	movne	r0, #0
	bx	lr
.L15:
	mov	r3, r7
	mov	ip, #0
	b	.L4
	.size	strnstr, .-strnstr
	.ident	"GCC: (Raspbian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
