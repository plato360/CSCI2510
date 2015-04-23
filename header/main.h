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
#include "Backgrounds/master.pal.c"



    
void loadHud();


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
	SetMode(0 | BG0_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);
	//SetMode(| BG1_ENABLE | BG2_ENABLE | BG3_ENABLE);
	loadHud();
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
}

