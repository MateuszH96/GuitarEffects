#include "Global.h"

__ALIGN_BEGIN uint8_t s_Buffer[BUFF_SIZE] __ALIGN_END={0}; /* 100 samples => time about 2 ms */
__ALIGN_BEGIN uint8_t s_Buffer_Out[BUFF_SIZE] __ALIGN_END={0}; /* 100 samples => time about 2 ms */
int16_t* in = (int16_t*)&s_Buffer;
int16_t* out = (int16_t*)&s_Buffer_Out;
float RADIAN_PER_SAMPLE = (float)(2.0 * PI) / SAMPLE_RATE;
volatile bool rxflag=false;
volatile bool txflag=false;
volatile uint16_t SAMP_POS=0;
