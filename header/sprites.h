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

#include "star.h"

int checka = 0;
int animationHolder = 0;
int attackStarCheck = 0;
int starAni = 0;
int starFlip = 0;
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

spriteHandle mysprites[128];

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
	
	setSpriteData(63,starData);
	
	for (count = 0; count < 128; count++)
	{
		defaultSprite(count);
		sprites[count].attribute0 = COLOR_256 | 240;
		sprites[count].attribute1 = SIZE_16 | 160;
		sprites[count].attribute2 = 0xC00;
		
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
	changeAnimation(63,90);
	mysprites[3].x = 10;
	mysprites[3].y = 10;
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
	
		if(Pressed(BUTTON_A))
		{
			if (checka < 1)
				animationHolder = mysprites[0].animation;
			checka = 1;
			attackStarCheck = 1;
			//attack2(0);
		}
		else if( checka > 0)
		{
			checka = 0;
			changeAnimation(animationHolder,0);
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
    if (x < 240 && (bg04map[ytile*32+xtile] < 9 || bg04map[(ytile+2)*32+xtile] < 9 || y % 8 == 0 && bg04map[(ytile+3)*32+xtile] < 9 || bg04map[ytile*32+(xtile+1)] < 9 || bg04map[ytile*32+(xtile+2)] < 9))
        return 0;
    
	mysprites[num].x = x;
	mysprites[num].y = y;
	return 0;
}
int changeAnimation(int animation, int num)
{
		sprites[num].attribute2 = 16 * animation;
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
    for (attack2count = 1; attack2count < 128; attack2count++)
    {
        if(abs(mysprites[attack2count].x - mysprites[0].x) < 18 && abs(mysprites[attack2count].y - mysprites[0].y) < 18)
            mysprites[attack2count].health--;
        if(mysprites[attack2count].health < 0)
            mysprites[attack2count].alive = -1;
    }
    wack();
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
					for (attack2count = 1; attack2count < 128; attack2count++)
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
					for (attack2count = 1; attack2count < 128; attack2count++)
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
					for (attack2count = 1; attack2count < 128; attack2count++)
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
					for (attack2count = 1; attack2count < 128; attack2count++)
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
		changeAnimation(7,num);
        return 0;
	}
    immune = 60;
    if(mysprites[num].animation == 3 || mysprites[num].animation == 6);
    else
    {
        if(mysprites[num].animation < 3)
            changeAnimation(10,num);
        else
            changeAnimation(10,num);
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
            attack(0,num);
      		moveSprite(mysprites[num].x, mysprites[num].y, num);
        }
        else;
            //changeAnimation(7,num);
    }
    else
        moveSprite(240,160,num);
    MoveSprite(num);
   	return 0;
    
}

int AI_follow(int character, int num)
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
                attack(0,num);
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
    MoveSprite(num);
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
                mysprites[num].x++;

        if (mysprites[num].y - mysprites[0].y > 0)
            if(isWall(mysprites[num].x,mysprites[num].y - 1))
                mysprites[num].y--;
        else
            if(isWall(mysprites[num].x,mysprites[num].y + 1))
                mysprites[num].y++;

        if(abs(mysprites[num].x - mysprites[0].x) < 10 && abs(mysprites[num].y - mysprites[0].y) < 10 && mysprites[num].animation != 3 && mysprites[num].animation != 6)
        {
            attack(0,2);
    		moveSprite(mysprites[num].x, mysprites[num].y, num);
        }
        else
            changeAnimation(0,2);
        MoveSprite(num);
    }

    return 0;
}
*/










