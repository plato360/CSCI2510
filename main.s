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
	.global	videoBuffer
	.data
	.align	2
	.type	videoBuffer, %object
	.size	videoBuffer, 4
videoBuffer:
	.word	100663296
	.global	ScanlineCounter
	.align	2
	.type	ScanlineCounter, %object
	.size	ScanlineCounter, 4
ScanlineCounter:
	.word	67108870
	.global	SpriteData3
	.align	2
	.type	SpriteData3, %object
	.size	SpriteData3, 4
SpriteData3:
	.word	100745216
	.global	BUTTONS
	.align	2
	.type	BUTTONS, %object
	.size	BUTTONS, 4
BUTTONS:
	.word	67109168
	.text
	.align	2
	.global	WaitVBlank
	.type	WaitVBlank, %function
WaitVBlank:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	@ lr needed for prologue
	mov	r2, #67108864
.L5:
	ldrh	r3, [r2, #6]
	cmp	r3, #159
	bhi	.L5
	mov	r2, #67108864
.L8:
	ldrh	r3, [r2, #6]
	cmp	r3, #159
	bls	.L8
	bx	lr
	.size	WaitVBlank, .-WaitVBlank
	.align	2
	.global	CheckButtons
	.type	CheckButtons, %function
CheckButtons:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, lr}
	ldr	r2, .L12
	ldr	r3, [r2, #0]	@  BUTTONS
	ldr	r8, [r3, #0]
	ldr	r1, [r3, #0]
	ldr	r0, [r3, #0]
	ldr	ip, [r3, #0]
	ldr	lr, [r3, #0]
	ldr	r4, [r3, #0]
	ldr	r5, [r3, #0]
	ldr	r6, [r3, #0]
	ldr	r7, [r3, #0]
	ldr	r2, [r3, #0]
	mov	r1, r1, lsr #1
	mov	r0, r0, lsr #5
	mov	ip, ip, lsr #4
	mov	lr, lr, lsr #6
	mov	r4, r4, lsr #7
	mov	r5, r5, lsr #3
	mov	r6, r6, lsr #2
	mov	r7, r7, lsr #9
	mov	r2, r2, lsr #8
	ldr	r3, .L12+4
	eor	r8, r8, #1
	eor	r1, r1, #1
	eor	r0, r0, #1
	eor	ip, ip, #1
	eor	lr, lr, #1
	eor	r4, r4, #1
	eor	r5, r5, #1
	eor	r6, r6, #1
	eor	r7, r7, #1
	eor	r2, r2, #1
	and	r8, r8, #1
	and	r1, r1, #1
	and	r0, r0, #1
	and	ip, ip, #1
	and	lr, lr, #1
	and	r4, r4, #1
	and	r5, r5, #1
	and	r6, r6, #1
	and	r7, r7, #1
	and	r2, r2, #1
	strh	r2, [r3, #18]	@ movhi 	@  buttons
	strh	r8, [r3, #0]	@ movhi 	@  buttons
	strh	r1, [r3, #2]	@ movhi 	@  buttons
	strh	r0, [r3, #4]	@ movhi 	@  buttons
	strh	ip, [r3, #6]	@ movhi 	@  buttons
	strh	lr, [r3, #8]	@ movhi 	@  buttons
	strh	r4, [r3, #10]	@ movhi 	@  buttons
	strh	r5, [r3, #12]	@ movhi 	@  buttons
	strh	r6, [r3, #14]	@ movhi 	@  buttons
	strh	r7, [r3, #16]	@ movhi 	@  buttons
	ldmfd	sp!, {r4, r5, r6, r7, r8, lr}
	bx	lr
.L13:
	.align	2
.L12:
	.word	BUTTONS
	.word	buttons
	.size	CheckButtons, .-CheckButtons
	.align	2
	.global	Pressed
	.type	Pressed, %function
Pressed:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	cmp	r0, #16	@  button
	ldreq	r3, .L31
	@ lr needed for prologue
	ldreqsh	r0, [r3, #6]	@  button,  buttons
	bxeq	lr
	bgt	.L28
	cmp	r0, #2	@  button
	ldreq	r3, .L31
	ldreqsh	r0, [r3, #2]	@  button,  buttons
	bxeq	lr
	bgt	.L29
	cmp	r0, #1	@  button
	ldreq	r3, .L31
	ldreqsh	r0, [r3, #0]	@  button,  buttons
	bxeq	lr
.L15:
	mov	r0, #0	@  button
	bx	lr
.L29:
	cmp	r0, #4	@  button
	ldreq	r3, .L31
	ldreqsh	r0, [r3, #14]	@  button,  buttons
	bxeq	lr
	cmp	r0, #8	@  button
	ldreq	r3, .L31
	ldreqsh	r0, [r3, #12]	@  button,  buttons
	bne	.L15
	bx	lr
.L28:
	cmp	r0, #128	@  button
	ldreq	r3, .L31
	ldreqsh	r0, [r3, #10]	@  button,  buttons
	bxeq	lr
	bgt	.L30
	cmp	r0, #32	@  button
	ldreq	r3, .L31
	ldreqsh	r0, [r3, #4]	@  button,  buttons
	bxeq	lr
	cmp	r0, #64	@  button
	ldreq	r3, .L31
	ldreqsh	r0, [r3, #8]	@  button,  buttons
	bne	.L15
	bx	lr
.L30:
	cmp	r0, #256	@  button
	ldreq	r3, .L31
	ldreqsh	r0, [r3, #18]	@  button,  buttons
	bxeq	lr
	cmp	r0, #512	@  button
	ldreq	r3, .L31
	ldreqsh	r0, [r3, #16]	@  button,  buttons
	bne	.L15
	bx	lr
.L32:
	.align	2
.L31:
	.word	buttons
	.size	Pressed, .-Pressed
	.align	2
	.global	activebutton
	.type	activebutton, %function
activebutton:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {r4, fp, ip, lr, pc}
	sub	fp, ip, #4
	mov	r4, r0	@  testbutton
.L45:
	bl	CheckButtons
	mov	r0, r4	@  testbutton
	bl	Pressed
	cmp	r0, #0	@  testbutton
	ldrne	r1, .L47
	movne	r2, #0	@  counter
	beq	.L46
.L41:
	mov	r3, r2, asl #1	@  counter
	add	r2, r2, #1	@  counter,  counter
	mov	r0, #0	@ movhi
	cmp	r2, #9	@  counter
	strh	r0, [r3, r1]	@ movhi 	@  buttons
	ble	.L41
	b	.L45
.L46:
	ldmea	fp, {r4, fp, sp, lr}
	bx	lr
.L48:
	.align	2
.L47:
	.word	buttons
	.size	activebutton, .-activebutton
	.global	solderData
	.section	.rodata
	.align	1
	.type	solderData, %object
	.size	solderData, 256
solderData:
	.short	0
	.short	0
	.short	0
	.short	-16449
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-7968
	.short	-26472
	.short	0
	.short	-8192
	.short	-26400
	.short	-26472
	.short	191
	.short	0
	.short	0
	.short	0
	.short	-16488
	.short	0
	.short	0
	.short	0
	.short	-16488
	.short	0
	.short	0
	.short	77
	.short	-16488
	.short	0
	.short	19712
	.short	77
	.short	-16640
	.short	0
	.short	19712
	.short	0
	.short	-16640
	.short	0
	.short	19712
	.short	0
	.short	-8040
	.short	224
	.short	19789
	.short	0
	.short	-26472
	.short	-7968
	.short	77
	.short	0
	.short	0
	.short	-8192
	.short	-26624
	.short	-26472
	.short	0
	.short	-8192
	.short	-26624
	.short	-26472
	.short	0
	.short	0
	.short	-26624
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	-26624
	.short	152
	.short	-26472
	.short	-8192
	.short	77
	.short	0
	.short	-26472
	.short	19712
	.short	77
	.short	0
	.short	-26472
	.short	19712
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.global	solderPalette
	.align	1
	.type	solderPalette, %object
	.size	solderPalette, 512
solderPalette:
	.short	0
	.short	16
	.short	512
	.short	528
	.short	16384
	.short	16400
	.short	16896
	.short	25368
	.short	25464
	.short	31540
	.short	136
	.short	140
	.short	144
	.short	148
	.short	152
	.short	156
	.short	256
	.short	260
	.short	264
	.short	268
	.short	272
	.short	276
	.short	280
	.short	284
	.short	384
	.short	388
	.short	392
	.short	396
	.short	400
	.short	404
	.short	408
	.short	412
	.short	512
	.short	516
	.short	520
	.short	524
	.short	528
	.short	532
	.short	536
	.short	540
	.short	640
	.short	644
	.short	648
	.short	652
	.short	656
	.short	660
	.short	664
	.short	668
	.short	768
	.short	772
	.short	776
	.short	780
	.short	784
	.short	788
	.short	792
	.short	796
	.short	896
	.short	900
	.short	904
	.short	908
	.short	912
	.short	916
	.short	920
	.short	924
	.short	8192
	.short	8196
	.short	8200
	.short	8204
	.short	8208
	.short	8212
	.short	8216
	.short	8220
	.short	8320
	.short	8324
	.short	8328
	.short	8332
	.short	8336
	.short	8340
	.short	8344
	.short	8348
	.short	8448
	.short	8452
	.short	8456
	.short	8460
	.short	8464
	.short	8468
	.short	8472
	.short	8476
	.short	8576
	.short	8580
	.short	8584
	.short	8588
	.short	8592
	.short	8596
	.short	8600
	.short	8604
	.short	8704
	.short	8708
	.short	8712
	.short	8716
	.short	8720
	.short	8724
	.short	8728
	.short	8732
	.short	8832
	.short	8836
	.short	8840
	.short	8844
	.short	8848
	.short	8852
	.short	8856
	.short	8860
	.short	8960
	.short	8964
	.short	8968
	.short	8972
	.short	8976
	.short	8980
	.short	8984
	.short	8988
	.short	9088
	.short	9092
	.short	9096
	.short	9100
	.short	9104
	.short	9108
	.short	9112
	.short	9116
	.short	16384
	.short	16388
	.short	16392
	.short	16396
	.short	16400
	.short	16404
	.short	16408
	.short	16412
	.short	16512
	.short	16516
	.short	16520
	.short	16524
	.short	16528
	.short	16532
	.short	16536
	.short	16540
	.short	16640
	.short	16644
	.short	16648
	.short	16652
	.short	16656
	.short	16660
	.short	16664
	.short	16668
	.short	16768
	.short	16772
	.short	16776
	.short	16780
	.short	16784
	.short	16788
	.short	16792
	.short	16796
	.short	16896
	.short	16900
	.short	16904
	.short	16908
	.short	16912
	.short	16916
	.short	16920
	.short	16924
	.short	17024
	.short	17028
	.short	17032
	.short	17036
	.short	17040
	.short	17044
	.short	17048
	.short	17052
	.short	17152
	.short	17156
	.short	17160
	.short	17164
	.short	17168
	.short	17172
	.short	17176
	.short	17180
	.short	17280
	.short	17284
	.short	17288
	.short	17292
	.short	17296
	.short	17300
	.short	17304
	.short	17308
	.short	24576
	.short	24580
	.short	24584
	.short	24588
	.short	24592
	.short	24596
	.short	24600
	.short	24604
	.short	24704
	.short	24708
	.short	24712
	.short	24716
	.short	24720
	.short	24724
	.short	24728
	.short	24732
	.short	24832
	.short	24836
	.short	24840
	.short	24844
	.short	24848
	.short	24852
	.short	24856
	.short	24860
	.short	24960
	.short	24964
	.short	24968
	.short	24972
	.short	24976
	.short	24980
	.short	24984
	.short	24988
	.short	25088
	.short	25092
	.short	25096
	.short	25100
	.short	25104
	.short	25108
	.short	25112
	.short	25116
	.short	25216
	.short	25220
	.short	25224
	.short	25228
	.short	25232
	.short	25236
	.short	25240
	.short	25244
	.short	25344
	.short	25348
	.short	25352
	.short	25356
	.short	25360
	.short	25364
	.short	31743
	.short	21140
	.short	16912
	.short	31
	.short	992
	.short	1023
	.short	31744
	.short	31775
	.short	32736
	.short	32767
	.global	solder2Data
	.align	1
	.type	solder2Data, %object
	.size	solder2Data, 256
solder2Data:
	.short	0
	.short	0
	.short	0
	.short	-16449
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-7968
	.short	-26472
	.short	0
	.short	-8192
	.short	-26400
	.short	-26472
	.short	191
	.short	0
	.short	0
	.short	0
	.short	-16488
	.short	0
	.short	0
	.short	0
	.short	-16488
	.short	0
	.short	0
	.short	77
	.short	-16488
	.short	0
	.short	19712
	.short	77
	.short	-16640
	.short	0
	.short	19712
	.short	0
	.short	-16640
	.short	0
	.short	19712
	.short	0
	.short	-8040
	.short	224
	.short	19789
	.short	0
	.short	-26472
	.short	-7968
	.short	77
	.short	0
	.short	0
	.short	-8192
	.short	-26624
	.short	-26472
	.short	0
	.short	-8192
	.short	-26624
	.short	-26472
	.short	0
	.short	0
	.short	-26624
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	-26472
	.short	-8192
	.short	77
	.short	0
	.short	-26472
	.short	19712
	.short	77
	.short	0
	.short	-26472
	.short	19712
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.global	solder2Palette
	.align	1
	.type	solder2Palette, %object
	.size	solder2Palette, 512
solder2Palette:
	.short	0
	.short	16
	.short	512
	.short	528
	.short	16384
	.short	16400
	.short	16896
	.short	25368
	.short	25464
	.short	31540
	.short	136
	.short	140
	.short	144
	.short	148
	.short	152
	.short	156
	.short	256
	.short	260
	.short	264
	.short	268
	.short	272
	.short	276
	.short	280
	.short	284
	.short	384
	.short	388
	.short	392
	.short	396
	.short	400
	.short	404
	.short	408
	.short	412
	.short	512
	.short	516
	.short	520
	.short	524
	.short	528
	.short	532
	.short	536
	.short	540
	.short	640
	.short	644
	.short	648
	.short	652
	.short	656
	.short	660
	.short	664
	.short	668
	.short	768
	.short	772
	.short	776
	.short	780
	.short	784
	.short	788
	.short	792
	.short	796
	.short	896
	.short	900
	.short	904
	.short	908
	.short	912
	.short	916
	.short	920
	.short	924
	.short	8192
	.short	8196
	.short	8200
	.short	8204
	.short	8208
	.short	8212
	.short	8216
	.short	8220
	.short	8320
	.short	8324
	.short	8328
	.short	8332
	.short	8336
	.short	8340
	.short	8344
	.short	8348
	.short	8448
	.short	8452
	.short	8456
	.short	8460
	.short	8464
	.short	8468
	.short	8472
	.short	8476
	.short	8576
	.short	8580
	.short	8584
	.short	8588
	.short	8592
	.short	8596
	.short	8600
	.short	8604
	.short	8704
	.short	8708
	.short	8712
	.short	8716
	.short	8720
	.short	8724
	.short	8728
	.short	8732
	.short	8832
	.short	8836
	.short	8840
	.short	8844
	.short	8848
	.short	8852
	.short	8856
	.short	8860
	.short	8960
	.short	8964
	.short	8968
	.short	8972
	.short	8976
	.short	8980
	.short	8984
	.short	8988
	.short	9088
	.short	9092
	.short	9096
	.short	9100
	.short	9104
	.short	9108
	.short	9112
	.short	9116
	.short	16384
	.short	16388
	.short	16392
	.short	16396
	.short	16400
	.short	16404
	.short	16408
	.short	16412
	.short	16512
	.short	16516
	.short	16520
	.short	16524
	.short	16528
	.short	16532
	.short	16536
	.short	16540
	.short	16640
	.short	16644
	.short	16648
	.short	16652
	.short	16656
	.short	16660
	.short	16664
	.short	16668
	.short	16768
	.short	16772
	.short	16776
	.short	16780
	.short	16784
	.short	16788
	.short	16792
	.short	16796
	.short	16896
	.short	16900
	.short	16904
	.short	16908
	.short	16912
	.short	16916
	.short	16920
	.short	16924
	.short	17024
	.short	17028
	.short	17032
	.short	17036
	.short	17040
	.short	17044
	.short	17048
	.short	17052
	.short	17152
	.short	17156
	.short	17160
	.short	17164
	.short	17168
	.short	17172
	.short	17176
	.short	17180
	.short	17280
	.short	17284
	.short	17288
	.short	17292
	.short	17296
	.short	17300
	.short	17304
	.short	17308
	.short	24576
	.short	24580
	.short	24584
	.short	24588
	.short	24592
	.short	24596
	.short	24600
	.short	24604
	.short	24704
	.short	24708
	.short	24712
	.short	24716
	.short	24720
	.short	24724
	.short	24728
	.short	24732
	.short	24832
	.short	24836
	.short	24840
	.short	24844
	.short	24848
	.short	24852
	.short	24856
	.short	24860
	.short	24960
	.short	24964
	.short	24968
	.short	24972
	.short	24976
	.short	24980
	.short	24984
	.short	24988
	.short	25088
	.short	25092
	.short	25096
	.short	25100
	.short	25104
	.short	25108
	.short	25112
	.short	25116
	.short	25216
	.short	25220
	.short	25224
	.short	25228
	.short	25232
	.short	25236
	.short	25240
	.short	25244
	.short	25344
	.short	25348
	.short	25352
	.short	25356
	.short	25360
	.short	25364
	.short	31743
	.short	21140
	.short	16912
	.short	31
	.short	992
	.short	1023
	.short	31744
	.short	31775
	.short	32736
	.short	32767
	.global	solder3Data
	.align	1
	.type	solder3Data, %object
	.size	solder3Data, 256
solder3Data:
	.short	0
	.short	0
	.short	0
	.short	-16449
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-7968
	.short	-26472
	.short	0
	.short	-8192
	.short	-26400
	.short	-26472
	.short	191
	.short	0
	.short	0
	.short	0
	.short	-16488
	.short	0
	.short	0
	.short	0
	.short	-16488
	.short	0
	.short	0
	.short	77
	.short	-16488
	.short	0
	.short	19712
	.short	77
	.short	-16640
	.short	0
	.short	19712
	.short	0
	.short	-16640
	.short	0
	.short	19712
	.short	0
	.short	-8040
	.short	224
	.short	19789
	.short	0
	.short	-26472
	.short	-7968
	.short	77
	.short	0
	.short	0
	.short	-8192
	.short	-26624
	.short	-26472
	.short	0
	.short	-8192
	.short	-26624
	.short	-26472
	.short	0
	.short	0
	.short	-26624
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	-8192
	.short	77
	.short	0
	.short	-26472
	.short	19712
	.short	77
	.short	0
	.short	-26472
	.short	19712
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.global	solder3Palette
	.align	1
	.type	solder3Palette, %object
	.size	solder3Palette, 512
solder3Palette:
	.short	0
	.short	16
	.short	512
	.short	528
	.short	16384
	.short	16400
	.short	16896
	.short	25368
	.short	25464
	.short	31540
	.short	136
	.short	140
	.short	144
	.short	148
	.short	152
	.short	156
	.short	256
	.short	260
	.short	264
	.short	268
	.short	272
	.short	276
	.short	280
	.short	284
	.short	384
	.short	388
	.short	392
	.short	396
	.short	400
	.short	404
	.short	408
	.short	412
	.short	512
	.short	516
	.short	520
	.short	524
	.short	528
	.short	532
	.short	536
	.short	540
	.short	640
	.short	644
	.short	648
	.short	652
	.short	656
	.short	660
	.short	664
	.short	668
	.short	768
	.short	772
	.short	776
	.short	780
	.short	784
	.short	788
	.short	792
	.short	796
	.short	896
	.short	900
	.short	904
	.short	908
	.short	912
	.short	916
	.short	920
	.short	924
	.short	8192
	.short	8196
	.short	8200
	.short	8204
	.short	8208
	.short	8212
	.short	8216
	.short	8220
	.short	8320
	.short	8324
	.short	8328
	.short	8332
	.short	8336
	.short	8340
	.short	8344
	.short	8348
	.short	8448
	.short	8452
	.short	8456
	.short	8460
	.short	8464
	.short	8468
	.short	8472
	.short	8476
	.short	8576
	.short	8580
	.short	8584
	.short	8588
	.short	8592
	.short	8596
	.short	8600
	.short	8604
	.short	8704
	.short	8708
	.short	8712
	.short	8716
	.short	8720
	.short	8724
	.short	8728
	.short	8732
	.short	8832
	.short	8836
	.short	8840
	.short	8844
	.short	8848
	.short	8852
	.short	8856
	.short	8860
	.short	8960
	.short	8964
	.short	8968
	.short	8972
	.short	8976
	.short	8980
	.short	8984
	.short	8988
	.short	9088
	.short	9092
	.short	9096
	.short	9100
	.short	9104
	.short	9108
	.short	9112
	.short	9116
	.short	16384
	.short	16388
	.short	16392
	.short	16396
	.short	16400
	.short	16404
	.short	16408
	.short	16412
	.short	16512
	.short	16516
	.short	16520
	.short	16524
	.short	16528
	.short	16532
	.short	16536
	.short	16540
	.short	16640
	.short	16644
	.short	16648
	.short	16652
	.short	16656
	.short	16660
	.short	16664
	.short	16668
	.short	16768
	.short	16772
	.short	16776
	.short	16780
	.short	16784
	.short	16788
	.short	16792
	.short	16796
	.short	16896
	.short	16900
	.short	16904
	.short	16908
	.short	16912
	.short	16916
	.short	16920
	.short	16924
	.short	17024
	.short	17028
	.short	17032
	.short	17036
	.short	17040
	.short	17044
	.short	17048
	.short	17052
	.short	17152
	.short	17156
	.short	17160
	.short	17164
	.short	17168
	.short	17172
	.short	17176
	.short	17180
	.short	17280
	.short	17284
	.short	17288
	.short	17292
	.short	17296
	.short	17300
	.short	17304
	.short	17308
	.short	24576
	.short	24580
	.short	24584
	.short	24588
	.short	24592
	.short	24596
	.short	24600
	.short	24604
	.short	24704
	.short	24708
	.short	24712
	.short	24716
	.short	24720
	.short	24724
	.short	24728
	.short	24732
	.short	24832
	.short	24836
	.short	24840
	.short	24844
	.short	24848
	.short	24852
	.short	24856
	.short	24860
	.short	24960
	.short	24964
	.short	24968
	.short	24972
	.short	24976
	.short	24980
	.short	24984
	.short	24988
	.short	25088
	.short	25092
	.short	25096
	.short	25100
	.short	25104
	.short	25108
	.short	25112
	.short	25116
	.short	25216
	.short	25220
	.short	25224
	.short	25228
	.short	25232
	.short	25236
	.short	25240
	.short	25244
	.short	25344
	.short	25348
	.short	25352
	.short	25356
	.short	25360
	.short	25364
	.short	31743
	.short	21140
	.short	16912
	.short	31
	.short	992
	.short	1023
	.short	31744
	.short	31775
	.short	32736
	.short	32767
	.global	solder4Data
	.align	1
	.type	solder4Data, %object
	.size	solder4Data, 256
solder4Data:
	.short	0
	.short	0
	.short	0
	.short	-16449
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-7968
	.short	-26472
	.short	0
	.short	-8192
	.short	-26400
	.short	-26472
	.short	191
	.short	0
	.short	0
	.short	0
	.short	-16488
	.short	0
	.short	0
	.short	0
	.short	-16488
	.short	0
	.short	0
	.short	0
	.short	-16488
	.short	0
	.short	0
	.short	0
	.short	-16640
	.short	0
	.short	0
	.short	0
	.short	-16640
	.short	0
	.short	19712
	.short	0
	.short	-8040
	.short	0
	.short	77
	.short	0
	.short	-26472
	.short	19936
	.short	0
	.short	0
	.short	0
	.short	-8192
	.short	-26624
	.short	-26472
	.short	0
	.short	-8192
	.short	-26624
	.short	-26472
	.short	0
	.short	0
	.short	-26624
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	-26472
	.short	-8192
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.global	solder4Palette
	.align	1
	.type	solder4Palette, %object
	.size	solder4Palette, 512
solder4Palette:
	.short	0
	.short	16
	.short	512
	.short	528
	.short	16384
	.short	16400
	.short	16896
	.short	25368
	.short	25464
	.short	31540
	.short	136
	.short	140
	.short	144
	.short	148
	.short	152
	.short	156
	.short	256
	.short	260
	.short	264
	.short	268
	.short	272
	.short	276
	.short	280
	.short	284
	.short	384
	.short	388
	.short	392
	.short	396
	.short	400
	.short	404
	.short	408
	.short	412
	.short	512
	.short	516
	.short	520
	.short	524
	.short	528
	.short	532
	.short	536
	.short	540
	.short	640
	.short	644
	.short	648
	.short	652
	.short	656
	.short	660
	.short	664
	.short	668
	.short	768
	.short	772
	.short	776
	.short	780
	.short	784
	.short	788
	.short	792
	.short	796
	.short	896
	.short	900
	.short	904
	.short	908
	.short	912
	.short	916
	.short	920
	.short	924
	.short	8192
	.short	8196
	.short	8200
	.short	8204
	.short	8208
	.short	8212
	.short	8216
	.short	8220
	.short	8320
	.short	8324
	.short	8328
	.short	8332
	.short	8336
	.short	8340
	.short	8344
	.short	8348
	.short	8448
	.short	8452
	.short	8456
	.short	8460
	.short	8464
	.short	8468
	.short	8472
	.short	8476
	.short	8576
	.short	8580
	.short	8584
	.short	8588
	.short	8592
	.short	8596
	.short	8600
	.short	8604
	.short	8704
	.short	8708
	.short	8712
	.short	8716
	.short	8720
	.short	8724
	.short	8728
	.short	8732
	.short	8832
	.short	8836
	.short	8840
	.short	8844
	.short	8848
	.short	8852
	.short	8856
	.short	8860
	.short	8960
	.short	8964
	.short	8968
	.short	8972
	.short	8976
	.short	8980
	.short	8984
	.short	8988
	.short	9088
	.short	9092
	.short	9096
	.short	9100
	.short	9104
	.short	9108
	.short	9112
	.short	9116
	.short	16384
	.short	16388
	.short	16392
	.short	16396
	.short	16400
	.short	16404
	.short	16408
	.short	16412
	.short	16512
	.short	16516
	.short	16520
	.short	16524
	.short	16528
	.short	16532
	.short	16536
	.short	16540
	.short	16640
	.short	16644
	.short	16648
	.short	16652
	.short	16656
	.short	16660
	.short	16664
	.short	16668
	.short	16768
	.short	16772
	.short	16776
	.short	16780
	.short	16784
	.short	16788
	.short	16792
	.short	16796
	.short	16896
	.short	16900
	.short	16904
	.short	16908
	.short	16912
	.short	16916
	.short	16920
	.short	16924
	.short	17024
	.short	17028
	.short	17032
	.short	17036
	.short	17040
	.short	17044
	.short	17048
	.short	17052
	.short	17152
	.short	17156
	.short	17160
	.short	17164
	.short	17168
	.short	17172
	.short	17176
	.short	17180
	.short	17280
	.short	17284
	.short	17288
	.short	17292
	.short	17296
	.short	17300
	.short	17304
	.short	17308
	.short	24576
	.short	24580
	.short	24584
	.short	24588
	.short	24592
	.short	24596
	.short	24600
	.short	24604
	.short	24704
	.short	24708
	.short	24712
	.short	24716
	.short	24720
	.short	24724
	.short	24728
	.short	24732
	.short	24832
	.short	24836
	.short	24840
	.short	24844
	.short	24848
	.short	24852
	.short	24856
	.short	24860
	.short	24960
	.short	24964
	.short	24968
	.short	24972
	.short	24976
	.short	24980
	.short	24984
	.short	24988
	.short	25088
	.short	25092
	.short	25096
	.short	25100
	.short	25104
	.short	25108
	.short	25112
	.short	25116
	.short	25216
	.short	25220
	.short	25224
	.short	25228
	.short	25232
	.short	25236
	.short	25240
	.short	25244
	.short	25344
	.short	25348
	.short	25352
	.short	25356
	.short	25360
	.short	25364
	.short	31743
	.short	21140
	.short	16912
	.short	31
	.short	992
	.short	1023
	.short	31744
	.short	31775
	.short	32736
	.short	32767
	.global	solder5Data
	.align	1
	.type	solder5Data, %object
	.size	solder5Data, 256
solder5Data:
	.short	0
	.short	0
	.short	0
	.short	-16449
	.short	0
	.short	0
	.short	-16640
	.short	-16449
	.short	0
	.short	0
	.short	-16640
	.short	-26433
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	0
	.short	-8040
	.short	0
	.short	0
	.short	0
	.short	-8040
	.short	191
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	77
	.short	0
	.short	152
	.short	19712
	.short	77
	.short	0
	.short	0
	.short	0
	.short	0
	.short	-8040
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	224
	.short	19789
	.short	0
	.short	0
	.short	19936
	.short	77
	.short	0
	.short	0
	.short	19864
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.global	solder5Palette
	.align	1
	.type	solder5Palette, %object
	.size	solder5Palette, 512
solder5Palette:
	.short	0
	.short	16
	.short	512
	.short	528
	.short	16384
	.short	16400
	.short	16896
	.short	25368
	.short	25464
	.short	31540
	.short	136
	.short	140
	.short	144
	.short	148
	.short	152
	.short	156
	.short	256
	.short	260
	.short	264
	.short	268
	.short	272
	.short	276
	.short	280
	.short	284
	.short	384
	.short	388
	.short	392
	.short	396
	.short	400
	.short	404
	.short	408
	.short	412
	.short	512
	.short	516
	.short	520
	.short	524
	.short	528
	.short	532
	.short	536
	.short	540
	.short	640
	.short	644
	.short	648
	.short	652
	.short	656
	.short	660
	.short	664
	.short	668
	.short	768
	.short	772
	.short	776
	.short	780
	.short	784
	.short	788
	.short	792
	.short	796
	.short	896
	.short	900
	.short	904
	.short	908
	.short	912
	.short	916
	.short	920
	.short	924
	.short	8192
	.short	8196
	.short	8200
	.short	8204
	.short	8208
	.short	8212
	.short	8216
	.short	8220
	.short	8320
	.short	8324
	.short	8328
	.short	8332
	.short	8336
	.short	8340
	.short	8344
	.short	8348
	.short	8448
	.short	8452
	.short	8456
	.short	8460
	.short	8464
	.short	8468
	.short	8472
	.short	8476
	.short	8576
	.short	8580
	.short	8584
	.short	8588
	.short	8592
	.short	8596
	.short	8600
	.short	8604
	.short	8704
	.short	8708
	.short	8712
	.short	8716
	.short	8720
	.short	8724
	.short	8728
	.short	8732
	.short	8832
	.short	8836
	.short	8840
	.short	8844
	.short	8848
	.short	8852
	.short	8856
	.short	8860
	.short	8960
	.short	8964
	.short	8968
	.short	8972
	.short	8976
	.short	8980
	.short	8984
	.short	8988
	.short	9088
	.short	9092
	.short	9096
	.short	9100
	.short	9104
	.short	9108
	.short	9112
	.short	9116
	.short	16384
	.short	16388
	.short	16392
	.short	16396
	.short	16400
	.short	16404
	.short	16408
	.short	16412
	.short	16512
	.short	16516
	.short	16520
	.short	16524
	.short	16528
	.short	16532
	.short	16536
	.short	16540
	.short	16640
	.short	16644
	.short	16648
	.short	16652
	.short	16656
	.short	16660
	.short	16664
	.short	16668
	.short	16768
	.short	16772
	.short	16776
	.short	16780
	.short	16784
	.short	16788
	.short	16792
	.short	16796
	.short	16896
	.short	16900
	.short	16904
	.short	16908
	.short	16912
	.short	16916
	.short	16920
	.short	16924
	.short	17024
	.short	17028
	.short	17032
	.short	17036
	.short	17040
	.short	17044
	.short	17048
	.short	17052
	.short	17152
	.short	17156
	.short	17160
	.short	17164
	.short	17168
	.short	17172
	.short	17176
	.short	17180
	.short	17280
	.short	17284
	.short	17288
	.short	17292
	.short	17296
	.short	17300
	.short	17304
	.short	17308
	.short	24576
	.short	24580
	.short	24584
	.short	24588
	.short	24592
	.short	24596
	.short	24600
	.short	24604
	.short	24704
	.short	24708
	.short	24712
	.short	24716
	.short	24720
	.short	24724
	.short	24728
	.short	24732
	.short	24832
	.short	24836
	.short	24840
	.short	24844
	.short	24848
	.short	24852
	.short	24856
	.short	24860
	.short	24960
	.short	24964
	.short	24968
	.short	24972
	.short	24976
	.short	24980
	.short	24984
	.short	24988
	.short	25088
	.short	25092
	.short	25096
	.short	25100
	.short	25104
	.short	25108
	.short	25112
	.short	25116
	.short	25216
	.short	25220
	.short	25224
	.short	25228
	.short	25232
	.short	25236
	.short	25240
	.short	25244
	.short	25344
	.short	25348
	.short	25352
	.short	25356
	.short	25360
	.short	25364
	.short	31743
	.short	21140
	.short	16912
	.short	31
	.short	992
	.short	1023
	.short	31744
	.short	31775
	.short	32736
	.short	32767
	.global	solder6Data
	.align	1
	.type	solder6Data, %object
	.size	solder6Data, 256
solder6Data:
	.short	0
	.short	0
	.short	0
	.short	-16449
	.short	0
	.short	0
	.short	-16640
	.short	-16449
	.short	0
	.short	0
	.short	-16640
	.short	-26433
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	0
	.short	-8040
	.short	0
	.short	0
	.short	0
	.short	-8040
	.short	191
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	19712
	.short	0
	.short	0
	.short	152
	.short	19789
	.short	0
	.short	0
	.short	19864
	.short	77
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	19936
	.short	0
	.short	0
	.short	-8192
	.short	19789
	.short	0
	.short	0
	.short	19712
	.short	-26547
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	19789
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	-26624
	.short	152
	.short	0
	.short	0
	.global	solder6Palette
	.align	1
	.type	solder6Palette, %object
	.size	solder6Palette, 512
solder6Palette:
	.short	0
	.short	16
	.short	512
	.short	528
	.short	16384
	.short	16400
	.short	16896
	.short	25368
	.short	25464
	.short	31540
	.short	136
	.short	140
	.short	144
	.short	148
	.short	152
	.short	156
	.short	256
	.short	260
	.short	264
	.short	268
	.short	272
	.short	276
	.short	280
	.short	284
	.short	384
	.short	388
	.short	392
	.short	396
	.short	400
	.short	404
	.short	408
	.short	412
	.short	512
	.short	516
	.short	520
	.short	524
	.short	528
	.short	532
	.short	536
	.short	540
	.short	640
	.short	644
	.short	648
	.short	652
	.short	656
	.short	660
	.short	664
	.short	668
	.short	768
	.short	772
	.short	776
	.short	780
	.short	784
	.short	788
	.short	792
	.short	796
	.short	896
	.short	900
	.short	904
	.short	908
	.short	912
	.short	916
	.short	920
	.short	924
	.short	8192
	.short	8196
	.short	8200
	.short	8204
	.short	8208
	.short	8212
	.short	8216
	.short	8220
	.short	8320
	.short	8324
	.short	8328
	.short	8332
	.short	8336
	.short	8340
	.short	8344
	.short	8348
	.short	8448
	.short	8452
	.short	8456
	.short	8460
	.short	8464
	.short	8468
	.short	8472
	.short	8476
	.short	8576
	.short	8580
	.short	8584
	.short	8588
	.short	8592
	.short	8596
	.short	8600
	.short	8604
	.short	8704
	.short	8708
	.short	8712
	.short	8716
	.short	8720
	.short	8724
	.short	8728
	.short	8732
	.short	8832
	.short	8836
	.short	8840
	.short	8844
	.short	8848
	.short	8852
	.short	8856
	.short	8860
	.short	8960
	.short	8964
	.short	8968
	.short	8972
	.short	8976
	.short	8980
	.short	8984
	.short	8988
	.short	9088
	.short	9092
	.short	9096
	.short	9100
	.short	9104
	.short	9108
	.short	9112
	.short	9116
	.short	16384
	.short	16388
	.short	16392
	.short	16396
	.short	16400
	.short	16404
	.short	16408
	.short	16412
	.short	16512
	.short	16516
	.short	16520
	.short	16524
	.short	16528
	.short	16532
	.short	16536
	.short	16540
	.short	16640
	.short	16644
	.short	16648
	.short	16652
	.short	16656
	.short	16660
	.short	16664
	.short	16668
	.short	16768
	.short	16772
	.short	16776
	.short	16780
	.short	16784
	.short	16788
	.short	16792
	.short	16796
	.short	16896
	.short	16900
	.short	16904
	.short	16908
	.short	16912
	.short	16916
	.short	16920
	.short	16924
	.short	17024
	.short	17028
	.short	17032
	.short	17036
	.short	17040
	.short	17044
	.short	17048
	.short	17052
	.short	17152
	.short	17156
	.short	17160
	.short	17164
	.short	17168
	.short	17172
	.short	17176
	.short	17180
	.short	17280
	.short	17284
	.short	17288
	.short	17292
	.short	17296
	.short	17300
	.short	17304
	.short	17308
	.short	24576
	.short	24580
	.short	24584
	.short	24588
	.short	24592
	.short	24596
	.short	24600
	.short	24604
	.short	24704
	.short	24708
	.short	24712
	.short	24716
	.short	24720
	.short	24724
	.short	24728
	.short	24732
	.short	24832
	.short	24836
	.short	24840
	.short	24844
	.short	24848
	.short	24852
	.short	24856
	.short	24860
	.short	24960
	.short	24964
	.short	24968
	.short	24972
	.short	24976
	.short	24980
	.short	24984
	.short	24988
	.short	25088
	.short	25092
	.short	25096
	.short	25100
	.short	25104
	.short	25108
	.short	25112
	.short	25116
	.short	25216
	.short	25220
	.short	25224
	.short	25228
	.short	25232
	.short	25236
	.short	25240
	.short	25244
	.short	25344
	.short	25348
	.short	25352
	.short	25356
	.short	25360
	.short	25364
	.short	31743
	.short	21140
	.short	16912
	.short	31
	.short	992
	.short	1023
	.short	31744
	.short	31775
	.short	32736
	.short	32767
	.global	solder7Data
	.align	1
	.type	solder7Data, %object
	.size	solder7Data, 256
solder7Data:
	.short	0
	.short	0
	.short	0
	.short	-16449
	.short	0
	.short	0
	.short	-16640
	.short	-16449
	.short	0
	.short	0
	.short	-16640
	.short	-26433
	.short	0
	.short	0
	.short	-16640
	.short	-26472
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	-16640
	.short	-26624
	.short	0
	.short	0
	.short	0
	.short	-8040
	.short	0
	.short	0
	.short	0
	.short	-8040
	.short	191
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	0
	.short	19712
	.short	152
	.short	0
	.short	0
	.short	19789
	.short	224
	.short	0
	.short	19789
	.short	77
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	-7968
	.short	19789
	.short	77
	.short	0
	.short	152
	.short	19936
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	152
	.short	0
	.short	0
	.short	0
	.short	-26472
	.short	0
	.short	0
	.short	0
	.short	-26624
	.short	152
	.short	0
	.short	0
	.global	solder7Palette
	.align	1
	.type	solder7Palette, %object
	.size	solder7Palette, 512
solder7Palette:
	.short	0
	.short	16
	.short	512
	.short	528
	.short	16384
	.short	16400
	.short	16896
	.short	25368
	.short	25464
	.short	31540
	.short	136
	.short	140
	.short	144
	.short	148
	.short	152
	.short	156
	.short	256
	.short	260
	.short	264
	.short	268
	.short	272
	.short	276
	.short	280
	.short	284
	.short	384
	.short	388
	.short	392
	.short	396
	.short	400
	.short	404
	.short	408
	.short	412
	.short	512
	.short	516
	.short	520
	.short	524
	.short	528
	.short	532
	.short	536
	.short	540
	.short	640
	.short	644
	.short	648
	.short	652
	.short	656
	.short	660
	.short	664
	.short	668
	.short	768
	.short	772
	.short	776
	.short	780
	.short	784
	.short	788
	.short	792
	.short	796
	.short	896
	.short	900
	.short	904
	.short	908
	.short	912
	.short	916
	.short	920
	.short	924
	.short	8192
	.short	8196
	.short	8200
	.short	8204
	.short	8208
	.short	8212
	.short	8216
	.short	8220
	.short	8320
	.short	8324
	.short	8328
	.short	8332
	.short	8336
	.short	8340
	.short	8344
	.short	8348
	.short	8448
	.short	8452
	.short	8456
	.short	8460
	.short	8464
	.short	8468
	.short	8472
	.short	8476
	.short	8576
	.short	8580
	.short	8584
	.short	8588
	.short	8592
	.short	8596
	.short	8600
	.short	8604
	.short	8704
	.short	8708
	.short	8712
	.short	8716
	.short	8720
	.short	8724
	.short	8728
	.short	8732
	.short	8832
	.short	8836
	.short	8840
	.short	8844
	.short	8848
	.short	8852
	.short	8856
	.short	8860
	.short	8960
	.short	8964
	.short	8968
	.short	8972
	.short	8976
	.short	8980
	.short	8984
	.short	8988
	.short	9088
	.short	9092
	.short	9096
	.short	9100
	.short	9104
	.short	9108
	.short	9112
	.short	9116
	.short	16384
	.short	16388
	.short	16392
	.short	16396
	.short	16400
	.short	16404
	.short	16408
	.short	16412
	.short	16512
	.short	16516
	.short	16520
	.short	16524
	.short	16528
	.short	16532
	.short	16536
	.short	16540
	.short	16640
	.short	16644
	.short	16648
	.short	16652
	.short	16656
	.short	16660
	.short	16664
	.short	16668
	.short	16768
	.short	16772
	.short	16776
	.short	16780
	.short	16784
	.short	16788
	.short	16792
	.short	16796
	.short	16896
	.short	16900
	.short	16904
	.short	16908
	.short	16912
	.short	16916
	.short	16920
	.short	16924
	.short	17024
	.short	17028
	.short	17032
	.short	17036
	.short	17040
	.short	17044
	.short	17048
	.short	17052
	.short	17152
	.short	17156
	.short	17160
	.short	17164
	.short	17168
	.short	17172
	.short	17176
	.short	17180
	.short	17280
	.short	17284
	.short	17288
	.short	17292
	.short	17296
	.short	17300
	.short	17304
	.short	17308
	.short	24576
	.short	24580
	.short	24584
	.short	24588
	.short	24592
	.short	24596
	.short	24600
	.short	24604
	.short	24704
	.short	24708
	.short	24712
	.short	24716
	.short	24720
	.short	24724
	.short	24728
	.short	24732
	.short	24832
	.short	24836
	.short	24840
	.short	24844
	.short	24848
	.short	24852
	.short	24856
	.short	24860
	.short	24960
	.short	24964
	.short	24968
	.short	24972
	.short	24976
	.short	24980
	.short	24984
	.short	24988
	.short	25088
	.short	25092
	.short	25096
	.short	25100
	.short	25104
	.short	25108
	.short	25112
	.short	25116
	.short	25216
	.short	25220
	.short	25224
	.short	25228
	.short	25232
	.short	25236
	.short	25240
	.short	25244
	.short	25344
	.short	25348
	.short	25352
	.short	25356
	.short	25360
	.short	25364
	.short	31743
	.short	21140
	.short	16912
	.short	31
	.short	992
	.short	1023
	.short	31744
	.short	31775
	.short	32736
	.short	32767
	.global	checka
	.bss
	.global	checka
	.align	2
	.type	checka, %object
	.size	checka, 4
checka:
	.space	4
	.text
	.align	2
	.global	easySprites
	.type	easySprites, %function
easySprites:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {r4, r5, r6, r7, r8, fp, ip, lr, pc}
	ldr	r3, .L57
	sub	fp, ip, #4
	ldr	r0, .L57+4
	mov	r5, #0	@  count
	mov	lr, pc
	bx	r3
	ldr	r4, .L57+8
	mov	r0, r5	@  count
	ldr	r1, .L57+12
	mov	lr, pc
	bx	r4
	mov	r0, #1
	ldr	r1, .L57+16
	mov	lr, pc
	bx	r4
	mov	r0, #2
	ldr	r1, .L57+20
	mov	lr, pc
	bx	r4
	mov	r0, #3
	ldr	r1, .L57+24
	mov	lr, pc
	bx	r4
	mov	r0, #4
	ldr	r1, .L57+28
	mov	lr, pc
	bx	r4
	mov	r0, #5
	ldr	r1, .L57+32
	mov	lr, pc
	bx	r4
	mov	r0, #6
	ldr	r1, .L57+36
	mov	lr, pc
	bx	r4
	mov	r7, #8384
	mov	r6, #16384
	ldr	r8, .L57+40
	ldr	r4, .L57+44
	add	r7, r7, #48
	add	r6, r6, #160
.L54:
	mov	r0, r5	@  count
	mov	lr, pc
	bx	r8
	mov	r2, r5, asl #3	@  count
	add	r5, r5, #1	@  count,  count
	add	r3, r2, r4
	strh	r7, [r2, r4]	@ movhi 	@  <variable>.attribute0
	cmp	r5, #127	@  count
	mov	r2, #0	@ movhi
	strh	r2, [r3, #4]	@ movhi 	@  <variable>.attribute2
	strh	r6, [r3, #2]	@ movhi 	@  <variable>.attribute1
	ble	.L54
	ldr	r1, .L57+48
	mov	r2, #40
	str	r2, [r1, #28]	@  <variable>.y
	str	r2, [r1, #24]	@  <variable>.x
	ldr	r3, .L57+52
	mov	lr, pc
	bx	r3
	ldmea	fp, {r4, r5, r6, r7, r8, fp, sp, lr}
	bx	lr
.L58:
	.align	2
.L57:
	.word	setSpritePalette
	.word	solderPalette
	.word	setSpriteData
	.word	solderData
	.word	solder2Data
	.word	solder3Data
	.word	solder4Data
	.word	solder5Data
	.word	solder6Data
	.word	solder7Data
	.word	defaultSprite
	.word	sprites
	.word	mysprites
	.word	UpdateSpriteMemory
	.size	easySprites, .-easySprites
	.align	2
	.global	defaultSprite
	.type	defaultSprite, %function
defaultSprite:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {r4, fp, ip, lr, pc}
	add	r3, r0, r0, asl #4	@  num,  num
	ldr	r4, .L60
	mov	r3, r3, asl #2
	mov	r1, #16
	add	r2, r3, r4
	mov	lr, #0
	str	r1, [r3, r4]	@  <variable>.size
	sub	fp, ip, #4
	mov	r3, #160
	mov	ip, #1
	mov	r1, #240
	str	r3, [r2, #24]	@  <variable>.x
	str	lr, [r2, #64]	@  <variable>.animation
	str	r1, [r2, #28]	@  <variable>.y
	str	ip, [r2, #4]	@  <variable>.health
	str	ip, [r2, #20]	@  <variable>.alive
	str	ip, [r2, #8]	@  <variable>.moveSpeed
	str	ip, [r2, #12]	@  <variable>.attack
	str	ip, [r2, #16]	@  <variable>.defense
	str	lr, [r2, #60]	@  <variable>.AI
	str	lr, [r2, #48]	@  <variable>.god
	ldr	r3, .L60+4
	mov	lr, pc
	bx	r3
	ldmea	fp, {r4, fp, sp, lr}
	bx	lr
.L61:
	.align	2
.L60:
	.word	mysprites
	.word	MoveSprite
	.size	defaultSprite, .-defaultSprite
	.align	2
	.global	MoveSprite
	.type	MoveSprite, %function
MoveSprite:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, lr}
	ldr	lr, .L63
	mov	ip, r0, asl #3	@  num
	add	r4, ip, lr
	ldrh	r3, [r4, #2]	@  <variable>.attribute1
	ldrh	r2, [ip, lr]	@  <variable>.attribute0
	and	r3, r3, #65024
	strh	r3, [r4, #2]	@ movhi 	@  <variable>.attribute1
	and	r2, r2, #65280
	ldr	r3, .L63+4
	strh	r2, [ip, lr]	@ movhi 	@  <variable>.attribute0
	add	r0, r0, r0, asl #4	@  num,  num
	add	r3, r3, r0, asl #2
	ldrh	r1, [r4, #2]	@  <variable>.attribute1
	ldrh	r2, [ip, lr]	@  <variable>.attribute0
	ldrh	r5, [r3, #28]	@  <variable>.y
	ldrh	r0, [r3, #24]	@  <variable>.x
	orr	r2, r2, r5
	orr	r1, r1, r0
	strh	r2, [ip, lr]	@ movhi 	@  <variable>.attribute0
	strh	r1, [r4, #2]	@ movhi 	@  <variable>.attribute1
	ldmfd	sp!, {r4, r5, lr}
	bx	lr
.L64:
	.align	2
.L63:
	.word	sprites
	.word	mysprites
	.size	MoveSprite, .-MoveSprite
	.align	2
	.global	setSpritePalette
	.type	setSpritePalette, %function
setSpritePalette:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	r1, #83886080
	@ lr needed for prologue
	mov	r2, #0	@  n
	add	r1, r1, #512
.L70:
	mov	r3, r2, asl #1	@  n
	ldrh	ip, [r3, r0]	@ movhi	@ * palette
	add	r2, r2, #1	@  n,  n
	cmp	r2, #255	@  n
	strh	ip, [r3, r1]	@ movhi 
	ble	.L70
	bx	lr
	.size	setSpritePalette, .-setSpritePalette
	.align	2
	.global	setSpriteData
	.type	setSpriteData, %function
setSpriteData:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	ip, #100663296
	@ lr needed for prologue
	mov	r0, r0, asl #9	@  num
	mov	r2, #0	@  n
	add	ip, ip, #65536
.L78:
	mov	r3, r2, asl #1	@  n
	ldrh	r3, [r3, r1]	@ movhi	@ * Data
	add	r2, r2, #1	@  n,  n
	cmp	r2, #255	@  n
	strh	r3, [r0, ip]	@ movhi 
	add	r0, r0, #2
	ble	.L78
	bx	lr
	.size	setSpriteData, .-setSpriteData
	.align	2
	.global	UpdateSpriteMemory
	.type	UpdateSpriteMemory, %function
UpdateSpriteMemory:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	r0, #508
	ldr	ip, .L89	@  temp
	@ lr needed for prologue
	mov	r1, #0	@  n
	add	r0, r0, #3
.L86:
	mov	r2, r1, asl #1	@  n
	add	r3, r2, #117440512
	add	r1, r1, #1	@  n,  n
	ldrh	r2, [r2, ip]	@ movhi	@ * temp
	cmp	r1, r0	@  n
	strh	r2, [r3, #0]	@ movhi 
	ble	.L86
	bx	lr
.L90:
	.align	2
.L89:
	.word	sprites
	.size	UpdateSpriteMemory, .-UpdateSpriteMemory
	.align	2
	.global	runSprite
	.type	runSprite, %function
runSprite:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {r4, fp, ip, lr, pc}
	sub	fp, ip, #4
	bl	CheckButtons
	mov	r0, #1
	bl	Pressed
	cmp	r0, #0
	mov	r2, r0
	bne	.L115
	ldr	ip, .L120
	ldr	r3, [ip, #0]	@  checka
	cmp	r3, #0
	movgt	r1, r0
	strgt	r2, [ip, #0]	@  checka
	ldrgt	r3, .L120+4
	movgt	lr, pc
	bxgt	r3
.L93:
	mov	r0, #32
	bl	Pressed
	cmp	r0, #0
	bne	.L116
.L95:
	mov	r0, #16
	bl	Pressed
	cmp	r0, #0
	bne	.L117
.L99:
	mov	r0, #64
	bl	Pressed
	cmp	r0, #0
	bne	.L118
.L103:
	mov	r0, #128
	bl	Pressed
	cmp	r0, #0
	bne	.L119
.L107:
	mov	r0, #0
	ldmea	fp, {r4, fp, sp, lr}
	b	MoveSprite
.L119:
	mov	r0, #0
	ldr	r4, .L120+8
	mov	r1, r0
	ldr	r3, .L120+12
	mov	lr, pc
	bx	r3
	ldr	r2, [r4, #64]	@  <variable>.animation
	cmp	r2, #1
	moveq	r1, #0
	movne	r1, #0
	moveq	r0, #2
	movne	r0, #1
	ldr	r3, .L120+4
	mov	lr, pc
	bx	r3
	ldr	r1, [r4, #28]	@  <variable>.y
	add	r3, r1, #16
	cmp	r3, #159
	bgt	.L107
	ldr	r0, [r4, #24]	@  <variable>.x
	add	r1, r1, #1
	mov	r2, #0
	ldr	r3, .L120+16
	mov	lr, pc
	bx	r3
	b	.L107
.L118:
	ldr	r4, .L120+8
	mov	r1, #0
	ldr	r3, .L120+12
	mov	r0, #1
	mov	lr, pc
	bx	r3
	ldr	r2, [r4, #64]	@  <variable>.animation
	cmp	r2, #1
	moveq	r1, #0
	movne	r1, #0
	moveq	r0, #2
	movne	r0, #1
	ldr	r3, .L120+4
	mov	lr, pc
	bx	r3
	ldr	r1, [r4, #28]	@  <variable>.y
	cmp	r1, #0
	ble	.L103
	ldr	r0, [r4, #24]	@  <variable>.x
	sub	r1, r1, #1
	mov	r2, #0
	ldr	r3, .L120+16
	mov	lr, pc
	bx	r3
	b	.L103
.L117:
	ldr	r4, .L120+8
	mov	r1, #0
	ldr	r3, .L120+12
	mov	r0, #1
	mov	lr, pc
	bx	r3
	ldr	r2, [r4, #64]	@  <variable>.animation
	cmp	r2, #4
	moveq	r1, #0
	moveq	r0, #5
	movne	r0, #4
	movne	r1, #0
	ldr	r3, .L120+4
	mov	lr, pc
	bx	r3
	ldr	r0, [r4, #24]	@  <variable>.x
	add	r3, r0, #16
	cmp	r3, #239
	bgt	.L99
	ldr	r1, [r4, #28]	@  <variable>.y
	add	r0, r0, #1
	mov	r2, #0
	ldr	r3, .L120+16
	mov	lr, pc
	bx	r3
	b	.L99
.L116:
	mov	r0, #0
	ldr	r4, .L120+8
	mov	r1, r0
	ldr	r3, .L120+12
	mov	lr, pc
	bx	r3
	ldr	r2, [r4, #64]	@  <variable>.animation
	cmp	r2, #4
	moveq	r1, #0
	moveq	r0, #5
	movne	r0, #4
	movne	r1, #0
	ldr	r3, .L120+4
	mov	lr, pc
	bx	r3
	ldr	r0, [r4, #24]	@  <variable>.x
	cmp	r0, #0
	ble	.L95
	ldr	r1, [r4, #28]	@  <variable>.y
	sub	r0, r0, #1
	mov	r2, #0
	ldr	r3, .L120+16
	mov	lr, pc
	bx	r3
	b	.L95
.L115:
	ldr	r2, .L120
	mov	r3, #1
	str	r3, [r2, #0]	@  checka
	ldr	r1, .L120+20
	mov	r0, #0
	mov	lr, pc
	bx	r1
	b	.L93
.L121:
	.align	2
.L120:
	.word	checka
	.word	changeAnimation
	.word	mysprites
	.word	flipSprite
	.word	moveSprite
	.word	attack
	.size	runSprite, .-runSprite
	.align	2
	.global	changeHealth
	.type	changeHealth, %function
changeHealth:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r2, .L123
	add	r1, r1, r1, asl #4	@  num,  num
	add	r2, r2, r1, asl #2
	ldr	r3, [r2, #4]	@  <variable>.health
	add	r3, r3, r0	@  health
	mov	r0, #0
	@ lr needed for prologue
	str	r3, [r2, #4]	@  <variable>.health
	bx	lr
.L124:
	.align	2
.L123:
	.word	mysprites
	.size	changeHealth, .-changeHealth
	.align	2
	.global	changeSpeed
	.type	changeSpeed, %function
changeSpeed:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L126
	add	r1, r1, r1, asl #4	@  num,  num
	add	r3, r3, r1, asl #2
	str	r0, [r3, #8]	@  speed,  <variable>.moveSpeed
	mov	r0, #0
	@ lr needed for prologue
	bx	lr
.L127:
	.align	2
.L126:
	.word	mysprites
	.size	changeSpeed, .-changeSpeed
	.align	2
	.global	changeAttack
	.type	changeAttack, %function
changeAttack:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L129
	add	r1, r1, r1, asl #4	@  num,  num
	add	r3, r3, r1, asl #2
	str	r0, [r3, #12]	@  attack,  <variable>.attack
	mov	r0, #0
	@ lr needed for prologue
	bx	lr
.L130:
	.align	2
.L129:
	.word	mysprites
	.size	changeAttack, .-changeAttack
	.align	2
	.global	changeDefense
	.type	changeDefense, %function
changeDefense:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L132
	add	r1, r1, r1, asl #4	@  num,  num
	add	r3, r3, r1, asl #2
	str	r0, [r3, #16]	@  defense,  <variable>.defense
	mov	r0, #0
	@ lr needed for prologue
	bx	lr
.L133:
	.align	2
.L132:
	.word	mysprites
	.size	changeDefense, .-changeDefense
	.align	2
	.global	alive
	.type	alive, %function
alive:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L135
	add	r1, r1, r1, asl #4	@  num,  num
	add	r3, r3, r1, asl #2
	str	r0, [r3, #20]	@  alive,  <variable>.alive
	mov	r0, #0
	@ lr needed for prologue
	bx	lr
.L136:
	.align	2
.L135:
	.word	mysprites
	.size	alive, .-alive
	.align	2
	.global	godMode
	.type	godMode, %function
godMode:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L138
	add	r1, r1, r1, asl #4	@  num,  num
	add	r3, r3, r1, asl #2
	str	r0, [r3, #48]	@  god,  <variable>.god
	mov	r0, #0
	@ lr needed for prologue
	bx	lr
.L139:
	.align	2
.L138:
	.word	mysprites
	.size	godMode, .-godMode
	.align	2
	.global	changeAI
	.type	changeAI, %function
changeAI:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L141
	add	r1, r1, r1, asl #4	@  num,  num
	add	r3, r3, r1, asl #2
	str	r0, [r3, #60]	@  ai,  <variable>.AI
	mov	r0, #0
	@ lr needed for prologue
	bx	lr
.L142:
	.align	2
.L141:
	.word	mysprites
	.size	changeAI, .-changeAI
	.align	2
	.global	moveSprite
	.type	moveSprite, %function
moveSprite:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L144
	add	r2, r2, r2, asl #4	@  num,  num
	add	r3, r3, r2, asl #2
	str	r0, [r3, #24]	@  x,  <variable>.x
	mov	r0, #0
	@ lr needed for prologue
	str	r1, [r3, #28]	@  y,  <variable>.y
	bx	lr
.L145:
	.align	2
.L144:
	.word	mysprites
	.size	moveSprite, .-moveSprite
	.align	2
	.global	changeAnimation
	.type	changeAnimation, %function
changeAnimation:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	ip, .L147
	add	r2, r1, r1, asl #4	@  num,  num
	ldr	r3, .L147+4
	add	ip, ip, r2, asl #2
	add	r3, r3, r1, asl #3	@  num
	mov	r2, r0, asl #4	@  animation
	str	r0, [ip, #64]	@  animation,  <variable>.animation
	mov	r0, #0
	@ lr needed for prologue
	strh	r2, [r3, #4]	@ movhi 	@  <variable>.attribute2
	bx	lr
.L148:
	.align	2
.L147:
	.word	mysprites
	.word	sprites
	.size	changeAnimation, .-changeAnimation
	.align	2
	.global	flipSprite
	.type	flipSprite, %function
flipSprite:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L158
	cmp	r0, #0	@  flip
	add	r2, r3, r1, asl #3	@  num
	ldreqh	r3, [r2, #2]	@  <variable>.attribute1
	orreq	r3, r3, #4096
	@ lr needed for prologue
	streqh	r3, [r2, #2]	@ movhi 	@  <variable>.attribute1
	beq	.L151
	ldr	r3, .L158
	cmp	r0, #1	@  flip
	add	r1, r3, r1, asl #3	@  num
	beq	.L157
.L151:
	mov	r0, #0
	bx	lr
.L157:
	ldrh	r3, [r1, #2]	@  <variable>.attribute1
	bic	r3, r3, #4352
	bic	r3, r3, #16
	strh	r3, [r1, #2]	@ movhi 	@  <variable>.attribute1
	ldrh	r2, [r1, #2]	@  <variable>.attribute1
	orr	r2, r2, #4096
	strh	r2, [r1, #2]	@ movhi 	@  <variable>.attribute1
	ldrh	r3, [r1, #2]	@  <variable>.attribute1
	bic	r3, r3, #4352
	bic	r3, r3, #16
	strh	r3, [r1, #2]	@ movhi 	@  <variable>.attribute1
	b	.L151
.L159:
	.align	2
.L158:
	.word	sprites
	.size	flipSprite, .-flipSprite
	.align	2
	.global	attack
	.type	attack, %function
attack:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	ldr	r3, .L166
	add	r2, r0, r0, asl #4	@  num,  num
	add	r3, r3, r2, asl #2
	ldr	r2, [r3, #64]	@  <variable>.animation
	cmp	r2, #6
	cmpne	r2, #3
	sub	fp, ip, #4
	mov	ip, r0	@  num
	beq	.L162
	mov	r3, ip, asl #3	@  num
	cmp	r2, #2
	mov	r0, r0, asl #3	@  num
	add	r3, r3, #6	@  num
	add	r0, r0, #3	@  num
	mov	r1, ip	@  num
	movgt	r0, r3	@  num
	movgt	r1, ip	@  num
	bl	changeAnimation
.L162:
	mov	r0, #0
	ldmea	fp, {fp, sp, lr}
	bx	lr
.L167:
	.align	2
.L166:
	.word	mysprites
	.size	attack, .-attack
	.align	2
	.global	DMAFastCopy
	.type	DMAFastCopy, %function
DMAFastCopy:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	ip, #67108864
	cmp	r3, #-2080374784	@  mode
	cmpne	r3, #-2147483648	@  mode
	orr	r2, r2, r3	@  count,  mode
	streq	r0, [ip, #212]	@  source
	@ lr needed for prologue
	streq	r1, [ip, #216]	@  dest
	streq	r2, [ip, #220]
	bx	lr
	.size	DMAFastCopy, .-DMAFastCopy
	.align	2
	.global	easy
	.type	easy, %function
easy:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	r3, #67108864
	mov	r2, #8000	@ movhi
	@ lr needed for prologue
	strh	r2, [r3, #0]	@ movhi 
	b	easySprites
	.size	easy, .-easy
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {r4, r5, fp, ip, lr, pc}
	ldr	r3, .L176
	sub	fp, ip, #4
	mov	lr, pc
	bx	r3
	ldr	r2, .L176+4
	mov	lr, pc
	bx	r2
	ldr	r5, .L176+8
	ldr	r4, .L176+12
.L175:
	mov	lr, pc
	bx	r5
	mov	lr, pc
	bx	r4
	b	.L175
.L177:
	.align	2
.L176:
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
	ldr	r3, .L179
	mov	r2, #1
	@ lr needed for prologue
	str	r2, [r3, #0]	@  gameState
	b	easy
.L180:
	.align	2
.L179:
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
	ldr	r3, .L183
	ldr	r2, [r3, #0]	@  gameState
	cmp	r2, #0
	@ lr needed for prologue
	bxne	lr
	b	LoadInitialTitleScreen
.L184:
	.align	2
.L183:
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
	ldr	r3, .L189
	ldr	r3, [r3, #0]	@  gameState
	cmp	r3, #0
	@ lr needed for prologue
	bne	.L186
	b	UpdateTitleScreen
.L186:
	cmp	r3, #1
	bxne	lr
	b	runSprite
.L190:
	.align	2
.L189:
	.word	gameState
	.size	Update, .-Update
	.align	2
	.global	Draw
	.type	Draw, %function
Draw:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	bl	WaitVBlank
	ldr	r3, .L196
	ldr	r3, [r3, #0]	@  gameState
	cmp	r3, #0
	bne	.L192
	ldmea	fp, {fp, sp, lr}
	b	DrawTitleScreen
.L192:
	cmp	r3, #1
	beq	.L195
	ldmea	fp, {fp, sp, lr}
	bx	lr
.L195:
	ldmea	fp, {fp, sp, lr}
	b	UpdateSpriteMemory
.L197:
	.align	2
.L196:
	.word	gameState
	.size	Draw, .-Draw
	.comm	gameState, 4, 32
	.comm	buttons, 20, 16
	.comm	palette, 4, 32
	.comm	Data, 4, 32
	.comm	sprites, 1024, 32
	.comm	mysprites, 8704, 32
	.ident	"GCC: (GNU) 3.3.2"
