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
	loadRoom1();
    
}

void Update() //Detect Button Presses and Update Info
{
    if (gameState == STATE_TITLE)
        UpdateTitleScreen();
    else if (gameState == STATE_INGAME) {
        runSprite();          //moves sprite accross the screen
		AI_Patrol(0, 20, 120, 0, 1, 1);
		aicount++;
        if(aicount > 5)
        {
		  AI_follow(1,2);
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
