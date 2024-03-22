################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_dma.c \
../drivers/fsl_flexcomm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_i2s.c \
../drivers/fsl_i2s_dma.c \
../drivers/fsl_inputmux.c \
../drivers/fsl_power.c \
../drivers/fsl_reset.c \
../drivers/fsl_sysctl.c \
../drivers/fsl_usart.c 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_dma.d \
./drivers/fsl_flexcomm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_i2s.d \
./drivers/fsl_i2s_dma.d \
./drivers/fsl_inputmux.d \
./drivers/fsl_power.d \
./drivers/fsl_reset.d \
./drivers/fsl_sysctl.d \
./drivers/fsl_usart.d 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_dma.o \
./drivers/fsl_flexcomm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_i2s.o \
./drivers/fsl_i2s_dma.o \
./drivers/fsl_inputmux.o \
./drivers/fsl_power.o \
./drivers/fsl_reset.o \
./drivers/fsl_sysctl.o \
./drivers/fsl_usart.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC55S69JBD100 -DPRINTF_ADVANCED_ENABLE=1 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DBOARD_USE_CODEC=1 -DCODEC_WM8904_ENABLE -DSDK_DEBUGCONSOLE=1 -DPRINTF_FLOAT_ENABLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/source" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/drivers" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/component/i2c" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/codec" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/utilities" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/codec/port/wm8904" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/codec/port" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/device" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/startup" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/component/uart" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/component/lists" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/CMSIS" -I"/home/mateusz/MCU_wkspace/Praca_inz_i2s_dma_record_playback/board" -O0 -fno-common -g3 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_dma.d ./drivers/fsl_dma.o ./drivers/fsl_flexcomm.d ./drivers/fsl_flexcomm.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_i2c.d ./drivers/fsl_i2c.o ./drivers/fsl_i2s.d ./drivers/fsl_i2s.o ./drivers/fsl_i2s_dma.d ./drivers/fsl_i2s_dma.o ./drivers/fsl_inputmux.d ./drivers/fsl_inputmux.o ./drivers/fsl_power.d ./drivers/fsl_power.o ./drivers/fsl_reset.d ./drivers/fsl_reset.o ./drivers/fsl_sysctl.d ./drivers/fsl_sysctl.o ./drivers/fsl_usart.d ./drivers/fsl_usart.o

.PHONY: clean-drivers

