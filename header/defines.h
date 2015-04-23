#define BG0_ENABLE 0x100
#define BG1_ENABLE 0x200
#define BG2_ENABLE 0x400
#define BG3_ENABLE 0x800

#define REG_DMA3SAD *(volatile unsigned int*)0x40000D4
#define REG_DMA3DAD *(volatile unsigned int*)0x40000D8
#define REG_DMA3CNT *(volatile unsigned int*)0x40000DC
#define DMA_ENABLE 0x80000000
#define DMA_TIMING_IMMEDIATE 0x00000000
#define DMA_16 0x00000000
#define DMA_32 0x04000000
#define DMA_32NOW (DMA_ENABLE | DMA_TIMING_IMMEDIATE | DMA_32)
#define DMA_16NOW (DMA_ENABLE | DMA_TIMING_IMMEDIATE | DMA_16)

//scrolling registers for backgrounds
#define REG_BG0HOFS *(volatile unsigned short*)0x4000010
#define REG_BG0VOFS *(volatile unsigned short*)0x4000012
#define REG_BG1HOFS *(volatile unsigned short*)0x4000014
#define REG_BG1VOFS *(volatile unsigned short*)0x4000016
#define REG_BG2HOFS *(volatile unsigned short*)0x4000018
#define REG_BG2VOFS *(volatile unsigned short*)0x400001A
#define REG_BG3HOFS *(volatile unsigned short*)0x400001C
#define REG_BG3VOFS *(volatile unsigned short*)0x400001E


//background setup registers and data
#define REG_BG0CNT *(volatile unsigned short*)0x4000008
#define REG_BG1CNT *(volatile unsigned short*)0x400000A
#define REG_BG2CNT *(volatile unsigned short*)0x400000C
#define REG_BG3CNT *(volatile unsigned short*)0x400000E
#define BG_COLOR256 0x80
#define CHAR_SHIFT 2
#define SCREEN_SHIFT 8
#define WRAPAROUND 0x1


//Palette for Backgrounds
#define BGPaletteMem ((unsigned short*)0x5000000)

//background tile bitmap sizes
#define TEXTBG_SIZE_256x256 0x0
#define TEXTBG_SIZE_256x512	0x8000
#define TEXTBG_SIZE_512x256	0x4000
#define TEXTBG_SIZE_512x512	0xC000

//background memory offset macros
#define CharBaseBlock(n) (((n)*0x4000)+0x6000000)
#define ScreenBaseBlock(n) (((n)*0x800)+0x6000000)



//macro to change the video mode
#define SetMode(mode) REG_DISPCNT = (mode)

//create a pointer to the video buffer
unsigned short* videoBuffer = (unsigned short*)0x6000000;

//define some video addresses
#define REG_DISPCNT *(volatile unsigned short*)0x4000000
#define BGPaletteMem ((unsigned short*)0x5000000)
//declare scanline counter for vertical blank
volatile unsigned short* ScanlineCounter = (volatile unsigned short*)0x4000006;
	
#define REG_BLDMOD     *(unsigned short*)0x4000050
#define REG_COLEV      *(unsigned short*)0x4000052


////////////////////////////////////////////////////////////////////////////////////////


typedef unsigned short u16;

//define object attribute memory state address
#define SpriteMem ((unsigned short*)0x7000000)

//define object attribute memory image address
#define SpriteData ((unsigned short*)0x6010000)

//video modes 3-5, OAMData starts at 0x6010000 + 8192
unsigned short* SpriteData3 = SpriteData + 8192;

//define object attribute memory palette address
#define SpritePal ((unsigned short*)0x5000200)

//misc sprite constants
#define OBJ_MAP_2D 0x0
#define OBJ_MAP_1D 0x40
#define OBJ_ENABLE 0x1000
#define BG2_ENABLE	0x400

//attribute0 stuff
#define ROTATION_FLAG 		0x100
#define SIZE_DOUBLE			0x200
#define MODE_NORMAL     	0x0
#define MODE_TRANSPARENT    0x400
#define MODE_WINDOWED		0x800
#define MOSAIC				0x1000
#define COLOR_256			0x2000
#define SQUARE              0x0
#define TALL                0x4000
#define WIDE                0x8000

//attribute1 stuff
#define SIZE_8              0x0
#define SIZE_16             0x4000
#define SIZE_32             0x8000
#define SIZE_64             0xC000

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


#define REG_VCOUNT *(volatile unsigned short*)0x04000006
void WaitVBlank(void)
{
	while(REG_VCOUNT >= 160);
	while(REG_VCOUNT < 160);
}




/////////////////////////////////////////////////////////////////
#define REG_DMA3SAD *(volatile unsigned int*)0x40000D4
#define REG_DMA3DAD *(volatile unsigned int*)0x40000D8
#define REG_DMA3CNT *(volatile unsigned int*)0x40000DC
#define DMA_ENABLE 0x80000000
#define DMA_TIMING_IMMEDIATE 0x00000000
#define DMA_16 0x00000000
#define DMA_32 0x04000000
#define DMA_32NOW (DMA_ENABLE | DMA_TIMING_IMMEDIATE | DMA_32)
#define DMA_16NOW (DMA_ENABLE | DMA_TIMING_IMMEDIATE | DMA_16)

//scrolling registers for backgrounds
#define REG_BG0HOFS *(volatile unsigned short*)0x4000010
#define REG_BG0VOFS *(volatile unsigned short*)0x4000012
#define REG_BG1HOFS *(volatile unsigned short*)0x4000014
#define REG_BG1VOFS *(volatile unsigned short*)0x4000016
#define REG_BG2HOFS *(volatile unsigned short*)0x4000018
#define REG_BG2VOFS *(volatile unsigned short*)0x400001A
#define REG_BG3HOFS *(volatile unsigned short*)0x400001C
#define REG_BG3VOFS *(volatile unsigned short*)0x400001E


//background setup registers and data
#define REG_BG0CNT *(volatile unsigned short*)0x4000008
#define REG_BG1CNT *(volatile unsigned short*)0x400000A
#define REG_BG2CNT *(volatile unsigned short*)0x400000C
#define REG_BG3CNT *(volatile unsigned short*)0x400000E
#define BG_COLOR256 0x80
#define CHAR_SHIFT 2
#define SCREEN_SHIFT 8
#define WRAPAROUND 0x1

//Palette for Backgrounds
#define BGPaletteMem ((unsigned short*)0x5000000)

//background tile bitmap sizes
#define TEXTBG_SIZE_256x256 0x0
#define TEXTBG_SIZE_256x512	0x8000
#define TEXTBG_SIZE_512x256	0x4000
#define TEXTBG_SIZE_512x512	0xC000

//background memory offset macros
#define CharBaseBlock(n) (((n)*0x4000)+0x6000000)
#define ScreenBaseBlock(n) (((n)*0x800)+0x6000000)

unsigned short MapData1[1024];
//create a pointer to background 0 tilemap buffer
 unsigned short* bg01map =(unsigned short*)ScreenBaseBlock(3);
 void DMAFastCopy(void* source, void* dest, unsigned int count, unsigned int mode);

 ////////////////////////////////////////////////////////////////////////
