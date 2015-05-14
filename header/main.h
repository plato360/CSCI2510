#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "defines.h"
#include "buttons.h"
#include "font.h"
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
#include "Backgrounds/Room2.map.c"
#include "Backgrounds/Room3.map.c"
#include "Backgrounds/Room4.map.c"
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

#include "Backgrounds/victory/victory.pal.c"
#include "Backgrounds/victory/victory1.map.c"
#include "Backgrounds/victory/victory1.raw.c"
#include "Backgrounds/victory/victory2.map.c"
#include "Backgrounds/victory/victory2.raw.c"

#include "solder.h"
#include "solder2.h"
#include "solder3.h"
#include "solder4.h"
#include "solder5.h"
#include "solder6.h"
#include "solder7.h"
#include "vilan 20.h"
#include "vilan 21.h"
#include "vilan 22.h"
#include "vilan 23.h"
#include "vilan 24.h"
#include "vilan 25.h"
#include "vilan 26.h"

#include "villan30.h"
#include "villan31.h"
#include "villan32.h"
#include "villan33.h"
#include "villan34.h"
#include "villan35.h"
#include "villan36.h"

#include "freeze.h"
#include "star.h"
#include "heart.h"
#include "hilight.h"
#include "ghost.h"

//---------Sprites.h variables

int proceed = 0;
int freezenumber = 0;
int starnumber = 0;
int attacklimit = 0;
int ltest = 0;
int bItem = 0;
int checka = 0;
int animationHolder = 0;
int attackStarCheck = 0;
int starAni = 0;
int starFlip = 0;
int freeze = 0;
void easySprites();
void defaultSprite(int num);
void MoveSprite(int num);
void setSpritePalette(const unsigned short *palette);
void setSpriteData(int num, const unsigned short *(Data));
void runSprite();
void UpdateSpriteMemory();
int changeHealth(int health,int num);
int changeSpeed(int speed, int num);
int changeAttack(int attack, int num);
int changeDefense(int defense, int num);
int alive(int alive, int num);
int godMode(int god, int num);
int changeAI(int ai, int num);
int moveSprite(int x, int y, int num);
int changeAnimation(int animation, int num);
int flipSprite(int flip, int num);
int attack(int ani, int num);
int attack2(int num);
int attackStar(int num);

int AI_Patrol(int x1, int y1, int x2, int y2, int character, int num);
int AI_follow(int character, int num);
int AI_followWall(int num);
int addHeart(int num);
int attackFreeze();


const unsigned short *palette;
const unsigned short *Data;
//an entry for object attribute memory (OAM)
//#include "AILogic.c"

typedef struct tagSprite
{
	unsigned short attribute0;
	unsigned short attribute1;
	unsigned short attribute2;
	unsigned short attribute3;
}Sprite, *pSprite;

//create an array of 128 sprites equal to OAM
Sprite sprites[128];

typedef struct sprite
{
	int size;
	int health;
	int moveSpeed;
	int attack;
	int defense;
	int alive;
	int x;
	int y;
	int dirx;
	int diry;
	int flip;
	int colormode;
	int trans;
	int god;
	signed int rotate;
	signed int scale;
	int AI;
	int animation;

}spriteHandle;


typedef struct Enemy{
    int numEnemies;
    int enemyType;
    int enemyX;
    int enemyY;
} Enemies, *proomSprites;

Enemies roomSprites[50];

typedef struct rd {
    unsigned short* mapData;
    unsigned short* hitmapData;
    Enemies* spriteData;
    int numEnemies;
    struct rd* roomLeft;
    struct rd* roomUp;
    struct rd* roomRight;
    struct rd* roomDown;
} roomData;

roomData* currentroom;
spriteHandle mysprites[128];

//---------End sprites.h variables---------


 
void loadHud();
void loadMenu();
int startCheck();
int initializeBackgrounds();
void loadRoomData();

void DMAFastCopy(void* source, void* dest, unsigned int count, unsigned int mode)
{
    if(mode == DMA_16NOW || mode == DMA_32NOW)
    {
        REG_DMA3SAD = (unsigned int) source;
        REG_DMA3DAD = (unsigned int) dest;
        REG_DMA3CNT = count | mode;
    }
}

