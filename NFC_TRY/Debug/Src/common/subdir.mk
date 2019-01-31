################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/common/lib_95HFConfigManager.c 

OBJS += \
./Src/common/lib_95HFConfigManager.o 

C_DEPS += \
./Src/common/lib_95HFConfigManager.d 


# Each subdirectory must supply rules for building sources it contributes
Src/common/%.o: ../Src/common/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' -DUSE_HAL_LEGACY -DUSE_FULL_ASSERT '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Inc" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


