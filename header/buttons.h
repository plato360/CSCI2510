
void CheckButtons()
{
    //store the status of the buttons in an array
    buttons[0] = !((*BUTTONS) & BUTTON_A);
    buttons[1] = !((*BUTTONS) & BUTTON_B);
    buttons[2] = !((*BUTTONS) & BUTTON_LEFT);
    buttons[3] = !((*BUTTONS) & BUTTON_RIGHT);
    buttons[4] = !((*BUTTONS) & BUTTON_UP);
    buttons[5] = !((*BUTTONS) & BUTTON_DOWN);
    buttons[6] = !((*BUTTONS) & BUTTON_START);
    buttons[7] = !((*BUTTONS) & BUTTON_SELECT);
    buttons[8] = !((*BUTTONS) & BUTTON_L);
    buttons[9] = !((*BUTTONS) & BUTTON_R);
}

int Pressed(int button)
{
	
    switch(button)
    {
        case BUTTON_A: return buttons[0];
        case BUTTON_B: return buttons[1];
        case BUTTON_LEFT: return buttons[2];
        case BUTTON_RIGHT: return buttons[3];
        case BUTTON_UP: return buttons[4];
        case BUTTON_DOWN: return buttons[5];
        case BUTTON_START: return buttons[6];
        case BUTTON_SELECT: return buttons[7];
        case BUTTON_L: return buttons[8];
        case BUTTON_R: return buttons[9];
    }
    return 0;
	
}

void activebutton(int testbutton)
{
	int counter = 0;
	CheckButtons();
	
        while(Pressed(testbutton))
        {
            for(counter = 0; counter < 10; counter++)
                buttons[counter] = 0;
            CheckButtons();
        }
		
}
