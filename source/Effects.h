#ifndef EFFECTS_H_
#define EFFECTS_H_

#include <math.h>
#include <string.h>
#include "Global.h"
#define LOOP_SIGNAL						\
	int i=0;i<LOOP_BUFF_SIZE;i+=2
#define INITIAL_VARS					\
	float in_value=0, out_value=0;
#define CONVERT_SIGNAL_TO_FLOAT 		\
	in_value = (float)input[i]/32767.0f;

#define CONVERT_FLOAT_TO_SIGNAL_LOW 	\
	out[i] = (int16_t)(out_value*32767);\
	out[i+1] = 0;

#define CONVERT_FLOAT_TO_SIGNAL_HIGH 	\
	out[i] = (int16_t)(out_value*32767);\
	out[i+1] = out[i];
#define LOW_OUTPUT
#ifndef LOW_OUTPUT
#define CONVERT_FLOAT_TO_SIGNAL CONVERT_FLOAT_TO_SIGNAL_HIGH
#else
#define CONVERT_FLOAT_TO_SIGNAL CONVERT_FLOAT_TO_SIGNAL_LOW
#endif

extern float treshold;
extern float th1_3;
extern float th2_3;
extern float th_volume;
void OverdriveInit(float,float);
void Overdrive(int16_t*);

extern float fuzz_th;
extern float fuzz_gain;
void FuzzInit(float,float);
void Fuzz(int16_t*);

void FlangerInit();
void Flanger(int16_t*);

extern float TremFreq;
extern float TremDepth;
void TremoloInit(float,float);
void Tremolo(int16_t*);

#define DELAY_BUFF_SIZE (SAMPLE_RATE/2)
extern float DelayBuffer[SAMPLE_RATE];
extern uint16_t delay_ms;
void DelayInit(uint16_t,float);
void DelayIIR(int16_t*);
void DelayFIR(int16_t*);
#endif /* EFFECTS_H_ */
