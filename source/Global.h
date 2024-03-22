#include <stdint.h>
#include <stdbool.h>
#ifndef GLOBAL_H_
#define GLOBAL_H_
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "board.h"
#include "fsl_dma.h"
#include "fsl_i2c.h"
#include "fsl_i2s.h"
#include "fsl_i2s_dma.h"
#include "fsl_codec_common.h"
#include "music.h"
#include <math.h>
#include <stdbool.h>
#include "fsl_sysctl.h"
#include "fsl_wm8904.h"
#include "fsl_codec_adapter.h"
#include "fsl_power.h"
#define DEMO_I2C                        (I2C4)
#define DEMO_I2S_MASTER_CLOCK_FREQUENCY (24576000)
#define DEMO_I2S_TX                     (I2S7)
#define DEMO_I2S_RX                     (I2S6)
#define DEMO_DMA                        (DMA0)
#define DEMO_I2S_TX_CHANNEL             (19)
#define DEMO_I2S_RX_CHANNEL             (16)
#define DEMO_I2S_CLOCK_DIVIDER          (CLOCK_GetPll0OutFreq() / 48000U / 16U / 2U)
#define DEMO_I2S_RX_MODE                (kI2S_MasterSlaveNormalSlave)
#define DEMO_I2S_TX_MODE                (kI2S_MasterSlaveNormalMaster)
#define DEMO_AUDIO_BIT_WIDTH            (16)
#define DEMO_AUDIO_SAMPLE_RATE          (48000)
#define DEMO_AUDIO_PROTOCOL             kCODEC_BusI2S
#ifndef DEMO_CODEC_VOLUME
#define DEMO_CODEC_VOLUME 				100U
#endif


#define SAMPLE_RATE 					(DEMO_AUDIO_SAMPLE_RATE)
#define PI								(3.14159265358979323846)
#define BUFF_SIZE 						(400)
#define LOOP_BUFF_SIZE 					(BUFF_SIZE/2)


extern float RADIAN_PER_SAMPLE;
extern volatile bool rxflag;
extern volatile bool txflag;
extern volatile uint16_t SAMP_POS;

__ALIGN_BEGIN extern uint8_t s_Buffer[BUFF_SIZE] __ALIGN_END; /* 100 samples => time about 2 ms */
__ALIGN_BEGIN extern uint8_t s_Buffer_Out[BUFF_SIZE] __ALIGN_END; /* 100 samples => time about 2 ms */
extern int16_t* in;
extern int16_t* out;

#endif /* GLOBAL_H_ */
