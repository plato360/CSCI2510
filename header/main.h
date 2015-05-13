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
		{
			gameState = STATE_TITLE;
			initializeBackgrounds();
		}
		else
		{
			gameState = STATE_INGAME;
			loadHud();
			loadRoom1();
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
	REG_BG1CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(2 << SCREEN_SHIFT) | 0x1;
	REG_BG2CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(2 << SCREEN_SHIFT) | 0x2;
	REG_BG3CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(2 << SCREEN_SHIFT) | 0x3;
	
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

}


