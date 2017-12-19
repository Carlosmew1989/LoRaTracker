################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include Project/Tracker/src/subdir.mk
-include Middlewares/Third\ Party/Lora/Utilities/subdir.mk
-include Middlewares/Third\ Party/Lora/Mac/region/subdir.mk
-include Middlewares/Third\ Party/Lora/Mac/subdir.mk
-include Middlewares/Third\ Party/Lora/Crypto/subdir.mk
-include Middlewares/Third\ Party/Lora/Core/subdir.mk
-include Drivers/STM32L0xx_HAL_Driver/Src/subdir.mk
-include Drivers/CMSIS/Device/ST/STM32L0xx/Source/subdir.mk
-include Drivers/BSP/MLM32L07X01/Phy/subdir.mk
-include Drivers/BSP/MLM32L07X01/subdir.mk
-include Drivers/BSP/B-L072Z-LRWAN1/subdir.mk
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
all: LoRaTracker.elf

# Tool invocations
LoRaTracker.elf: $(OBJS) $(USER_OBJS) C:\Users\Carlos\Desktop\LoRa\Software\LoRaWorkspace\LoRaTracker\STM32L072CZYx_FLASH.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -T"C:\Users\Carlos\Desktop\LoRa\Software\LoRaWorkspace\LoRaTracker\STM32L072CZYx_FLASH.ld" -Wl,-Map=output.map -Wl,--gc-sections -lm -o "LoRaTracker.elf" @"objects.list" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "LoRaTracker.elf" "LoRaTracker.bin"
	arm-none-eabi-size "LoRaTracker.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
