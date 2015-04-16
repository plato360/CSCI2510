#include "globals.h"
#include "titlescreen.h"
#include "header/main.h"
void Initialize(void);
void LoadContent(void);
void Update(void);
void Draw(void);

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
    gameState = STATE_INGAME;
   	easy();            //located in main.h
}

void LoadContent() //Loads the initial content
{
    if (gameState == STATE_TITLE)
        LoadInitialTitleScreen();
    
}

void Update() //Detect Button Presses and Update Info
{
    if (gameState == STATE_TITLE)
        UpdateTitleScreen();
    else if (gameState == STATE_INGAME) {
        runSprite();          //moves sprite accross the screen
    }
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
