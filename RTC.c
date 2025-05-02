#include<LPC21xx.H>
#include"rtc_defines.h"
#include"type.h"
#include"lcd.h"

s8 week[][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

void init_RTC(void)
{
	CCR=RTC_CTC_RESET;  //(1<<1)
	PREINT=PREINT_VAL;
	PREFRAC=PREFRAC_VAL;
	CCR=RTC_CCR_EN | RTC_CLK;     //(1<<0)
	
}

void RTC_get_time(u32 *hr, u32 *min ,u32 *sec )
{
	*hr=HOUR;
	*min=MIN;
	*sec=SEC;
}
void RTC_display_time(u32 hr, u32 min , u32 sec )
{
	cmd_LCD(0x80);
	data_LCD((hr/10)+48);
	data_LCD((hr%10)+48);
	data_LCD(':');
	data_LCD((min/10)+48);
	data_LCD((min%10)+48);
	data_LCD(':');
	data_LCD((sec/10)+48);
	data_LCD((sec%10)+48);
	
}
void RTC_get_date(u32 *dt, u32 * month ,u32 *yr)
{
	*dt=DOM;
	*month=MONTH;
	*yr=YEAR;
}

void RTC_display_date(u32 dt,u32 month,u32 yr)
{
	cmd_LCD(0xc0);
	data_LCD((dt/10)+48);
	data_LCD((dt%10)+48);
	data_LCD('/');
	data_LCD((month/10)+48);
	data_LCD((month%10)+48);
	data_LCD('/');
	U32LCD(yr);
}

void RTC_get_day(u8 *day)
{
	*day=DOW;
}

void RTC_dasplay_day(u8 day)
{
	cmd_LCD(0x89);
	str_LCD(week[day]);
}

void RTC_set_time(u32 hr, u32 min, u32 sec)
{
	HOUR=hr;
	MIN=min;
	SEC=sec;
}

void RTC_set_date(u32 dt, u32 month, u32 yr)
{
	DOM=dt;
	MONTH=month;
	YEAR=yr;
}

void RTC_set_day(u32 day)
{
	DOW=day;
}
