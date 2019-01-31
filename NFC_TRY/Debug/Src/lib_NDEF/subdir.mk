################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/lib_NDEF/lib_95HF_wrapper.c \
../Src/lib_NDEF/lib_NDEF.c \
../Src/lib_NDEF/lib_NDEF_AAR.c \
../Src/lib_NDEF/lib_NDEF_Email.c \
../Src/lib_NDEF/lib_NDEF_Geo.c \
../Src/lib_NDEF/lib_NDEF_MyApp.c \
../Src/lib_NDEF/lib_NDEF_SMS.c \
../Src/lib_NDEF/lib_NDEF_Text.c \
../Src/lib_NDEF/lib_NDEF_URI.c \
../Src/lib_NDEF/lib_NDEF_Vcard.c 

OBJS += \
./Src/lib_NDEF/lib_95HF_wrapper.o \
./Src/lib_NDEF/lib_NDEF.o \
./Src/lib_NDEF/lib_NDEF_AAR.o \
./Src/lib_NDEF/lib_NDEF_Email.o \
./Src/lib_NDEF/lib_NDEF_Geo.o \
./Src/lib_NDEF/lib_NDEF_MyApp.o \
./Src/lib_NDEF/lib_NDEF_SMS.o \
./Src/lib_NDEF/lib_NDEF_Text.o \
./Src/lib_NDEF/lib_NDEF_URI.o \
./Src/lib_NDEF/lib_NDEF_Vcard.o 

C_DEPS += \
./Src/lib_NDEF/lib_95HF_wrapper.d \
./Src/lib_NDEF/lib_NDEF.d \
./Src/lib_NDEF/lib_NDEF_AAR.d \
./Src/lib_NDEF/lib_NDEF_Email.d \
./Src/lib_NDEF/lib_NDEF_Geo.d \
./Src/lib_NDEF/lib_NDEF_MyApp.d \
./Src/lib_NDEF/lib_NDEF_SMS.d \
./Src/lib_NDEF/lib_NDEF_Text.d \
./Src/lib_NDEF/lib_NDEF_URI.d \
./Src/lib_NDEF/lib_NDEF_Vcard.d 


# Each subdirectory must supply rules for building sources it contributes
Src/lib_NDEF/%.o: ../Src/lib_NDEF/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' -DUSE_HAL_LEGACY -DUSE_FULL_ASSERT '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Inc" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


