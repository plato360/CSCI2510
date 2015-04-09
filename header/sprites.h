void easySprites();
void defaultSprite(int num);
void MoveSprite(int num);
void setSpritePalette(const unsigned short *palette);
void setSpriteData(const unsigned short *(Data));

const unsigned short *palette;
const unsigned short *Data;
//an entry for object attribute memory (OAM)

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
	int colormode;
	int trans;
	int god;
	signed int rotate;
	signed int scale;
	int AI;

}spriteHandle;

spriteHandle mysprites[128];

void easySprites()
{
	int count = 0;
	setSpritePalette(palette);
	for (count = 0; count < 128; count++)
		defaultSprite(count);
	setSpriteData(Data);
}

void defaultSprite(int num)
{
	mysprites[num].alive = 1;
//	mysprites[num].size = size;
	mysprites[num].x = 160;
	mysprites[num].y = 240;
	mysprites[num].size = 1;
	mysprites[num].moveSpeed = 1;
	mysprites[num].attack = 1;
	mysprites[num].defense = 1;
	mysprites[num].AI = 0;
	mysprites[num].god = 0;
	mysprites[num].health = 1;
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
void setSpriteData(const unsigned short *Data)
{
	int n = 0;
    for(n = 0; n < 256*8; n++)
        SpriteData[n] = Data[n];
    //setup the first sprite
//    sprites[0].attribute0 = COLOR_256 | y;
//    sprites[0].attribute1 = SIZE_64 | x;
//   sprites[0].attribute2 = char_number;
}
