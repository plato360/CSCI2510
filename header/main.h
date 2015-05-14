#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "defines.h"
#include "buttons.h"
#include "font.h"
#include "sprites.h"
#include "sound.h"
#include "Backgrounds/HUD.map.c"
#include "Backgrounds/HUD.raw.c"


#include "Backgrounds\title\title.pal.c"
#include "Backgrounds\title\title.map.c"
#include "Backgrounds\title\title.raw.c"

#include "Backgrounds\blank\blank.pal.c"
#include "Backgrounds\blank\blank.map.c"
#include "Backgrounds\blank\blank.raw.c"


#include "Backgrounds/Room1.map.c"
#include "Backgrounds/Room1.raw.c"
#include "Backgrounds/Room1hitmap.map.c"
#include "Backgrounds/Room1hitmap.raw.c"
#include "Backgrounds/master.pal.c"

#include "Backgrounds/menu/menu.pal.c"
#include "Backgrounds/menu/menu.map.c"
#include "Backgrounds/menu/menu.raw.c"

#include "Backgrounds/menu2/menu2.pal.c"
#include "Backgrounds/menu2/menu2.map.c"
#include "Backgrounds/menu2/menu2.raw.c"

void loadHud();
void loadMenu();
int startCheck();
int initializeBackgrounds();

void DMAFastCopy(void* source, void* dest, unsigned int count, unsigned int mode)
{
    if(mode == DMA_16NOW || mode == DMA_32NOW)
    {
        REG_DMA3SAD = (unsigned int) source;
        REG_DMA3DAD = (unsigned int) dest;
        REG_DMA3CNT = count | mode;
    }
}


void easy()
{	
	easySprites();
	initializeBackgrounds();
	
	
}

void loadHud()
{
	int countx = 0;
	int county = 0;
	
	REG_BG0CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(2 << SCREEN_SHIFT) | 0x0;
	DMAFastCopy((void*)master_Palette, (void*)BGPaletteMem,256, DMA_16NOW);
	for(county = 0; county <32; county++)
	{
		for(countx = 0; countx < 32; countx++)
		{
			MapData1[countx + county*32] = 0;
		}
	}

    for(county = 0; county <20; county++)
	{
		for(countx = 0; countx < 30; countx++)
		{
			MapData1[countx + county*32] = HUD_Map[countx+county*30];
		}
	}
	
	DMAFastCopy((void*)HUD_Tiles, (void*)CharBaseBlock(0),144, DMA_32NOW);
    DMAFastCopy((void*)MapData1, (void*)bg01map, 512, DMA_32NOW);
    
    addHeart(10);
}

void loadRoom1()
{
	int countx = 0;
	int county = 0;
	
    //REG_BG1CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(10 << SCREEN_SHIFT) | 4 | 0x1;
	DMAFastCopy((void*)master_Palette, (void*)BGPaletteMem,256, DMA_16NOW);
	DMAFastCopy((void*)Room1_Tiles, (void*)CharBaseBlock(1),704/4, DMA_32NOW);
    
    //REG_BG3CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(26 << SCREEN_SHIFT) | 12 | 0x3;
	for(county = 0; county <32; county++)
	{
		for(countx = 0; countx < 32; countx++)
		{
			MapData4[countx + county*32] = 0;
		}
	}

    for(county = 0; county <20; county++)
	{
		for(countx = 0; countx < 30; countx++)
		{
			MapData4[countx + county*32] = Room1hitmap_Map[countx+county*30];
		}
	}
	
	DMAFastCopy((void*)Room1hitmap_Tiles, (void*)CharBaseBlock(3),640/4, DMA_32NOW);
    DMAFastCopy((void*)MapData4, (void*)bg04map, 512, DMA_32NOW);
    loadRoom(Room1_Map);

//    loadRoomLeft(Room1hitmap_Map);
//    loadRoomLeft(Room1hitmap_Map);
//    loadRoomRight(Room1hitmap_Map);
//    loadRoomDown(Room1hitmap_Map);
//    loadRoomDown(Room1hitmap_Map);
//    loadRoomUp(Room1hitmap_Map);
//    loadRoomRight(Room1hitmap_Map);
}
int loadRoom(const unsigned short* roomLoaded) {

    int loop, loopy;
    int cy;
    WaitVBlank();
    for (loop = 0; loop < 30; loop++) {
        cy = cvprev + 1;
        if (cy > 31)
            cy = 0;
        for (loopy = 0; loopy < 20; loopy++) {
            bg02map[cnext + cy*32] = roomLoaded[loop+loopy*30];
            cy++;
            if (cy > 31)
                cy = 0;
        }
        chofs += 8;
        REG_BG1HOFS = chofs;
        cnext++;
        cprev++;
        if (cnext == 32) {
            cnext = 0;
        }
        if (cprev == 32) {
            cprev = 0;
        }
        if (chofs >= 256) {
            chofs = 0;
            REG_BG1HOFS = 0;
        }
    }
	return 0;
}

