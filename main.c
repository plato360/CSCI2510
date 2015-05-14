#include "globals.h"
#include "titlescreen.h"
#include "header/main.h"
void Initialize(void);
void LoadContent(void);
void Update(void);
void Draw(void);
void makeEnemy1();


int aicount = 0;

int main()
{
	Initialize();
	LoadContent();
	while(1)
	{
		Update();
		Draw();
	}
}

void Initialize() //Initializes variables
{
    gameState = STATE_TITLE;
   	easy();            //located in main.h
	makeEnemy1();
}

void LoadContent() //Loads the initial content
{
    loadRoomData();
    if (gameState == STATE_TITLE)
        LoadInitialTitleScreen();
	loadHud();
	loadRoom(currentmap, currenthitmap);
	
    
}

void Update() //Detect Button Presses and Update Info
{
    if (gameState == STATE_TITLE)
        UpdateTitleScreen();
    else if (gameState == STATE_INGAME) {
        runSprite();          //moves sprite accross the screen
		attackStar(0);
		if(activateheart)
			insertHeart(99,50);
		attackFreeze();
		aicount++;
      if(aicount > 5)
        {
			runEnemy(current,currentnumber);
		  aicount = 0;
        }
    }
	startCheck();
	
}

void Draw() //Draw updates to the screen
{
    WaitVBlank();
    if (gameState == STATE_TITLE)
        DrawTitleScreen();
    else if (gameState == STATE_INGAME) {
        UpdateSpriteMemory(); //updates OAM
    }
}

void makeEnemy1()
{
	roomSprites[0].enemyX = 50;
	roomSprites[0].enemyY = 50;
	roomSprites[0].enemyType = 1;
	
	roomSprites[1].enemyX = 60;
	roomSprites[1].enemyY = 60;
	roomSprites[1].enemyType = 1;
	
	roomSprites[2].enemyX = 70;
	roomSprites[2].enemyY = 50;
	roomSprites[2].enemyType = 1;
	
	roomSprites[3].enemyX = 80;
	roomSprites[3].enemyY = 50;
	roomSprites[3].enemyType = 2;
	
	roomSprites[4].enemyX = 50;
	roomSprites[4].enemyY = 60;
	roomSprites[4].enemyType = 2;
	
	roomSprites[5].enemyX = 50;
	roomSprites[5].enemyY = 80;
	roomSprites[5].enemyType = 2;
	
	roomSprites[6].enemyX = 80;
	roomSprites[6].enemyY = 80;
	roomSprites[6].enemyType = 3;
	
	roomSprites[7].enemyX = 90;
	roomSprites[7].enemyY = 90;
	roomSprites[7].enemyType = 3;
	
	roomSprites[8].enemyX = 90;
	roomSprites[8].enemyY = 50;
	roomSprites[8].enemyType = 3;
	
	roomSprites[9].enemyX = 50;
	roomSprites[9].enemyY = 90;
	roomSprites[9].enemyType = 1;
	
	room1[0].enemyX = 80;
	room1[0].enemyY = 80;
	room1[0].enemyType = 1;
	
	room1[1].enemyX = 70;
	room1[1].enemyY = 70;
	room1[1].enemyType = 2;
	
	room2[2].enemyX = 70;
	room2[2].enemyY = 100;
	room2[2].enemyType = 1;
	
	room2[3].enemyX = 50;
	room2[3].enemyY = 80;
	room2[3].enemyType = 2;
	
	room2[4].enemyX = 40;
	room2[4].enemyY = 70;
	room2[4].enemyType = 3;
	
	loadEnemy(roomSprites,10);
}


/* END OF FILE */