void loadRoomData() {
    currentmap = Room1_Map;
    currenthitmap = Room1hitmap_Map;
    roomData* room1 = (roomData*) malloc(sizeof(roomData));
    room1->spriteData = roomSprites;
    room1->mapData = Room1_Map;
    room1->hitmapData = Room1hitmap_Map;
    room1->numEnemies = 5;

    roomData* room2 = (roomData*) malloc(sizeof(roomData));
    room2->spriteData = roomSprites;
    room2->mapData = Room2_Map;
    room2->hitmapData = Room2hitmap_Map;
    room2->numEnemies = 5;

    roomData* room3 = (roomData*) malloc(sizeof(roomData));
    room3->spriteData = roomSprites;
    room3->mapData = Room3_Map;
    room3->hitmapData = Room3hitmap_Map;
    room3->numEnemies = 5;

    roomData* room4 = (roomData*) malloc(sizeof(roomData));
    room4->spriteData = roomSprites;
    room4->mapData = Room4_Map;
    room4->hitmapData = Room4hitmap_Map;
    room4->numEnemies = 5;

    room1->roomLeft = room4;
    room1->roomRight= room2;
    room1->roomUp = room1;
    room1->roomDown = room1;

    room2->roomLeft = room1;
    room2->roomRight= room2;
    room2->roomUp = room3;
    room2->roomDown = room2;

    room3->roomLeft = room3;
    room3->roomRight= room3;
    room3->roomUp = room3;
    room3->roomDown = room2;

    room4->roomLeft = room4;
    room4->roomRight= room1;
    room4->roomUp = room4;
    room4->roomDown = room4;
    currentroom = room1;
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
int loadRoom(const unsigned short* roomLoaded, const unsigned short* hitmapLoaded) {

    int loop, loopy;
    int cy;
    WaitVBlank();
    for (loop = 0; loop < 30; loop++) {
        cy = cvprev + 1;
        if (cy > 31)
            cy = 0;
        for (loopy = 0; loopy < 20; loopy++) {
            bg02map[cnext + cy*32] = roomLoaded[loop+loopy*30];
            bg04map[loop + loopy*32] = hitmapLoaded[loop+loopy*30];
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

int loadRoomRight(const unsigned short* roomLoaded, const unsigned short* hitmapLoaded) {

    int loop, loopy;
    int cy;
    for (loop = 0; loop < 30; loop++) {
        cy = cvprev + 1;
        if (cy > 31)
            cy = 0;
        for (loopy = 0; loopy < 20; loopy++) {
            bg02map[cnext + cy*32] = roomLoaded[loop+loopy*30];
            bg04map[loop + loopy*32] = hitmapLoaded[loop+loopy*30];
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
        mysprites[0].x-=7;
		MoveSprite(0);
		UpdateSpriteMemory();
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

int loadRoomLeft(const unsigned short* roomLoaded, const unsigned short* hitmapLoaded) {

    int loop, loopy;
    int cy;
    for (loop = 29; loop >= 0; loop--) {
        cy = cvprev + 1;
        if (cy > 31)
            cy = 0;
        for (loopy = 0; loopy < 20; loopy++) {
            bg02map[cprev + cy*32] = roomLoaded[loop+loopy*30];
            bg04map[loop + loopy*32] = hitmapLoaded[loop+loopy*30];
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
        mysprites[0].x+=7;
		MoveSprite(0);
		UpdateSpriteMemory();
        if (cnext < 0) {
            cnext = 31;
        }
        if (cprev < 0) {
            cprev = 31;
        }

    }
	return 0;
}
int loadRoomUp(const unsigned short* roomLoaded, const unsigned short* hitmapLoaded) {

    int loop, loopx, cx;
    for (loop = 19; loop >= 0; loop--) {
        cx = cprev + 1;
        if (cx > 31)
            cx = 0;
        for (loopx = 0; loopx < 30; loopx++) {
            bg02map[cvprev*32 + cx] = roomLoaded[loopx+loop*30];
            bg04map[loopx + loop*32] = hitmapLoaded[loopx+loop*30];
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
		mysprites[0].y+=6;
		MoveSprite(0);
		UpdateSpriteMemory();
        if (cvnext < 0) {
            cvnext = 31;
        }
        if (cvprev < 0) {
            cvprev = 31;
        }

    }
	return 0;
}

int loadRoomDown(const unsigned short* roomLoaded, const unsigned short* hitmapLoaded) {

    int loop, loopx, cx;
    for (loop = 0; loop < 20; loop++) {
        cx = cprev + 1;
        if (cx > 31)
            cx = 0;
        for (loopx = 0; loopx < 30; loopx++) {
            bg02map[cvnext*32 + cx] = roomLoaded[loopx+loop*30];
            bg04map[loopx + loop*32] = hitmapLoaded[loopx+loop*30];
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
		mysprites[0].y-=6;
		MoveSprite(0);
		UpdateSpriteMemory();
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
			REG_BG1HOFS = 0;
		}
		else
		{
			REG_TM0CNT = 0;
    	    REG_DMA1CNT_H = 0;
		    DMAFastCopy((void*)master_Palette, (void*)BGPaletteMem,256, DMA_16NOW);
	        DMAFastCopy((void*)Room1_Tiles, (void*)CharBaseBlock(1),704/4, DMA_32NOW);
            DMAFastCopy((void*)Room1hitmap_Tiles, (void*)CharBaseBlock(3),640/4, DMA_32NOW);
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
			REG_BG1CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(10 << SCREEN_SHIFT) | 4 | 0x1;
			loadRoom(currentroom->mapData, currentroom->hitmapData);
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

//--------------------------Old sprites.h starts here---------------------











int loadEnemy(Enemies * room, int size)
{
	int count = 0;
	int spritenum = 0;
	for(count = 0; count < size; count++)
	{
		spritenum++;
		changeAnimation(room[count].enemyType,spritenum);
		moveSprite(room[count].enemyX, room[count].enemyY, spritenum);
		MoveSprite(spritenum);
	}
	return 0;
}
int runEnemy(Enemies * room, int size)
{
	proceed = 0;
	int count = 0;
	int countenemy = 0;
	int spritenum = 0;
	for(count = 0; count < size; count++)
	{
		spritenum++;
		AI_follow(room[count].enemyType,spritenum);
	}
	spritenum = 0;
	for(count = 0; count < size; count++)
	{
		spritenum++;
		if(mysprites[spritenum].alive > 0)
			countenemy++;
	}
	if(countenemy <= 0)
		proceed = 1;
	
	return 0;
}

void easySprites()
{
	int count = 0;
	setSpritePalette(solderPalette);
	setSpriteData(0,solderData);
	setSpriteData(1,solder2Data);
	setSpriteData(2,solder3Data);
	setSpriteData(3,solder4Data);
	setSpriteData(4,solder5Data);
	setSpriteData(5,solder6Data);
	setSpriteData(6,solder7Data);
	
	setSpriteData(7,Vilan20Data);
	setSpriteData(8,Vilan21Data);
	setSpriteData(9,Vilan22Data);
	setSpriteData(10,Vilan23Data);
	setSpriteData(11,Vilan24Data);
	setSpriteData(12,Vilan25Data);
	setSpriteData(13,Vilan26Data);
	
	setSpriteData(14,villan30Data);
	setSpriteData(15,villan31Data);
	setSpriteData(16,villan32Data);
	setSpriteData(17,villan33Data);
	setSpriteData(18,villan34Data);
	setSpriteData(19,villan35Data);
	setSpriteData(20,villan36Data);
	
	setSpriteData(21,ghostData);
	setSpriteData(22,ghostData);
	setSpriteData(23,ghostData);
	setSpriteData(24,ghostData);
	setSpriteData(25,ghostData);
	setSpriteData(26,ghostData);
	setSpriteData(27,ghostData);
	
	setSpriteData(60,freezeData);
	setSpriteData(61,hilightData);
	setSpriteData(62,heartData);
	setSpriteData(63,starData);
	
	for (count = 0; count < 128; count++)
	{
		defaultSprite(count);
		sprites[count].attribute0 = COLOR_256 | 240;
		sprites[count].attribute1 = SIZE_16 | 160;
		sprites[count].attribute2 = (((3)&3)<<10);
		
	}
	
	mysprites[0].x = 40;
	mysprites[0].y = 40;
	mysprites[0].health = 10;
	
	
	
	
	
	changeAnimation(63,90);
	changeAnimation(62,91);
	UpdateSpriteMemory();
	
}

void defaultSprite(int num)
{
	mysprites[num].alive = 1;
	mysprites[num].size = 16;
	mysprites[num].x = 160;
	mysprites[num].y = 240;
	mysprites[num].moveSpeed = 1;
	mysprites[num].attack = 1;
	mysprites[num].defense = 1;
	mysprites[num].AI = 0;
	mysprites[num].god = 0;
	mysprites[num].health = 1;
	mysprites[num].animation = 0;
	MoveSprite(num);
}

void MoveSprite(int num)
{
    //clear the old x value
    sprites[num].attribute1 = sprites[num].attribute1 & 0xFE00;
    sprites[num].attribute1 = sprites[num].attribute1 | mysprites[num].x;
    //clear the old y value
    sprites[num].attribute0 = sprites[num].attribute0 & 0xFF00;
    sprites[num].attribute0 = sprites[num].attribute0 | mysprites[num].y;
}


    //set the sprite palette
void setSpritePalette(const unsigned short *palette)
{
	int n = 0;
    for(n = 0; n < 256; n++)
        SpritePal[n] = palette[n];
}


    //copy the sprite image into memory
void setSpriteData(int num, const unsigned short *Data)
{
	int n = 0;
    for(n = 0; n < 256; n++)
        SpriteData[n + (num*256)] = Data[n];

}
void UpdateSpriteMemory()
{
	int n;
	unsigned short* temp;
	temp = (unsigned short*)sprites;
	
	for(n = 0; n < 128 * 4; n++)
		SpriteMem[n] = temp[n];
}

void runSprite()
{
	if(attacklimit < 100)
		attacklimit++;
    CheckButtons();
	if(mysprites[0].alive > 0)
	{
	    if (immune > 0) {
	        immune--;
	        if (immune % 2 == 0)
	           moveSprite(mysprites[0].x - 1, mysprites[0].y + 1, 0);
            else
               moveSprite(mysprites[0].x + 1, mysprites[0].y - 1, 0);
        }
	
		if(Pressed(BUTTON_A) && (attacklimit > 50))
		{
			attacklimit = 0;
			if (checka < 1)
				animationHolder = mysprites[0].animation;
			checka = 1;
			attack2(0);
			
		}
		else if( (attacklimit > 50) && checka > 0)
		{
			checka = 0;
			changeAnimation(animationHolder,0);
		}
		
		if(Pressed(BUTTON_B))
		{
			if(bItem%2 == 0)
			{
				if(starnumber < 3)
				{
					if(attackStarCheck == 0)
						starnumber++;
					attackStarCheck = 1;
				}
			}
			else if(freezenumber < 3)
			{
				if(freeze == 0)
					freezenumber++;
				freeze = 200;
			}
		}
		if(Pressed(BUTTON_L) && ltest == 1)
		{
			bItem--;
			ltest = 0;
		}
		if(Pressed(BUTTON_R) && ltest == 0)
		{
			bItem++;
			ltest = 1;
		}
		

		if(Pressed(BUTTON_LEFT))
		{
			flipSprite(0,0);
			mysprites[0].flip = 0;
			if (mysprites[0].animation == 4)
				changeAnimation(5,0);
			else
				changeAnimation(4,0);
			if(mysprites[0].x > 0)
				moveSprite(mysprites[0].x - 1, mysprites[0].y, 0);
			
		}
		if(Pressed(BUTTON_RIGHT))
		{
			flipSprite(1,0);
			mysprites[0].flip = 1;
			if (mysprites[0].animation == 4)
				changeAnimation(5,0);
			else
			changeAnimation(4,0);
			if(mysprites[0].x + 16 < 240)
				moveSprite(mysprites[0].x + 1, mysprites[0].y, 0);
		}
		if(Pressed(BUTTON_UP))
		{
			flipSprite(1,0);
			mysprites[0].flip = 1;
			if (mysprites[0].animation == 1)
				changeAnimation(2,0);
			else
			changeAnimation(1,0);
			if(mysprites[0].y > 0)
				moveSprite(mysprites[0].x, mysprites[0].y - 1, 0);
		}
		if(Pressed(BUTTON_DOWN))
		{
			flipSprite(0,0);
			mysprites[0].flip = 0;
			if (mysprites[0].animation == 1)
				changeAnimation(2,0);
			else
			changeAnimation(1,0);
			if(mysprites[0].y + 16 < 160)
				moveSprite(mysprites[0].x, mysprites[0].y + 1, 0);
		}
	}
	MoveSprite(0);
}

int changeHealth(int health, int num)
{
	mysprites[num].health = mysprites[num].health + health;
	return 0;
}

int changeSpeed(int speed, int num)
{
	mysprites[num].moveSpeed = speed;
	return 0;
}

int changeAttack(int attack, int num)
{
	mysprites[num].attack = attack;
	return 0;
}

int changeDefense(int defense, int num)
{
	mysprites[num].defense = defense;
	return 0;
}

int alive(int alive, int num)
{
	mysprites[num].alive = alive;
	return 0;
}

int godMode(int god, int num)
{
	mysprites[num].god = god;
	return 0;
}

int changeAI(int ai, int num)
{
	mysprites[num].AI = ai;
	return 0;
}

int moveSprite(int x, int y, int num)
{
    int xtile = x / 8;
    int ytile = y / 8;
    if (x < 0 || y < 0 || x < 240 && (bg04map[ytile*32+xtile] == 5 || bg04map[(ytile+1)*32+xtile] == 5 ||  bg04map[(ytile+2)*32+xtile] == 5 || bg04map[ytile*32+(xtile+1)] == 5 || bg04map[(ytile+1)*32+(xtile+1)] == 5 || bg04map[(ytile+2)*32+(xtile+1)] == 5 || bg04map[ytile*32+(xtile+2)] == 5 || bg04map[(ytile+1)*32+(xtile+2)] == 5 || bg04map[(ytile+2)*32+(xtile+2)] == 5))
        return 0;

    if ((num == 0) && (proceed == 1))
	{
        if (xtile == 0) {
            //mysprites[num].x = 208;
            mysprites[num].y = y;
            currentroom = currentroom->roomLeft;
            loadRoomLeft(currentroom->mapData,currentroom->hitmapData);
            return 0;
        }
        else if (xtile > 27) {
            //mysprites[num].x = 16;
            mysprites[num].y = y;
            currentroom = currentroom->roomRight;
            loadRoomRight(currentroom->mapData,currentroom->hitmapData);
            return 0;
        }
        else if (ytile == 0) {
            mysprites[num].x = x;
         //   mysprites[num].y = 128;
            currentroom = currentroom->roomUp;
            loadRoomUp(currentroom->mapData,currentroom->hitmapData);
            return 0;
        }
        else if (ytile > 17) {
            mysprites[num].x = x;
          //  mysprites[num].y = 16;
            currentroom = currentroom->roomDown;
            loadRoomDown(currentroom->mapData,currentroom->hitmapData);
            return 0;
        }
    }

	mysprites[num].x = x;
	mysprites[num].y = y;
	return 0;
}
int changeAnimation(int animation, int num)
{
		sprites[num].attribute2 = ((animation*16)&0x3FF) | (((1)&3)<<10);
		mysprites[num].animation = animation;
		return 0;
}
int flipSprite(int flip, int num)
{
    if (flip == 0)
        sprites[num].attribute1 = sprites[num].attribute1 | 0x1000;
    else if (flip == 1)
    {
        sprites[num].attribute1 = sprites[num].attribute1 & -0x1111;
        sprites[num].attribute1 = sprites[num].attribute1 | 0x1000;
        sprites[num].attribute1 = sprites[num].attribute1 & -0x1111;
    }
    else if (flip == 2);
    else if (flip == 3);
    return 0;
}

int attack2(int num)
{
    int attack2count = 1;
    if(mysprites[num].animation == 3 || mysprites[num].animation == 6);
    else
    {
        if(mysprites[num].animation < 3)
            changeAnimation(num*8 + 3,num);
        else
            changeAnimation(num*8 + 6,num);
    }
    for (attack2count = 1; attack2count < 90; attack2count++)
    {
        if(abs(mysprites[attack2count].x - mysprites[0].x) < 18 && abs(mysprites[attack2count].y - mysprites[0].y) < 18)
        {
			mysprites[attack2count].health--;
			if(mysprites[attack2count].health <= 0)
				mysprites[attack2count].alive = -1;
			attack2count = 1000;
		}
    }
    wack();
	UpdateSpriteMemory();
    return 0;
}
int attackStar(int num)
{
	if(attackStarCheck > 0)
	{
		int attack2count = 1;
		if (starAni < 4)
		{
			if(starFlip == 0)
			{
				if(mysprites[90].y <= 156)
				{
					mysprites[90].y +=4;
					MoveSprite(90);
					for (attack2count = 1; attack2count < 90; attack2count++)
					{
						if(abs(mysprites[attack2count].x - mysprites[90].x) < 18 && abs(mysprites[attack2count].y - mysprites[90].y) < 18)
							mysprites[attack2count].health--;
						if(mysprites[attack2count].health < 0)
							mysprites[attack2count].alive = -1;
					}
				}
				else
					attackStarCheck = 0;
			}
			else
			{
				if(mysprites[90].y >= 4)
				{
					mysprites[90].y -=4;
					MoveSprite(90);
					for (attack2count = 1; attack2count < 90; attack2count++)
					{
						if(abs(mysprites[attack2count].x - mysprites[90].x) < 18 && abs(mysprites[attack2count].y - mysprites[90].y) < 18)
							mysprites[attack2count].health--;
						if(mysprites[attack2count].health < 0)
							mysprites[attack2count].alive = -1;
					}
				}
				else
					attackStarCheck = 0;
			}
		}
		else
		{
			if(starFlip == 1)
			{
				if(mysprites[90].x <= 236)
				{
					mysprites[90].x +=4;
					MoveSprite(90);
					for (attack2count = 1; attack2count < 90; attack2count++)
					{
						if(abs(mysprites[attack2count].x - mysprites[90].x) < 18 && abs(mysprites[attack2count].y - mysprites[90].y) < 18)
							mysprites[attack2count].health--;
						if(mysprites[attack2count].health < 0)
							mysprites[attack2count].alive = -1;
					}
				}
				else
					attackStarCheck = 0;
			}
			else
			{
				if(mysprites[90].x >= 4)
				{
					mysprites[90].x -=4;
					MoveSprite(90);
					for (attack2count = 1; attack2count < 90; attack2count++)
					{
						if(abs(mysprites[attack2count].x - mysprites[90].x) < 18 && abs(mysprites[attack2count].y - mysprites[90].y) < 18)
							mysprites[attack2count].health--;
						if(mysprites[attack2count].health < 0)
							mysprites[attack2count].alive = -1;
					}
				}
				else
					attackStarCheck = 0;
			}
		}
	}
	else
	{
		moveSprite(240,160,90);
		MoveSprite(90);
		mysprites[90].x = mysprites[num].x;
		mysprites[90].y = mysprites[num].y;
		starAni = mysprites[num].animation % 7;
		starFlip = mysprites[num].flip;
	}

	return 0;
}

int attack(int ani,int num)
{
    if (immune > 0)
	{
		changeAnimation((ani*7),num);
        return 0;
	}
    immune = 60;
    if(mysprites[num].animation == 3 || mysprites[num].animation == 6);
    else
    {
        if(mysprites[num].animation < 3)
            changeAnimation((ani*7) + 3,num);
        else
            changeAnimation((ani*7) + 6,num);
    }

    addHeart(--mysprites[0].health);

    if (mysprites[0].health <= 0)
    {
        moveSprite(240, 160, 0);
        mysprites[0].alive = -1;
    }
    return 0;
}
int addHeart(int num)
{
    int countaddheart = 20;
    int y = 32;
    int cah = 0;
    for(cah = 0;cah < 10; cah++)
    {

            if(cah < num)
            {
                if (cah % 2 == 0) {
                    MapData1[countaddheart + cah] = 0x0001;
                    MapData1[countaddheart + cah + 32] = 0x0003;
                }
                else {
                    MapData1[countaddheart + (cah)] = 0x0002;
                    MapData1[countaddheart + (cah) + 32] = 0x0004;
                }
            }
            else
            {
                if (cah % 2 == 0) {
                    MapData1[countaddheart + cah] = 0x0000;
                    MapData1[countaddheart + cah + 32] = 0x00000;
                }
                else {
                    MapData1[countaddheart + (cah)] = 0x0000;
                    MapData1[countaddheart + (cah) + 32] = 0x0000;
                }
            }

                MapData1[countaddheart + cah + y*2] = 0x0000;
                MapData1[countaddheart + (cah + 1) + y*2] = 0x0000;
                MapData1[countaddheart + cah + y*3] = 0x00000;
                MapData1[countaddheart + (cah + 1) + y*3] = 0x0000;



    }
    DMAFastCopy((void*)MapData1, (void*)bg01map, 512, DMA_32NOW);
    return 0;
}
/*
int wallChecker(int num)
{
	if(BUTTON_LEFT)
		if(isWall(mysprites[num].x - 1))
			return 1;
		
	if(Pressed(BUTTON_RIGHT))
		if(isWall(mysprites[num].x + 1))
			return 1;
		
    if(Pressed(BUTTON_UP))
		if(isWall(mysprites[num].y - 1))
			return 1;
		
    if(Pressed(BUTTON_DOWN))
		if(isWall(mysprites[num].y + 1))
			return 1;
	return 0;
}
int isWall(int test)
{
	if(wallMap[test])
		return 1;
	else
		return 0;
}

//void createWall(){}
*/

int AI_Patrol(int x1, int y1, int x2, int y2, int character, int num)
{
	if(freeze <= 0)
	{
		if(mysprites[num].alive > 0)
		{
		if (y2 == 0)
		{
				if (mysprites[num].flip == 0)
				{
					if(mysprites[num].animation == 7*character + 5)
						changeAnimation(7*character + 4,num);
					else
						changeAnimation(7*character + 5,num);
					mysprites[num].x++;
					mysprites[num].y = y1;
					if (mysprites[num].x >= x2)
					{
						mysprites[num].flip = 1;
						flipSprite(0,num);
					}
				}
				else
				{
					if(mysprites[num].animation == 7*character + 5)
						changeAnimation(7*character + 4,num);
					else
						changeAnimation(7*character + 5,num);
					mysprites[num].x--;
					mysprites[num].y = y1;
					if (mysprites[num].x <= x1)
					{
						mysprites[num].flip = 0;
						flipSprite(1,num);
					}
				}
			}
			else
			{
				if (mysprites[num].flip == 0)
				{
					if(mysprites[num].animation == 7*character + 2)
						changeAnimation(7*character + 1,num);
					else
						changeAnimation(7*character + 2,num);
					mysprites[num].y++;
					mysprites[num].x = x1;
					if (mysprites[num].y >= y2)
						mysprites[num].flip = 1;
				}
				else
				{
					if(mysprites[num].animation == 7*character + 2)
						changeAnimation(7*character + 1,num);
					else
						changeAnimation(7*character + 2,num);
					mysprites[num].y--;
					mysprites[num].x = x1;
					if (mysprites[num].y <= y1)
						mysprites[num].flip = 0;
				}
			}

			if(abs(mysprites[num].x - mysprites[0].x) < 10 && abs(mysprites[num].y - mysprites[0].y) < 10 && mysprites[num].animation != 3 && mysprites[num].animation != 6)
			{
				attack(character,num);
				moveSprite(mysprites[num].x, mysprites[num].y, num);
			}
			else;
				//changeAnimation(7,num);
		}
		else
			moveSprite(240,160,num);
	}
	MoveSprite(num);
   	return 0;

}

int AI_follow(int character, int num)
{
	if(freeze <= 0)
	{
		if(mysprites[num].alive > 0)
		{
			if(mysprites[0].alive > 0)
			{
				if (mysprites[num].x - mysprites[0].x > 0)
				{
					if(mysprites[num].animation == 7*character + 5)
						changeAnimation(7*character + 4,num);
					else
						changeAnimation(7*character + 5,num);
					mysprites[num].x--;
					flipSprite(0,num);
				}
				else
				{
					if(mysprites[num].animation == 7*character + 5)
						changeAnimation(7*character + 4,num);
					else
						changeAnimation(7*character + 5,num);
					mysprites[num].x++;
					flipSprite(1,num);
				}
	
				if (mysprites[num].y - mysprites[0].y > 0)
				{
					/*if(mysprites[num].animation == 7*character + 2)
						changeAnimation(7*character + 1,num);
					else
						changeAnimation(7*character + 2,num);*/
					mysprites[num].y--;
				}
				else
				{
					/* if(mysprites[num].animation == 7*character + 2)
						changeAnimation(7*character + 1,num);
					else
						changeAnimation(7*character + 2,num); */
					mysprites[num].y++;
				}
	
				if(abs(mysprites[num].x - mysprites[0].x) < 10 && abs(mysprites[num].y - mysprites[0].y) < 10 && mysprites[num].animation != 3 && mysprites[num].animation != 6)
				{
					attack(character,num);
					moveSprite(mysprites[num].x, mysprites[num].y, num);
				}
				else;
				//   changeAnimation(7,num);
			}
		}
		else
		{
			moveSprite(240,160,num);
		}
	}
	MoveSprite(num);
	return 0;
}


int insertHeart(int x, int y)
{
	if(mysprites[91].alive > 0)
	{
		moveSprite(x,y,91);
		MoveSprite(91);
		if(abs(x - mysprites[0].x) < 10 && abs(y - mysprites[0].y) < 10)
		{
			addHeart(++mysprites[0].health);
			moveSprite(240,160,91);
			MoveSprite(91);
			mysprites[91].alive = 0;
		}
	}
	return 0;
}



int attackFreeze()
{
	if(freeze > 0)
		freeze--;
	return 0;
}

void loadvictory()
{
	int countx = 0;
	int county = 0;
	
	REG_BG0CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(2 << SCREEN_SHIFT) | 0x0;
	REG_BG1CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 |(10 << SCREEN_SHIFT) | 0x4;
	
	DMAFastCopy((void*)victory_Palette, (void*)BGPaletteMem,256, DMA_16NOW);
	DMAFastCopy((void*)victory1_Tiles, (void*)CharBaseBlock(0),768, DMA_32NOW);
	DMAFastCopy((void*)victory2_Tiles, (void*)CharBaseBlock(1),128, DMA_32NOW);
	
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
			MapData1[countx + county*32] = victory2_Map[countx+county*30];
		}
	}
	
    DMAFastCopy((void*)MapData1, (void*)bgm1map, 512, DMA_32NOW);
	
	for(county = 0; county <20; county++)
	{
		for(countx = 0; countx < 30; countx++)
		{
			MapData1[countx + county*32] = victory1_Map[countx+county*30];
		}
	}
	
    DMAFastCopy((void*)MapData1, (void*)bgm0map, 512, DMA_32NOW);
	

}


/*
int AI_followWall(int num)
{
    if(mysprites[0].alive > 0)
    {
        if (mysprites[num].x - mysprites[0].x > 0)
            if(isWall(mysprites[num].x - 1,mysprites[num].y))
                mysprites[num].x--;
        else
            if(isWall(mysprites[num].x + 1,mysprites[num].y))

*/


