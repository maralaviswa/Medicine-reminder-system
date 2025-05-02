#ifndef RTC_H
#define RTC_H
#include"type.h"

void RTC_set_day(u32);
void RTC_set_date(u32, u32, u32);
void RTC_set_time(u32, u32, u32);
void RTC_dasplay_day(u8);
void RTC_get_day(u8*);
void RTC_display_date(u32,u32,u32);
void RTC_get_date(u32 *, u32 *  ,u32 *);
void RTC_display_time(u32,u32,u32 );
void RTC_get_time(u32 *, u32 * ,u32 );
void init_RTC(void);

#endif