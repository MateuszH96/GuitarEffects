################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utilities/fsl_assert.c \
../utilities/fsl_debug_console.c \
../utilities/fsl_str.c 

S_UPPER_SRCS += \
../utilities/fsl_memcpy.S 

C_DEPS += \
./utilities/fsl_assert.d \
./utilities/fsl_debug_console.d \
./utilities/fsl_str.d 

OBJS += \
./utilities/fsl_assert.o \
./utilities/fsl_debug_console.o \
./utilities/fsl_memcpy.o \
./utilities/fsl_str.o 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.c utilities/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC55S69JBD100 -DPRINTF_ADVANCED_ENABLE=1 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DBOARD_USE_CODEC=1 -DCODEC_WM8904_ENABLE -DSDK_DEBUGCONSOLE=1 -DPRINTF_FLOAT_ENABLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/source" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/drivers" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/component/i2c" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/codec" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/utilities" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/codec/port/wm8904" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/codec/port" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/device" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/startup" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/component/uart" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/component/lists" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/CMSIS" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/board" -O0 -fno-common -g3 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

utilities/%.o: ../utilities/%.S utilities/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/source" -g3 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-utilities

clean-utilities:
	-$(RM) ./utilities/fsl_assert.d ./utilities/fsl_assert.o ./utilities/fsl_debug_console.d ./utilities/fsl_debug_console.o ./utilities/fsl_memcpy.o ./utilities/fsl_str.d ./utilities/fsl_str.o

.PHONY: clean-utilities

