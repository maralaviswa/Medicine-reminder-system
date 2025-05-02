#ifndef LCD_H
#define LCD_H

#include"type.h"
void init_LCD(void);
void cmd_LCD(u32);
void data_LCD(u32);
void write_LCD(u32);
void num_LCD(u32);
void U32LCD(u32);
void str_LCD(s8 *);


#endif
