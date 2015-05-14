#include "globals.h"
#include "titlescreen.h"
#include "header/main.h"
void Initialize(void);
void LoadContent(void);
void Update(void);
void Draw(void);

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
}

void LoadContent() //Loads the initial content
{
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
		insertHeart(50,50);
		attackFreeze();
		AI_Patrol(16, 20, 120, 0, 1, 1);
		AI_Patrol(121, 20, 200, 0, 2, 10);
		aicount++;
      if(aicount > 5)
        {
		  AI_follow(1,2);
		  AI_follow(1,3);
		  AI_follow(1,4);
		  AI_follow(1,5);
		  AI_follow(1,6);
		  AI_follow(2,7);
		  AI_follow(2,8);
		  AI_follow(2,9);

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



/* END OF FILE */