int loadRoomRight(const unsigned short* roomLoaded) {

    int loop, loopy;
    int cy;
    for (loop = 0; loop < 30; loop++) {
        cy = cvprev + 1;
        if (cy > 31)
            cy = 0;
        for (loopy = 0; loopy < 20; loopy++) {
            bg02map[cnext + cy*32] = roomLoaded[loop+loopy*30];
            cy++;
            if (cy > 31)
                cy = 0;
        }
        chofs += 2;
        WaitVBlank();
        REG_BG1HOFS = chofs;
        chofs += 2;
        WaitVBlank();
        REG_BG1HOFS = chofs;
        chofs += 2;
        WaitVBlank();
        REG_BG1HOFS = chofs;
        chofs += 2;
        WaitVBlank();
        REG_BG1HOFS = chofs;
        cnext++;
        cprev++;
        if (cnext == 32) {
            cnext = 0;
        }
        if (cprev == 32) {
            cprev = 0;
        }
        if (chofs >= 256) {
            chofs = 0;
            REG_BG1HOFS = 0;
        }
    }
	return 0;
}

int loadRoomLeft(const unsigned short* roomLoaded) {

    int loop, loopy;
    int cy;
    for (loop = 29; loop >= 0; loop--) {
        cy = cvprev + 1;
        if (cy > 31)
            cy = 0;
        for (loopy = 0; loopy < 20; loopy++) {
            bg02map[cprev + cy*32] = roomLoaded[loop+loopy*30];
            cy++;
            if (cy > 31)
                cy = 0;
        }
        chofs -= 2;
        WaitVBlank();
        REG_BG1HOFS = chofs;
        chofs -= 2;
        WaitVBlank();
        REG_BG1HOFS = chofs;
        chofs -= 2;
        WaitVBlank();
        REG_BG1HOFS = chofs;
        chofs -= 2;
        WaitVBlank();
        REG_BG1HOFS = chofs;
        cnext--;
        cprev--;
        if (cnext < 0) {
            cnext = 31;
        }
        if (cprev < 0) {
            cprev = 31;
        }

    }
	return 0;
}
int loadRoomUp(const unsigned short* roomLoaded) {

    int loop, loopx, cx;
    for (loop = 19; loop >= 0; loop--) {
        cx = cprev + 1;
        if (cx > 31)
            cx = 0;
        for (loopx = 0; loopx < 30; loopx++) {
            bg02map[cvprev*32 + cx] = roomLoaded[loopx+loop*30];
            cx++;
            if (cx > 31)
                cx = 0;
        }
        cvofs -= 2;
        WaitVBlank();
        REG_BG1VOFS = cvofs;
        cvofs -= 2;
        WaitVBlank();
        REG_BG1VOFS = cvofs;
        cvofs -= 2;
        WaitVBlank();
        REG_BG1VOFS = cvofs;
        cvofs -= 2;
        WaitVBlank();
        REG_BG1VOFS = cvofs;
        cvnext--;
        cvprev--;
        if (cvnext < 0) {
            cvnext = 31;
        }
        if (cvprev < 0) {
            cvprev = 31;
        }

    }
	return 0;
}

