#include"lcd.h"
#include"lcd_defines.h"
#include<LPC21xx.H>
void init_LCD(void)
{
	WRITEBYTE(IODIR0,LCD,0x7FF);
	cmd_LCD(0x30);
	delay_ms(1);
	cmd_LCD(0x30);
	delay_ms(1);
	cmd_LCD(0x30);
	delay_ms(1);
	cmd_LCD(0x38);
	cmd_LCD(0x0F);
	cmd_LCD(0x01);
	cmd_LCD(0x06);
}
void cmd_LCD(u32 cmd)
{
	SCLRBIT(IOCLR0,LCD_RS);
	write_LCD(cmd);
}

void data_LCD(u32 data)
{
	SSETBIT(IOSET0,LCD_RS);
	write_LCD(data);
}
void write_LCD(u32 data)
{
	SCLRBIT(IOCLR0,LCD_RW);
	WRITEBYTE(IOPIN0,LCD,data);
	SSETBIT(IOSET0,LCD_EN);
	delay_ms(1);
	SCLRBIT(IOCLR0,LCD_EN);
	delay_ms(1);
}

 void U32LCD(u32 num)
{
	u8 arr[10];
	s8 i=0;
	if(num==0)
		data_LCD('0');
	while(num)
	{
		arr[i++]=(num%10)+48;
		num/=10;
	}
	for(--i;i>=0;i--)
	data_LCD(arr[i]);
}


void str_LCD(s8 * str)
{
	
	while(*str)
	{
		data_LCD(*str++);
	}
}

