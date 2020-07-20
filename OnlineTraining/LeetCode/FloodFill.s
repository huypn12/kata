	.cpu arm10tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"FloodFill.c"
	.text
	.align	2
	.global	createImg
	.arch armv5t
	.syntax unified
	.arm
	.fpu softvfp
	.type	createImg, %function
createImg:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #24
	str	r0, [fp, #-24]
	str	r1, [fp, #-28]
	ldr	r3, [fp, #-28]
	lsl	r3, r3, #2
	mov	r0, r3
	bl	malloc
	mov	r3, r0
	str	r3, [fp, #-12]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L2
.L3:
	ldr	r3, [fp, #-24]
	lsl	r3, r3, #2
	mov	r0, r3
	bl	malloc
	mov	r3, r0
	str	r3, [fp, #-16]
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-12]
	add	r3, r2, r3
	ldr	r2, [fp, #-16]
	str	r2, [r3]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-28]
	cmp	r2, r3
	blt	.L3
	ldr	r3, [fp, #-12]
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
	.size	createImg, .-createImg
	.align	2
	.syntax unified
	.arm
	.fpu softvfp
	.type	isValidCell, %function
isValidCell:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	str	r3, [fp, #-20]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	blt	.L6
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-16]
	cmp	r2, r3
	bge	.L6
	ldr	r3, [fp, #-12]
	cmp	r3, #0
	blt	.L6
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-20]
	cmp	r2, r3
	bge	.L6
	mov	r3, #1
	b	.L8
.L6:
	mov	r3, #0
.L8:
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	isValidCell, .-isValidCell
	.align	2
	.syntax unified
	.arm
	.fpu softvfp
	.type	pushCell, %function
pushCell:
	@ args = 16, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	str	r3, [fp, #-20]
	ldr	r3, [fp, #12]
	ldr	r2, [fp, #8]
	ldr	r1, [fp, #4]
	ldr	r0, [fp, #-20]
	bl	isValidCell
	mov	r3, r0
	cmp	r3, #0
	beq	.L11
	ldr	r3, [fp, #4]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-16]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-20]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r3, [r3]
	ldr	r2, [fp, #16]
	cmp	r2, r3
	bne	.L11
	ldr	r3, [fp, #-12]
	ldr	r3, [r3]
	add	r2, r3, #1
	ldr	r3, [fp, #-12]
	str	r2, [r3]
	ldr	r3, [fp, #-12]
	ldr	r3, [r3]
	lsl	r3, r3, #3
	ldr	r2, [fp, #-8]
	add	r3, r2, r3
	ldr	r2, [fp, #-20]
	str	r2, [r3]
	ldr	r2, [fp, #4]
	str	r2, [r3, #4]
.L11:
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
	.size	pushCell, .-pushCell
	.align	2
	.global	floodFill
	.syntax unified
	.arm
	.fpu softvfp
	.type	floodFill, %function
floodFill:
	@ args = 16, pretend = 0, frame = 56
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #72
	str	r0, [fp, #-48]
	str	r1, [fp, #-52]
	str	r2, [fp, #-56]
	str	r3, [fp, #-60]
	ldr	r3, [fp, #-52]
	str	r3, [fp, #-16]
	ldr	r3, [fp, #-56]
	ldr	r3, [r3]
	str	r3, [fp, #-20]
	ldr	r1, [fp, #-20]
	ldr	r0, [fp, #-16]
	bl	createImg
	str	r0, [fp, #-24]
	ldr	r3, [fp, #12]
	ldr	r2, [fp, #-52]
	str	r2, [r3]
	ldr	r3, [fp, #16]
	ldr	r2, [fp, #-56]
	str	r2, [r3]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L13
.L16:
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L14
.L15:
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-48]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-12]
	lsl	r3, r3, #2
	add	r2, r2, r3
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #2
	ldr	r1, [fp, #-24]
	add	r3, r1, r3
	ldr	r1, [r3]
	ldr	r3, [fp, #-12]
	lsl	r3, r3, #2
	add	r3, r1, r3
	ldr	r2, [r2]
	str	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L14:
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-16]
	cmp	r2, r3
	blt	.L15
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L13:
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-20]
	cmp	r2, r3
	blt	.L16
	ldr	r3, [fp, #-16]
	ldr	r2, [fp, #-20]
	mul	r1, r2, r3
	mov	r3, r1
	lsl	r3, r3, #3
	mov	r0, r3
	bl	malloc
	mov	r3, r0
	str	r3, [fp, #-28]
	ldr	r3, [fp, #-28]
	ldr	r2, [fp, #4]
	str	r2, [r3]
	ldr	r3, [fp, #-28]
	ldr	r2, [fp, #-60]
	str	r2, [r3, #4]
	mov	r3, #0
	str	r3, [fp, #-36]
	ldr	r3, [fp, #-60]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-48]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #4]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r3, [r3]
	str	r3, [fp, #-32]
	b	.L17
.L18:
	ldr	r3, [fp, #-36]
	lsl	r3, r3, #3
	ldr	r2, [fp, #-28]
	add	r2, r2, r3
	sub	r3, fp, #44
	ldm	r2, {r0, r1}
	stm	r3, {r0, r1}
	ldr	r3, [fp, #-40]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-24]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-44]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r2, [fp, #8]
	str	r2, [r3]
	ldr	r3, [fp, #-40]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-48]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-44]
	lsl	r3, r3, #2
	add	r3, r2, r3
	mvn	r2, #0
	str	r2, [r3]
	ldr	r3, [fp, #-36]
	sub	r3, r3, #1
	str	r3, [fp, #-36]
	ldr	r3, [fp, #-44]
	sub	r0, r3, #1
	ldr	r3, [fp, #-40]
	sub	r1, fp, #36
	ldr	r2, [fp, #-32]
	str	r2, [sp, #12]
	ldr	r2, [fp, #-20]
	str	r2, [sp, #8]
	ldr	r2, [fp, #-16]
	str	r2, [sp, #4]
	str	r3, [sp]
	mov	r3, r0
	ldr	r2, [fp, #-48]
	ldr	r0, [fp, #-28]
	bl	pushCell
	ldr	r3, [fp, #-44]
	add	r0, r3, #1
	ldr	r3, [fp, #-40]
	sub	r1, fp, #36
	ldr	r2, [fp, #-32]
	str	r2, [sp, #12]
	ldr	r2, [fp, #-20]
	str	r2, [sp, #8]
	ldr	r2, [fp, #-16]
	str	r2, [sp, #4]
	str	r3, [sp]
	mov	r3, r0
	ldr	r2, [fp, #-48]
	ldr	r0, [fp, #-28]
	bl	pushCell
	ldr	r0, [fp, #-44]
	ldr	r3, [fp, #-40]
	sub	r3, r3, #1
	sub	r1, fp, #36
	ldr	r2, [fp, #-32]
	str	r2, [sp, #12]
	ldr	r2, [fp, #-20]
	str	r2, [sp, #8]
	ldr	r2, [fp, #-16]
	str	r2, [sp, #4]
	str	r3, [sp]
	mov	r3, r0
	ldr	r2, [fp, #-48]
	ldr	r0, [fp, #-28]
	bl	pushCell
	ldr	r0, [fp, #-44]
	ldr	r3, [fp, #-40]
	add	r3, r3, #1
	sub	r1, fp, #36
	ldr	r2, [fp, #-32]
	str	r2, [sp, #12]
	ldr	r2, [fp, #-20]
	str	r2, [sp, #8]
	ldr	r2, [fp, #-16]
	str	r2, [sp, #4]
	str	r3, [sp]
	mov	r3, r0
	ldr	r2, [fp, #-48]
	ldr	r0, [fp, #-28]
	bl	pushCell
.L17:
	ldr	r3, [fp, #-36]
	cmp	r3, #0
	bge	.L18
	ldr	r3, [fp, #-24]
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
	.size	floodFill, .-floodFill
	.section	.rodata
	.align	2
.LC2:
	.ascii	"%d \000"
	.align	2
.LC3:
	.ascii	"...\000"
	.align	2
.LC0:
	.word	2
	.word	2
	.word	2
	.text
	.align	2
	.global	test_1
	.syntax unified
	.arm
	.fpu softvfp
	.type	test_1, %function
test_1:
	@ args = 0, pretend = 0, frame = 80
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #96
	mov	r3, #3
	str	r3, [fp, #-32]
	mov	r3, #2
	str	r3, [fp, #-36]
	ldr	r1, [fp, #-36]
	ldr	r0, [fp, #-32]
	bl	createImg
	str	r0, [fp, #-40]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L21
.L24:
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L22
.L23:
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-40]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-12]
	lsl	r3, r3, #2
	add	r3, r2, r3
	mov	r2, #0
	str	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L22:
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L23
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L21:
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-36]
	cmp	r2, r3
	blt	.L24
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L25
.L28:
	mov	r3, #0
	str	r3, [fp, #-20]
	b	.L26
.L27:
	ldr	r3, [fp, #-20]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-40]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-16]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r0, .L33
	bl	printf
	ldr	r3, [fp, #-20]
	add	r3, r3, #1
	str	r3, [fp, #-20]
.L26:
	ldr	r2, [fp, #-20]
	ldr	r3, [fp, #-36]
	cmp	r2, r3
	blt	.L27
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L25:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L28
	mov	r3, #3
	str	r3, [fp, #-44]
	ldr	r2, .L33+4
	sub	r3, fp, #72
	ldm	r2, {r0, r1, r2}
	stm	r3, {r0, r1, r2}
	mov	r3, #0
	str	r3, [fp, #-48]
	mov	r3, #0
	str	r3, [fp, #-52]
	mov	r3, #2
	str	r3, [fp, #-56]
	mov	r3, #0
	str	r3, [fp, #-76]
	sub	r2, fp, #72
	sub	r3, fp, #80
	str	r3, [sp, #12]
	sub	r3, fp, #76
	str	r3, [sp, #8]
	ldr	r3, [fp, #-56]
	str	r3, [sp, #4]
	ldr	r3, [fp, #-52]
	str	r3, [sp]
	ldr	r3, [fp, #-48]
	ldr	r1, [fp, #-44]
	ldr	r0, [fp, #-40]
	bl	floodFill
	str	r0, [fp, #-60]
	ldr	r0, .L33+8
	bl	puts
	mov	r3, #0
	str	r3, [fp, #-24]
	b	.L29
.L32:
	mov	r3, #0
	str	r3, [fp, #-28]
	b	.L30
.L31:
	ldr	r3, [fp, #-28]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-60]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-24]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r0, .L33
	bl	printf
	ldr	r3, [fp, #-28]
	add	r3, r3, #1
	str	r3, [fp, #-28]
.L30:
	ldr	r2, [fp, #-28]
	ldr	r3, [fp, #-36]
	cmp	r2, r3
	blt	.L31
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-24]
	add	r3, r3, #1
	str	r3, [fp, #-24]
.L29:
	ldr	r2, [fp, #-24]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L32
	mov	r0, #10
	bl	putchar
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L34:
	.align	2
.L33:
	.word	.LC2
	.word	.LC0
	.word	.LC3
	.size	test_1, .-test_1
	.section	.rodata
	.align	2
.LC1:
	.word	3
	.word	3
	.word	3
	.text
	.align	2
	.global	test_2
	.syntax unified
	.arm
	.fpu softvfp
	.type	test_2, %function
test_2:
	@ args = 0, pretend = 0, frame = 80
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #96
	mov	r3, #3
	str	r3, [fp, #-32]
	mov	r3, #3
	str	r3, [fp, #-36]
	ldr	r1, [fp, #-36]
	ldr	r0, [fp, #-32]
	bl	createImg
	str	r0, [fp, #-40]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L36
.L39:
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L37
.L38:
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-40]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-12]
	lsl	r3, r3, #2
	add	r3, r2, r3
	mov	r2, #1
	str	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L37:
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L38
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L36:
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-36]
	cmp	r2, r3
	blt	.L39
	ldr	r3, [fp, #-40]
	add	r3, r3, #4
	ldr	r3, [r3]
	add	r3, r3, #8
	mov	r2, #0
	str	r2, [r3]
	ldr	r3, [fp, #-40]
	add	r3, r3, #8
	ldr	r3, [r3]
	add	r3, r3, #4
	mov	r2, #0
	str	r2, [r3]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L40
.L43:
	mov	r3, #0
	str	r3, [fp, #-20]
	b	.L41
.L42:
	ldr	r3, [fp, #-20]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-40]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-16]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r0, .L48
	bl	printf
	ldr	r3, [fp, #-20]
	add	r3, r3, #1
	str	r3, [fp, #-20]
.L41:
	ldr	r2, [fp, #-20]
	ldr	r3, [fp, #-36]
	cmp	r2, r3
	blt	.L42
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L40:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L43
	mov	r3, #3
	str	r3, [fp, #-44]
	ldr	r2, .L48+4
	sub	r3, fp, #72
	ldm	r2, {r0, r1, r2}
	stm	r3, {r0, r1, r2}
	mov	r3, #1
	str	r3, [fp, #-48]
	mov	r3, #1
	str	r3, [fp, #-52]
	mov	r3, #2
	str	r3, [fp, #-56]
	mov	r3, #0
	str	r3, [fp, #-76]
	sub	r2, fp, #72
	sub	r3, fp, #80
	str	r3, [sp, #12]
	sub	r3, fp, #76
	str	r3, [sp, #8]
	ldr	r3, [fp, #-56]
	str	r3, [sp, #4]
	ldr	r3, [fp, #-52]
	str	r3, [sp]
	ldr	r3, [fp, #-48]
	ldr	r1, [fp, #-44]
	ldr	r0, [fp, #-40]
	bl	floodFill
	str	r0, [fp, #-60]
	ldr	r0, .L48+8
	bl	puts
	mov	r3, #0
	str	r3, [fp, #-24]
	b	.L44
.L47:
	mov	r3, #0
	str	r3, [fp, #-28]
	b	.L45
.L46:
	ldr	r3, [fp, #-28]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-60]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-24]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r0, .L48
	bl	printf
	ldr	r3, [fp, #-28]
	add	r3, r3, #1
	str	r3, [fp, #-28]
.L45:
	ldr	r2, [fp, #-28]
	ldr	r3, [fp, #-36]
	cmp	r2, r3
	blt	.L46
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-24]
	add	r3, r3, #1
	str	r3, [fp, #-24]
.L44:
	ldr	r2, [fp, #-24]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L47
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L49:
	.align	2
.L48:
	.word	.LC2
	.word	.LC1
	.word	.LC3
	.size	test_2, .-test_2
	.align	2
	.global	test_3
	.syntax unified
	.arm
	.fpu softvfp
	.type	test_3, %function
test_3:
	@ args = 0, pretend = 0, frame = 80
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #96
	mov	r3, #2
	str	r3, [fp, #-32]
	mov	r3, #2
	str	r3, [fp, #-36]
	ldr	r1, [fp, #-36]
	ldr	r0, [fp, #-32]
	bl	createImg
	str	r0, [fp, #-40]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L51
.L54:
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L52
.L53:
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-40]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-12]
	lsl	r3, r3, #2
	add	r3, r2, r3
	mov	r2, #0
	str	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L52:
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L53
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L51:
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-36]
	cmp	r2, r3
	blt	.L54
	ldr	r3, [fp, #-40]
	ldr	r3, [r3]
	mov	r2, #1
	str	r2, [r3]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L55
.L58:
	mov	r3, #0
	str	r3, [fp, #-20]
	b	.L56
.L57:
	ldr	r3, [fp, #-20]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-40]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-16]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r0, .L63
	bl	printf
	ldr	r3, [fp, #-20]
	add	r3, r3, #1
	str	r3, [fp, #-20]
.L56:
	ldr	r2, [fp, #-20]
	ldr	r3, [fp, #-36]
	cmp	r2, r3
	blt	.L57
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L55:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L58
	mov	r3, #3
	str	r3, [fp, #-44]
	sub	r3, fp, #72
	mov	r2, #0
	str	r2, [r3]
	str	r2, [r3, #4]
	str	r2, [r3, #8]
	mov	r3, #2
	str	r3, [fp, #-72]
	mov	r3, #2
	str	r3, [fp, #-68]
	mov	r3, #0
	str	r3, [fp, #-48]
	mov	r3, #0
	str	r3, [fp, #-52]
	mov	r3, #2
	str	r3, [fp, #-56]
	mov	r3, #0
	str	r3, [fp, #-76]
	sub	r2, fp, #72
	sub	r3, fp, #80
	str	r3, [sp, #12]
	sub	r3, fp, #76
	str	r3, [sp, #8]
	ldr	r3, [fp, #-56]
	str	r3, [sp, #4]
	ldr	r3, [fp, #-52]
	str	r3, [sp]
	ldr	r3, [fp, #-48]
	ldr	r1, [fp, #-44]
	ldr	r0, [fp, #-40]
	bl	floodFill
	str	r0, [fp, #-60]
	ldr	r0, .L63+4
	bl	puts
	mov	r3, #0
	str	r3, [fp, #-24]
	b	.L59
.L62:
	mov	r3, #0
	str	r3, [fp, #-28]
	b	.L60
.L61:
	ldr	r3, [fp, #-28]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-60]
	add	r3, r2, r3
	ldr	r2, [r3]
	ldr	r3, [fp, #-24]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r0, .L63
	bl	printf
	ldr	r3, [fp, #-28]
	add	r3, r3, #1
	str	r3, [fp, #-28]
.L60:
	ldr	r2, [fp, #-28]
	ldr	r3, [fp, #-36]
	cmp	r2, r3
	blt	.L61
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-24]
	add	r3, r3, #1
	str	r3, [fp, #-24]
.L59:
	ldr	r2, [fp, #-24]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L62
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L64:
	.align	2
.L63:
	.word	.LC2
	.word	.LC3
	.size	test_3, .-test_3
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu softvfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	bl	test_1
	bl	test_2
	bl	test_3
	mov	r3, #0
	mov	r0, r3
	pop	{fp, pc}
	.size	main, .-main
	.ident	"GCC: (crosstool-NG 1.24.0) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