int loadRoomDown(const unsigned short* roomLoaded) {

    int loop, loopx, cx;
    for (loop = 0; loop < 20; loop++) {
        cx = cprev + 1;
        if (cx > 31)
            cx = 0;
        for (loopx = 0; loopx < 30; loopx++) {
            bg02map[cvnext*32 + cx] = roomLoaded[loopx+loop*30];
            cx++;
            if (cx > 31)
                cx = 0;
        }
        cvofs += 2;
        WaitVBlank();
        REG_BG1VOFS = cvofs;
        cvofs += 2;
        WaitVBlank();
        REG_BG1VOFS = cvofs;
        cvofs += 2;
        WaitVBlank();
        REG_BG1VOFS = cvofs;
        cvofs += 2;
        WaitVBlank();
        REG_BG1VOFS = cvofs;
        cvnext++;
        cvprev++;
        if (cvnext > 31) {
            cvnext = 0;
        }
        if (cvprev > 31) {
            cvprev = 0;
        }

    }
	return 0;
}

int startCheck()
{
	CheckButtons();
	if(Pressed(BUTTON_START))
	{
		if (gameState == STATE_INGAME)
		{
			gameState = STATE_TITLE;
			mysprites[89].x = 1;
			mysprites[89].y = 16*3;
			sprites[89].attribute2 = ((61*16)&0x3FF) | (((0)&3)<<10);
			MoveSprite(89);
			initializeBackgrounds();
		}
		else
		{
			gameState = STATE_INGAME;
			mysprites[86].x = 240;
			mysprites[86].y = 160;
			mysprites[87].x = 240;
			mysprites[87].y = 160;
			mysprites[88].x = 240;
			mysprites[88].y = 160;
			mysprites[89].x = 240;
			mysprites[89].y = 160;
			MoveSprite(86);
			MoveSprite(87);
			MoveSprite(88);
			MoveSprite(89);
			UpdateSpriteMemory();
			loadHud();
			loadRoom1();
			addHeart(mysprites[0].health);
		}
		activebutton(BUTTON_START);
		return 1;
	}
	return 0;
}


void loadTitle()
{
	int countx = 0;
	int county = 0;
	
	REG_BG0CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(2 << SCREEN_SHIFT) | 0x0;
	DMAFastCopy((void*)title_Palette, (void*)BGPaletteMem,256, DMA_16NOW);
	
	for(county = 0; county <32; county++)
	{
		for(countx = 0; countx < 32; countx++)
		{
			MapData1[countx + county*32] = 0;
		}
	}


    for(county = 0; county <20; county++)
	{
		for(countx = 0; countx < 30; countx++)
		{
			MapData1[countx + county*32] = title_Map[countx+county*30];
		}
	}
	
//	DMAFastCopy((void*)title_Tiles, (void*)CharBaseBlock(0),124, DMA_32NOW);
    DMAFastCopy((void*)MapData1, (void*)bg01map, 512, DMA_32NOW);
   
}

int initializeBackgrounds()
{
	int count = 0;
	int countx = 0;
	int county = 0;
	
	
	//set video mode 0 with background 0
	SetMode(0 | BG0_ENABLE | BG1_ENABLE | BG2_ENABLE  | BG3_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);
	REG_BG0CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(2 << SCREEN_SHIFT) | 0x0;
	REG_BG1CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(10 << SCREEN_SHIFT) | 4 | 0x1;
	REG_BG2CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(2 << SCREEN_SHIFT) | 0x2;
	REG_BG3CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(26 << SCREEN_SHIFT) | 12 | 0x3;
	
	for(county = 0; county <32; county++)
	{
		for(countx = 0; countx < 32; countx++)
		{
			MapData1[countx + county*32] = 0;
		}
	}

    for(county = 0; county <20; county++)
	{
		for(countx = 0; countx < 30; countx++)
		{
			MapData1[countx + county*32] = blank_Map[countx+county*30];
		}
	}
	for(count = 0; count < 32; count++)
		DMAFastCopy((void*)MapData1, (void*)ScreenBaseBlock(count), 512, DMA_32NOW);
	
	
	DMAFastCopy((void*)title_Tiles, (void*)CharBaseBlock(0),992, DMA_32NOW);
	DMAFastCopy((void*)blank_Tiles, (void*)CharBaseBlock(1),992, DMA_32NOW);
	DMAFastCopy((void*)blank_Tiles, (void*)CharBaseBlock(2),992, DMA_32NOW);
	DMAFastCopy((void*)blank_Tiles, (void*)CharBaseBlock(3),992, DMA_32NOW);
	return 0;
}

