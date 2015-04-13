#include "solder.h"

void easySprites();
void defaultSprite(int num);
void MoveSprite(int num);
void setSpritePalette(const unsigned short *palette);
void setSpriteData(const unsigned short *(Data));
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





const unsigned short *palette;
const unsigned short *Data;
//an entry for object attribute memory (OAM)

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
	int colormode;
	int trans;
	int god;
	signed int rotate;
	signed int scale;
	int AI;

}spriteHandle;

spriteHandle mysprites[128];

void easySprites()
{
	int count = 0;
	setSpritePalette(solderPalette);
	setSpriteData(solderData);
	for (count = 0; count < 128; count++)
	{
		defaultSprite(count);
		sprites[count].attribute0 = COLOR_256 | 240;
		sprites[count].attribute1 = SIZE_16 | 160;
		sprites[count].attribute2 = 0;
		
	}
	mysprites[0].x = 40;
	mysprites[0].y = 40;
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
void setSpriteData(const unsigned short *Data)
{
	int n = 0;
    for(n = 0; n < 256*16; n++)
        SpriteData[n] = Data[n];
 
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
    CheckButtons();
    if(Pressed(BUTTON_LEFT))
    {
		if(mysprites[0].x > 0)
			moveSprite(mysprites[0].x - 1, mysprites[0].y, 0);
		
    }
    if(Pressed(BUTTON_RIGHT))
    {
		if(mysprites[0].x + 16 < 240)
			moveSprite(mysprites[0].x + 1, mysprites[0].y, 0);
    }
    if(Pressed(BUTTON_UP))
    {
		if(mysprites[0].y > 0)
			moveSprite(mysprites[0].x, mysprites[0].y - 1, 0);
    }
    if(Pressed(BUTTON_DOWN))
    {
		if(mysprites[0].y + 16 < 160)
			moveSprite(mysprites[0].x, mysprites[0].y + 1, 0);
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
	mysprites[num].x = x;
	mysprites[num].y = y;
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