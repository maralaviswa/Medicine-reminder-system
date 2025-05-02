#include"lcd.h"
#include"rtc.h"
#include"keypad.h"
#include"MACROS.h"
#include"delay.h"
#include<LPC21xx.H>

#define SW1 5
#define SW2 6
#define BUSSER 24

u32 hour=00,min=00,sec=5;
s32 key,num;
u32 set_time(s8*str,u32 min,u32 max)
{
                   cmd_LCD(0x01); cmd_LCD(0x80);str_LCD(str);
					         num=Read_NUM();
					         U32LCD(num);
					         if(num>=min && num<=max)
									 {
										cmd_LCD(0x01);cmd_LCD(0x80);str_LCD("SUCCESSFULLY SET");delay_ms(200);
									 return num;
									 }
									 else
									{
										cmd_LCD(0x01);cmd_LCD(0x80);str_LCD("INVALID RANGE");cmd_LCD(0xC0);str_LCD(str);
										num=Read_NUM();
										U32LCD(num);
									 cmd_LCD(0x01);cmd_LCD(0x80);str_LCD("SUCCESSFULLY SET");delay_ms(200);
										return num;
									}
}
int main()
{
	init_LCD();
  init_KEYPAD();
	init_RTC();
	SETBIT(IODIR1,BUSSER);
	LABEL1:while(1)
	   {	   
		   cmd_LCD(0x0c);
		   RTC_display_time(HOUR,MIN,SEC);
		   RTC_display_date(DOM,MONTH,YEAR);
		   RTC_dasplay_day(DOW);
			 cmd_LCD(0x94);str_LCD("MEDICINE TIME :");
			 cmd_LCD(0xD4);U32LCD(hour);data_LCD(':');U32LCD(min);data_LCD(':');U32LCD(sec);
   	 	 while(READBIT(IOPIN0,SW1)==0)
			 {
			 MAIN:cmd_LCD(0x01);cmd_LCD(0x80); str_LCD("1.RTC EDIT");cmd_LCD(0xc0);str_LCD("2.M.T UPDATE");
	     key=key_detect();
		   cmd_LCD(0x01);	cmd_LCD(0x80);	 
		   switch(key)
		   {
			 case'1':while(1)
			 {
				 cmd_LCD(0x01);cmd_LCD(0x80);str_LCD("1:H");cmd_LCD(0x85);	str_LCD("2.M");cmd_LCD(0x89);str_LCD("3.S");cmd_LCD(0x8E);str_LCD("4.DY");
		      cmd_LCD(0xC0);str_LCD("5.DT");cmd_LCD(0xc5);str_LCD("6.MO");cmd_LCD(0xC9);	str_LCD("7.YR");cmd_LCD(0xCE);str_LCD("8.EX");
				  key=key_detect();
				  switch(key)
				    {
				     	case'1':HOUR=set_time("SET HOUR :",0,23);break;
							case'2':MIN=set_time("SET MIN :",0,59);break;
							case'3':SEC=set_time("SET SEC :",0,59);break;
							case'4':DOW=set_time("SET DOW :",0,6);break;
							case'5':DOM=set_time("SET DOM :",0,31);break;
							case'6':MONTH=set_time("SET MONTH :",0,12);break;
							case'7':YEAR=set_time("SET YEAR :",0,9999);break;
							case'8':cmd_LCD(0x01);goto MAIN;
							default:cmd_LCD(0x01);cmd_LCD(0x80);str_LCD("INVALID CHOICE");delay_s(1);
				    }
			   }
			    case'2':cmd_LCD(0x01);cmd_LCD(0x0c);
									cmd_LCD(0x01);cmd_LCD(0x80);
						      str_LCD("PSS SW1 SET TIME");
									while(READBIT(IOPIN0,SW1)==1);
								  while(READBIT(IOPIN0,SW1)==0)
			            while(1)
						   	   {
										 cmd_LCD(0x01);cmd_LCD(0x80);str_LCD("1:SET HR");cmd_LCD(0x89); str_LCD("2:SET MI");cmd_LCD(0xc0);str_LCD("3:SET SC");
									  cmd_LCD(0xc9);str_LCD("4:EXIT");
									  key=key_detect();
									  switch(key)
										   {
											    case'1':hour=set_time("SET HOUR :",0,23);break;
							            case'2':min=set_time("SET MIN :",0,59);break;
							            case'3':sec=set_time("SET SEC :",0,59);break;
											    case'4':cmd_LCD(0x01);goto LABEL1;
							            default:cmd_LCD(0x01);cmd_LCD(0x80);str_LCD("INVALID CHOICE");
											 
								      }
									}
							default:cmd_LCD(0x01);cmd_LCD(0x80);str_LCD("INVALID CHOICE");delay_ms(500);goto MAIN;
	       }
		   	
         }
			    if(SEC<=(sec+2))
		  	  if(HOUR==hour && MIN==min && SEC>=sec)
					{
						cmd_LCD(0x01);
					while(READBIT(IOPIN0,SW2)==1)
						{  
							cmd_LCD(0x94);str_LCD("MEDICINE TIME  ");
							  RTC_display_time(HOUR,MIN,SEC);
		            RTC_display_date(DOM,MONTH,YEAR);
		            RTC_dasplay_day(DOW);
							  if(READBIT(IOPIN0,SW2)==0) break;
								SSETBIT(IOSET1,BUSSER);
								delay_ms(300);
							  SCLRBIT(IOCLR1,BUSSER);
							  delay_ms(300);
						}
					}
  }
}
