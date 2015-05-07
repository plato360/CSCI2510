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
#include "Backgrounds/Room1.map.c"
#include "Backgrounds/Room1.raw.c"
#include "Backgrounds/Room1hitmap.map.c"
#include "Backgrounds/Room1hitmap.raw.c"
#include "Backgrounds/master.pal.c"

void loadHud();
int startCheck();

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
	//set video mode 0 with background 0
	SetMode(0 | BG0_ENABLE | BG1_ENABLE | BG3_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);
	//SetMode(| BG1_ENABLE | BG2_ENABLE | BG3_ENABLE);
	loadHud();
	loadRoom1();
	easySprites();
}

void loadHud()
{
	int countx = 0;
	int county = 0;
	
	REG_BG0CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(3 << SCREEN_SHIFT) | 0x0;
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
	
	DMAFastCopy((void*)HUD_Tiles, (void*)CharBaseBlock(0),2496/4, DMA_32NOW);
    DMAFastCopy((void*)MapData1, (void*)bg01map, 512, DMA_32NOW);
    
    addHeart(10);
}

void loadRoom1()
{
	int countx = 0;
	int county = 0;
	
    REG_BG1CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(10 << SCREEN_SHIFT) | 4 | 0x0;
	DMAFastCopy((void*)master_Palette, (void*)BGPaletteMem,256, DMA_16NOW);
	for(county = 0; county <32; county++)
	{
		for(countx = 0; countx < 32; countx++)
		{
			MapData2[countx + county*32] = 0;
		}
	}

    for(county = 0; county <20; county++)
	{
		for(countx = 0; countx < 30; countx++)
		{
			MapData2[countx + county*32] = Room1_Map[countx+county*30];
		}
	}
	
	DMAFastCopy((void*)Room1_Tiles, (void*)CharBaseBlock(1),704/4, DMA_32NOW);
    DMAFastCopy((void*)MapData2, (void*)bg02map, 512, DMA_32NOW);
    
    REG_BG3CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(26 << SCREEN_SHIFT) | 12 | 0x0;
	DMAFastCopy((void*)master_Palette, (void*)BGPaletteMem,256, DMA_16NOW);
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
}

int startCheck()
{
	CheckButtons();
	if(Pressed(BUTTON_START))
	{
		if (gameState == STATE_INGAME)
			gameState = STATE_TITLE;
		else
			gameState = STATE_INGAME;
		activebutton(BUTTON_START);
	}
	return 0;
}
