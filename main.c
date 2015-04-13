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
	easy();            //located in main.h
	while(1)
	{
	    runSprite();          //moves sprite accross the screen
	    UpdateSpriteMemory(); //updates OAM
		Update();
		Draw();
	}
}

void Initialize() //Initializes variables
{
    gameState = STATE_TITLE;
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
}

void Draw() //Draw updates to the screen
{
    if (gameState == STATE_TITLE)
        DrawTitleScreen();
}



/* END OF FILE */
