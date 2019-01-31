################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include Src/lib_pcd/subdir.mk
-include Src/lib_NDEF/subdir.mk
-include Src/common/subdir.mk
-include Src/Drivers/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: NFC_TRY.elf

# Tool invocations
NFC_TRY.elf: $(OBJS) $(USER_OBJS) ../STM32L476RGTx_FLASH.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -specs=nosys.specs -specs=nano.specs -T"../STM32L476RGTx_FLASH.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "NFC_TRY.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating hex and Printing size information:'
	arm-none-eabi-objcopy -O ihex "NFC_TRY.elf" "NFC_TRY.hex"
	arm-none-eabi-size "NFC_TRY.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
