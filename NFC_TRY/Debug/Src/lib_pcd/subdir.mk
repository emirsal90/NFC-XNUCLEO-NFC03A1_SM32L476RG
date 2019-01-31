################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/lib_pcd/lib_iso14443Apcd.c \
../Src/lib_pcd/lib_iso14443Bpcd.c \
../Src/lib_pcd/lib_iso15693pcd.c \
../Src/lib_pcd/lib_iso18092pcd.c \
../Src/lib_pcd/lib_iso7816pcd.c \
../Src/lib_pcd/lib_nfctype1pcd.c \
../Src/lib_pcd/lib_nfctype2pcd.c \
../Src/lib_pcd/lib_nfctype3pcd.c \
../Src/lib_pcd/lib_nfctype4pcd.c \
../Src/lib_pcd/lib_nfctype5pcd.c \
../Src/lib_pcd/lib_pcd.c 

OBJS += \
./Src/lib_pcd/lib_iso14443Apcd.o \
./Src/lib_pcd/lib_iso14443Bpcd.o \
./Src/lib_pcd/lib_iso15693pcd.o \
./Src/lib_pcd/lib_iso18092pcd.o \
./Src/lib_pcd/lib_iso7816pcd.o \
./Src/lib_pcd/lib_nfctype1pcd.o \
./Src/lib_pcd/lib_nfctype2pcd.o \
./Src/lib_pcd/lib_nfctype3pcd.o \
./Src/lib_pcd/lib_nfctype4pcd.o \
./Src/lib_pcd/lib_nfctype5pcd.o \
./Src/lib_pcd/lib_pcd.o 

C_DEPS += \
./Src/lib_pcd/lib_iso14443Apcd.d \
./Src/lib_pcd/lib_iso14443Bpcd.d \
./Src/lib_pcd/lib_iso15693pcd.d \
./Src/lib_pcd/lib_iso18092pcd.d \
./Src/lib_pcd/lib_iso7816pcd.d \
./Src/lib_pcd/lib_nfctype1pcd.d \
./Src/lib_pcd/lib_nfctype2pcd.d \
./Src/lib_pcd/lib_nfctype3pcd.d \
./Src/lib_pcd/lib_nfctype4pcd.d \
./Src/lib_pcd/lib_nfctype5pcd.d \
./Src/lib_pcd/lib_pcd.d 


# Each subdirectory must supply rules for building sources it contributes
Src/lib_pcd/%.o: ../Src/lib_pcd/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' -DUSE_HAL_LEGACY -DUSE_FULL_ASSERT '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Inc" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Simon Lindell/Desktop/Development/NFC/NFC/NFC_TRY/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


