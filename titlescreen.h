void LoadInitialTitleScreen(void);
void UpdateTitleScreen(void);
void DrawTitleScreen(void);
void loadTitle();
void loadMenu();
int startCheck();


//Loads the initial title screen
void LoadInitialTitleScreen()
{
	
	loadTitle();
	sound();
	while(!startCheck());
}

//Updates title screen data based on keyboard inputs
void UpdateTitleScreen()
{
    loadMenu();
}

//Draws changes to the screen
void DrawTitleScreen()
{
    loadMenu();
}
