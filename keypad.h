#ifndef KEYPAD_H
#define KEYPAD_H

#include"type.h"
#include"MACROS.h"

void init_KEYPAD(void);
u32 col_scan(void);
u32 row_check(void);
u32 key_detect(void);
u32 Read_NUM(void);

#endif
