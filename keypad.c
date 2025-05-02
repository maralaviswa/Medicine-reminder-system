#include"keypad.h"
#include<LPC21xx.H>
#include"lcd.h"
#include"keypad_defines.h"
u8 KEYPAD_LUT[4][4]={'7','8','9','/','4','5','6','*','1','2','3','-','C','0','=','+'};
void init_KEYPAD(void)
{
WRITENIBBLE(IODIR1,ROW0,15);
WRITENIBBLE(IOCLR1,ROW0,15);
WRITENIBBLE(IOSET1,COL0,15);
}
u32 col_scan(void)
{
	return READNIBBLE(IOPIN1,COL0)<15?0:1;
}
u32 row_check(void)
{ 
	u8 rno;
	for(rno=0;rno<=3;rno++)
	{
		WRITENIBBLE(IOPIN1,ROW0,((1<<rno)^15));
		if(col_scan()==0)
			break;
	}
	return rno;
}
u32 col_check()
{
	u32 cno;
	for(cno=0;cno<=3;cno++)
	{
		if(READBIT(IOPIN1,(cno+COL0))==0)
			break;
	}
	return cno;
}
u32 key_detect(void)
{
		u32 row,col;
		while(col_scan());
		row=row_check();
		col=col_check();
	  WRITENIBBLE(IOCLR1,ROW0,15);
		while(!(col_scan()));
		return KEYPAD_LUT[row][col];
}


u32 Read_NUM(void)
{
	u32 num=0,key;
//	cmd_LCD(0x01);
	while(1)
	{
		key=key_detect();
		if(key>='0' && key<='9')
		{
			num=(num*10)+(key-48);
			data_LCD(key);
		}
		if(key=='-')
		{
			if(num>0)
			{
			num=num/10;
			cmd_LCD(0x10);
			data_LCD(' ');
			cmd_LCD(0x10);
			}
		}
		if(key=='C')
			break;
	}
	return num;
}
