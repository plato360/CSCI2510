typedef unsigned char u8;
//typedef unsigned short u16;
typedef unsigned long u32;


//define some interrupt registers
#define REG_IME        *(u16*)0x4000208
#define REG_IE         *(u16*)0x4000200
#define REG_IF         *(u16*)0x4000202
#define REG_INTERRUPT  *(u32*)0x3007FFC
#define REG_DISPSTAT   *(u16*)0x4000004
#define INT_VBLANK     0x0001

//define some timer and DMA registers/values
#define REG_TM0D       *(volatile u16*)0x4000100
#define REG_TM0CNT     *(volatile u16*)0x4000102
#define REG_DMA1SAD    *(volatile u32*)0x40000BC
#define REG_DMA1DAD    *(volatile u32*)0x40000C0
#define REG_DMA1CNT_H  *(volatile u16*)0x40000C6
#define TIMER_ENABLE   0x80
#define DMA_DEST_FIXED 64
#define DMA_REPEAT     512
//#define DMA_32         1024
//#define DMA_ENABLE     32768
#define DMA_TIMING_SYNC_TO_DISPLAY	4096 | 8192

//define some sound hardware registers/values
#define REG_SGCNT0_H *(volatile u16*)0x4000082
#define REG_SGCNT1 *(volatile u16*)0x4000084
#define DSOUND_A_RIGHT_CHANNEL 256
#define DSOUND_A_LEFT_CHANNEL  512
#define DSOUND_A_FIFO_RESET    2048
#define SOUND_MASTER_ENABLE    128



#include "maintheme.h"
#include "attack.h"



//global variables
u16 len = 0;

//////////////////////////////////////////////////
// Function: MyHandler
// Custom interrupt callback function
//////////////////////////////////////////////////
void MyHandler(void)
{
    //disable/store interrupts
	REG_IME = 0x00;
	u16 Int_Flag = REG_IF;

    //look for vertical refresh
	if((REG_IF & INT_VBLANK) == INT_VBLANK)
	{
	    if (!len--)
	    {
            //stop playback: disable the timer and DMA
    	    REG_TM0CNT = 0;
    	    REG_DMA1CNT_H = 0;
	    }
	}

    //restore/enable interrupts
	REG_IF = Int_Flag;
	REG_IME = 0x01;
}

void sound()
{
    u16 samplerate = (u16)704500;
    u16 samplelen = 27500;
    u16 samples;

	
    //create custom interrupt handler for vblank (chapter 8)
	REG_IME = 0x00;
	REG_INTERRUPT = (u32)MyHandler;
    REG_IE |= INT_VBLANK;
	REG_DISPSTAT |= 0x08;
	REG_IME = 0x01;
	
	//output to both channels and reset the FIFO
	REG_SGCNT0_H = DSOUND_A_RIGHT_CHANNEL |
        DSOUND_A_LEFT_CHANNEL | DSOUND_A_FIFO_RESET;

	//enable all sound
	REG_SGCNT1 = SOUND_MASTER_ENABLE;

	//DMA1 source addresss
	REG_DMA1SAD = (u32)maintheme;

	//DMA1 destination address
	REG_DMA1DAD = 0x40000A0;

	//write 32 bits into destination every vblank
	REG_DMA1CNT_H =  DMA_DEST_FIXED | DMA_REPEAT | 1024 |
        DMA_TIMING_SYNC_TO_DISPLAY | 32768;

	//set the sample rate
	samples = 16777216 / samplerate;
	REG_TM0D = 65536 - samples;

    //determine length of playback in vblanks
    len = samplelen / samples * 15.57;

	//enable the timer
	REG_TM0CNT = TIMER_ENABLE;

}

void wack()
{	
	u16 samplerate = (u16)704500;
    u16 samplelen = 341;
    u16 samples;

	
    //create custom interrupt handler for vblank (chapter 8)
	REG_IME = 0x00;
	REG_INTERRUPT = (u32)MyHandler;
    REG_IE |= INT_VBLANK;
	REG_DISPSTAT |= 0x08;
	REG_IME = 0x01;
	
	//output to both channels and reset the FIFO
	REG_SGCNT0_H = DSOUND_A_RIGHT_CHANNEL |
        DSOUND_A_LEFT_CHANNEL | DSOUND_A_FIFO_RESET;

	//enable all sound
	REG_SGCNT1 = SOUND_MASTER_ENABLE;

	//DMA1 source addresss
	REG_DMA1SAD = (u32)swordattack;

	//DMA1 destination address
	REG_DMA1DAD = 0x40000A0;

	//write 32 bits into destination every vblank
	REG_DMA1CNT_H =  DMA_DEST_FIXED | DMA_REPEAT | 1024 |
        DMA_TIMING_SYNC_TO_DISPLAY | 32768;

	//set the sample rate
	samples = 16777216 / samplerate;
	REG_TM0D = 65536 - samples;

    //determine length of playback in vblanks
    len = samplelen / samples * 15.57;

	//enable the timer
	REG_TM0CNT = TIMER_ENABLE;
}
