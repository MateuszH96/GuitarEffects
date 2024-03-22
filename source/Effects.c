#include "Effects.h"
//----------------------------------------------------------
//Ovedrive
//----------------------------------------------------------
float treshold;
float th1_3;
float th2_3;
float th_volume;
void OverdriveInit(float th, float volume){
	treshold = th;
	th1_3 = th/3.0f;
	th2_3 = 2.0f* th / 3.0f;
	th_volume = volume > 1.0f ? 1.0f:volume;
}

void Overdrive(int16_t* input){
	INITIAL_VARS;
	float multipier=0;
	for(LOOP_SIGNAL){
		CONVERT_SIGNAL_TO_FLOAT;
		multipier = in_value >= .0f ? 1.0f:-1.0f;
		if(fabsf(in_value) < th1_3){
			out_value = 2.0f*in_value;
		}else if(fabsf(in_value) > th2_3){
			out_value = multipier;
		}else{
			out_value = multipier*(3-((2-3*fabsf(in_value))*(2-3*fabsf(in_value))))/3;
		}
		out_value*=th_volume;
		CONVERT_FLOAT_TO_SIGNAL;
	}
}
//----------------------------------------------------------
//Tremolo
//----------------------------------------------------------
float TremDepth = 0;
float TremFreq = 0;
void TremoloInit(float freq, float depth){
	TremDepth = depth;
	TremFreq = freq;
}
void Tremolo(int16_t* input){
	INITIAL_VARS;
	static uint32_t indexSinTrem = 0;
	for(LOOP_SIGNAL){
		CONVERT_SIGNAL_TO_FLOAT;
		out_value  = in_value *sinf((2.0f*PI/SAMPLE_RATE)*(float)indexSinTrem*TremFreq)*TremFreq;
		indexSinTrem%=SAMPLE_RATE;
		CONVERT_FLOAT_TO_SIGNAL;

	}
}
//----------------------------------------------------------
//Fuzz
//----------------------------------------------------------
float fuzz_th;
float fuzz_gain;
void FuzzInit(float gain, float th){
	fuzz_th = th;
	fuzz_gain = gain;
}
void Fuzz(int16_t* input){
	INITIAL_VARS;
	float multipier=0;
	float tmp1 = 0;
	for(LOOP_SIGNAL){
		CONVERT_SIGNAL_TO_FLOAT;
		multipier = in_value >= .0f ? 1.0f:-1.0f;
		tmp1 = in_value * fuzz_gain /fuzz_th;
		out_value = multipier * (1.0f-expf(-multipier*tmp1));
		CONVERT_FLOAT_TO_SIGNAL;
	}
}
//----------------------------------------------------------
//Delay
//----------------------------------------------------------
uint16_t delay_ms = 0;
float loopback = 0;
float DelayBuffer[SAMPLE_RATE] ={0};
void DelayInit(uint16_t _delay, float lb){
	loopback = lb;
	delay_ms = floorf(0.001f * _delay * SAMPLE_RATE);
	memset(DelayBuffer, 0, sizeof(DelayBuffer[0]));
}
void DelayIIR(int16_t* input){
	INITIAL_VARS;
	static uint32_t indexDelay = 0;
	for(LOOP_SIGNAL){
		CONVERT_SIGNAL_TO_FLOAT;
			out_value =(1.0f/(1.0f+loopback))*(in_value + loopback*DelayBuffer[indexDelay]);
			DelayBuffer[delay_ms] = out_value;
			indexDelay++;
			delay_ms++;
			if(delay_ms>= SAMPLE_RATE){
				delay_ms =0;
			}

			if(indexDelay>= SAMPLE_RATE){
				indexDelay =0;
			}
		out[i] = (int16_t)(out_value*32767);
			out[i+1] = 0;
	}
}
void DelayFIR(int16_t* input){
	INITIAL_VARS;
	static uint32_t indexDelay = 0;
	for(LOOP_SIGNAL){
		CONVERT_SIGNAL_TO_FLOAT;
			out_value =(1.0f/(1.0f+loopback))*(in_value + loopback*DelayBuffer[indexDelay]);
			DelayBuffer[delay_ms] = in_value;
			indexDelay++;
			delay_ms++;
			if(delay_ms>= SAMPLE_RATE){
				delay_ms =0;
			}

			if(indexDelay>= SAMPLE_RATE){
				indexDelay =0;
			}
		out[i] = (int16_t)(out_value*32767);
			out[i+1] = 0;
			if(out[i]>1.0f || out[i]<-1.0f){
				PRINTF("Cos nie tak \r\n");
			}
	}
}
