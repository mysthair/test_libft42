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
	.file	"strlcat.c"
	.text
	.align	2
	.global	strlcat
	.type	strlcat, %function
strlcat:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, lr}
	mov	r7, r1
	mov	r5, r2
	mov	r8, r0
	bl	strlen
	mov	r6, r0
	mov	r0, r7
	bl	strlen
	cmp	r6, r5
	mov	r4, r0
	bcc	.L2
	add	r0, r0, r5
	ldmfd	sp!, {r4, r5, r6, r7, r8, pc}
.L2:
	sub	r2, r5, #1
	rsb	r2, r6, r2
	mov	r0, r8
	mov	r1, r7
	bl	strncat
	add	r0, r4, r6
	ldmfd	sp!, {r4, r5, r6, r7, r8, pc}
	.size	strlcat, .-strlcat
	.ident	"GCC: (Raspbian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
