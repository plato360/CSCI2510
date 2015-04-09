//define button names
#define BUTTON_A 1
#define BUTTON_B 2
#define BUTTON_SELECT 4
#define BUTTON_START 8
#define BUTTON_RIGHT 16
#define BUTTON_LEFT 32
#define BUTTON_UP 64
#define BUTTON_DOWN 128
#define BUTTON_R 256
#define BUTTON_L 512

#define btnA 1
#define btnB 2
#define btnSL 4
#define btnST 8
#define btnR 16
#define btnL 32
#define btnU 64
#define btnD 128
#define btnRT 256
#define btnLT 512

#define btn_A 1
#define btn_B 2
#define btn_SL 4
#define btn_ST 8
#define btn_R 16
#define btn_L 32
#define btn_U 64
#define btn_D 128
#define btn_RT 256
#define btn_LT 512

#define btnA 1
#define btnB 2
#define btnSelect 4
#define btnStart 8
#define btnRight 16
#define btnLeft 32
#define btnUp 64
#define btnDown 128
#define btnRightTrigger 256
#define btnLeftTrigger 512

#define btn_A 1
#define btn_B 2
#define btn_Select 4
#define btn_Start 8
#define btn_Right 16
#define btn_Left 32
#define btn_Up 64
#define btn_Down 128
#define btn_RightTrigger 256
#define btn_LeftTrigger 512
////////////////////////////////////////////

volatile unsigned int *BUTTONS = (volatile unsigned int *)0X4000130; //button pointer
short buttons[10]; //button status




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

bool Pressed(int button)
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
    return false;
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
