#ifndef _MACRO_H
#define _MACRO_H

#define SETBIT(WORD,BITPOS)                (WORD|=(1<<BITPOS))
#define CLRBIT(WORD,BITPOS)               (WORD&=~(1<<BITPOS))
#define CPLBIT(WORD,BITPOS)               (WORD^=(1<<BITPOS))
#define READBIT(WORD,BITPOS)              ((WORD>>BITPOS)&1)
#define READNIBBLE(WORD,BITPOS)              ((WORD>>BITPOS)&15)
#define READBYTE(WORD,BITPOS)              ((WORD>>BITPOS)&0xFF)


#define SSETBIT(WORD,BITPOS)             (WORD=(1<<BITPOS))
#define SCLRBIT(WORD,BITPOS)             (WORD=(1<<BITPOS))
#define WRITEBYTE(WORD,BITPOS,DATA)       (WORD=((WORD&(~(255<<BITPOS)))|(DATA<<BITPOS)))
#define WRITEBIT(WORD,BITPOS,DATA)       (WORD=((WORD&(~(1<<BITPOS)))|(DATA<<BITPOS)))
#define WRITENIBBLE(WORD,BITPOS,DATA)       (WORD=((WORD&(~(15<<BITPOS)))|(DATA<<BITPOS)))


#endif