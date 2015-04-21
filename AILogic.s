	.file	"AILogic.c"
@ GNU C version 3.3.2 (arm-thumb-elf)
@	compiled by GNU C version 3.3.1 (cygming special).
@ GGC heuristics: --param ggc-min-expand=99 --param ggc-min-heapsize=131006
@ options passed:  -fpreprocessed -mthumb-interwork -mlong-calls
@ -auxbase-strip -O2 -Wall -fverbose-asm
@ options enabled:  -fdefer-pop -fomit-frame-pointer
@ -foptimize-sibling-calls -fcse-follow-jumps -fcse-skip-blocks
@ -fexpensive-optimizations -fthread-jumps -fstrength-reduce -fpeephole
@ -fforce-mem -ffunction-cse -fkeep-static-consts -fcaller-saves
@ -freg-struct-return -fgcse -fgcse-lm -fgcse-sm -floop-optimize
@ -fcrossjumping -fif-conversion -fif-conversion2 -frerun-cse-after-loop
@ -frerun-loop-opt -fdelete-null-pointer-checks -fschedule-insns
@ -fschedule-insns2 -fsched-interblock -fsched-spec -fbranch-count-reg
@ -freorder-blocks -freorder-functions -fcprop-registers -fcommon
@ -fverbose-asm -fgnu-linker -fregmove -foptimize-register-move
@ -fargument-alias -fstrict-aliasing -fmerge-constants
@ -fzero-initialized-in-bss -fident -fpeephole2 -fguess-branch-probability
@ -fmath-errno -ftrapping-math -mapcs -mapcs-frame -mapcs-32 -msoft-float
@ -mthumb-interwork -mlong-calls

	.text
	.align	2
	.global	AI_Patrol
	.type	AI_Patrol, %function
AI_Patrol:
	@ Function supports interworking.
	@ args = 4, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	cmp	r0, r2	@  x1,  x2
	sub	fp, ip, #4
	ldr	r2, [fp, #4]	@  num
	blt	.L3
.L2:
	mov	r0, #0
	ldmea	fp, {fp, sp, lr}
	bx	lr
.L3:
	ldr	r3, .L4
	mov	lr, pc
	bx	r3
	b	.L2
.L5:
	.align	2
.L4:
	.word	moveSprite
	.size	AI_Patrol, .-AI_Patrol
	.align	2
	.global	AI_follow
	.type	AI_follow, %function
AI_follow:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	r0, #0
	@ lr needed for prologue
	bx	lr
	.size	AI_follow, .-AI_follow
	.align	2
	.global	AI_followWall
	.type	AI_followWall, %function
AI_followWall:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	r0, #0
	@ lr needed for prologue
	bx	lr
	.size	AI_followWall, .-AI_followWall
	.ident	"GCC: (GNU) 3.3.2"
