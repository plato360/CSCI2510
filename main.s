	.file	"main.c"
@ GNU C version 3.3.2 (arm-thumb-elf)
@	compiled by GNU C version 3.3.1 (cygming special).
@ GGC heuristics: --param ggc-min-expand=30 --param ggc-min-heapsize=4096
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
	.global	LoadInitialTitleScreen
	.type	LoadInitialTitleScreen, %function
LoadInitialTitleScreen:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	@ lr needed for prologue
	bx	lr
	.size	LoadInitialTitleScreen, .-LoadInitialTitleScreen
	.align	2
	.global	UpdateTitleScreen
	.type	UpdateTitleScreen, %function
UpdateTitleScreen:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	@ lr needed for prologue
	bx	lr
	.size	UpdateTitleScreen, .-UpdateTitleScreen
	.align	2
	.global	DrawTitleScreen
	.type	DrawTitleScreen, %function
DrawTitleScreen:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	@ lr needed for prologue
	bx	lr
	.size	DrawTitleScreen, .-DrawTitleScreen
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {r4, r5, fp, ip, lr, pc}
	ldr	r3, .L9
	sub	fp, ip, #4
	mov	lr, pc
	bx	r3
	ldr	r2, .L9+4
	mov	lr, pc
	bx	r2
	ldr	r5, .L9+8
	ldr	r4, .L9+12
.L8:
	mov	lr, pc
	bx	r5
	mov	lr, pc
	bx	r4
	b	.L8
.L10:
	.align	2
.L9:
	.word	Initialize
	.word	LoadContent
	.word	Update
	.word	Draw
	.size	main, .-main
	.align	2
	.global	Initialize
	.type	Initialize, %function
Initialize:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L12
	mov	r2, #0
	@ lr needed for prologue
	str	r2, [r3, #0]	@  gameState
	bx	lr
.L13:
	.align	2
.L12:
	.word	gameState
	.size	Initialize, .-Initialize
	.align	2
	.global	LoadContent
	.type	LoadContent, %function
LoadContent:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L16
	ldr	r2, [r3, #0]	@  gameState
	cmp	r2, #0
	@ lr needed for prologue
	bxne	lr
	b	LoadInitialTitleScreen
.L17:
	.align	2
.L16:
	.word	gameState
	.size	LoadContent, .-LoadContent
	.align	2
	.global	Update
	.type	Update, %function
Update:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L20
	ldr	r2, [r3, #0]	@  gameState
	cmp	r2, #0
	@ lr needed for prologue
	bxne	lr
	b	UpdateTitleScreen
.L21:
	.align	2
.L20:
	.word	gameState
	.size	Update, .-Update
	.align	2
	.global	Draw
	.type	Draw, %function
Draw:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L24
	ldr	r2, [r3, #0]	@  gameState
	cmp	r2, #0
	@ lr needed for prologue
	bxne	lr
	b	DrawTitleScreen
.L25:
	.align	2
.L24:
	.word	gameState
	.size	Draw, .-Draw
	.comm	gameState, 4, 32
	.ident	"GCC: (GNU) 3.3.2"
