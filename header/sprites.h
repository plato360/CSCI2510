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
#include "defines.h"





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

roomData currentroom;


spriteHandle mysprites[128];


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
	int count = 0;
	int spritenum = 0;
	for(count = 0; count < size; count++)
	{
		spritenum++;
		AI_follow(room[count].enemyType,spritenum++);
	}
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
	
	
	mysprites[1].x = 0;
	mysprites[1].y = 20;
	changeAnimation(7,1);
	
	mysprites[2].x = 150;
	mysprites[2].y = 0;
	mysprites[2].health = 1;
	changeAnimation(7,2);
	
	mysprites[3].x = 150;
	mysprites[3].y = 50;
	mysprites[3].health = 1;
	changeAnimation(7,3);
	
	mysprites[4].x = 100;
	mysprites[4].y = 100;
	mysprites[4].health = 1;
	changeAnimation(7,4);
	
	mysprites[5].x = 120;
	mysprites[5].y = 80;
	mysprites[5].health = 1;
	changeAnimation(7,5);
	
	mysprites[6].x = 90;
	mysprites[6].y = 90;
	mysprites[6].health = 1;
	changeAnimation(7,6);
	
	mysprites[7].x = 80;
	mysprites[7].y = 80;
	mysprites[7].health = 1;
	changeAnimation(7,7);
	
	mysprites[8].x = 64;
	mysprites[8].y = 24;
	mysprites[8].health = 1;
	changeAnimation(14,8);
	
	mysprites[9].x = 38;
	mysprites[9].y = 47;
	mysprites[9].health = 1;
	changeAnimation(14,9);
	
	mysprites[10].x = 91;
	mysprites[10].y = 86;
	mysprites[10].health = 1;
	changeAnimation(14,10);
	mysprites[3].x = 10;
	mysprites[3].y = 10;
	
	
	
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
        
    if (num == 0) {
        if (xtile == 0) {
            loadRoomLeft(currentroom->roomLeft.mapData, currentroom->roomLeft.hitmapData);
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