void loadMenu()
{
	int countx = 0;
	int county = 0;
	
	REG_BG0CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(2 << SCREEN_SHIFT) | 0x0;
	REG_BG1CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(10 << SCREEN_SHIFT) | 0x4;
	
	DMAFastCopy((void*)menu_Palette, (void*)BGPaletteMem,256, DMA_16NOW);
	DMAFastCopy((void*)menu_Tiles, (void*)CharBaseBlock(0),768, DMA_32NOW);
	DMAFastCopy((void*)menu2_Tiles, (void*)CharBaseBlock(1),128, DMA_32NOW);
	
	for(county = 0; county <32; county++)
	{
		for(countx = 0; countx < 32; countx++)
		{
			MapData1[countx + county*32] = 0;
		}
	}


    for(county = 0; county <20; county++)
	{
		for(countx = 0; countx < 30; countx++)
		{
			MapData1[countx + county*32] = menu2_Map[countx+county*30];
		}
	}
	
    DMAFastCopy((void*)MapData1, (void*)bgm1map, 512, DMA_32NOW);
	
	for(county = 0; county <20; county++)
	{
		for(countx = 0; countx < 30; countx++)
		{
			MapData1[countx + county*32] = menu_Map[countx+county*30];
		}
	}
	
    DMAFastCopy((void*)MapData1, (void*)bgm0map, 512, DMA_32NOW);
	
	mysprites[86].x = 17;
	mysprites[86].y = 16*3;
	mysprites[87].x = 1;
	mysprites[87].y = 16*3;
	mysprites[88].x = 1;
	mysprites[88].y = 16*7;
	
	sprites[86].attribute2 = ((60*16)&0x3FF) | (((0)&3)<<10);
	sprites[87].attribute2 = ((63*16)&0x3FF) | (((0)&3)<<10);
	sprites[88].attribute2 = ((62*16)&0x3FF) | (((0)&3)<<10);
	

	MoveSprite(86);
	MoveSprite(87);
	MoveSprite(88);

	CheckButtons();
	if(Pressed(BUTTON_UP))
	{
		if(mysprites[89].y == 16*7)
		{
			mysprites[89].y = 16*3;
			mysprites[89].x = 1;
		}
		MoveSprite(89);
	}
	if(Pressed(BUTTON_DOWN))
	{
		if(mysprites[89].y == 16*3)
		{
			mysprites[89].y = 16*7;
			mysprites[89].x = 1;
		}
		MoveSprite(89);
	}
	if(Pressed(BUTTON_LEFT))
	{
		if(mysprites[89].x == 17)
		{
			mysprites[89].x = 1;
		}
		MoveSprite(89);
	}
	if(Pressed(BUTTON_RIGHT))
	{
		if(mysprites[89].x == 1 &&  mysprites[89].y == 16*3)
		{
			mysprites[89].x = 17;
		}
		MoveSprite(89);
	}
	if(Pressed(BUTTON_A))
	{
		if(mysprites[89].y == 16*3)
		{
			if(mysprites[89].x == 1)
			{
				bItem = 0;
				ltest = 0;
			}
			else
			{
				bItem = 1;
				ltest = 1;
			}
		}
		else
			if(mysprites[0].health < 10)
				mysprites[0].health++;
	}

	UpdateSpriteMemory();
	

}


