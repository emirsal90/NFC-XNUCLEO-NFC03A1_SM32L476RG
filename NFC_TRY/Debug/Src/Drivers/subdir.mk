################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Drivers/btn_drv.c \
../Src/Drivers/com.c \
../Src/Drivers/drv_led.c \
../Src/Drivers/drv_spi.c \
../Src/Drivers/drv_uart.c 

OBJS += \
./Src/Drivers/btn_drv.o \
./Src/Drivers/com.o \
./Src/Drivers/drv_led.o \
./Src/Drivers/drv_spi.o \
./Src/Drivers/drv_uart.o 

C_DEPS += \
./Src/Drivers/btn_drv.d \
./Src/Drivers/com.d \
./Src/Drivers/drv_led.d \
./Src/Drivers/drv_spi.d \
./Src/Drivers/drv_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Drivers/%.o: ../Src/Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' -DUSE_HAL_LEGACY -DUSE_FULL_ASSERT '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Inc" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


