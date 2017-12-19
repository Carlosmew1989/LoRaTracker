################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third\ Party/Lora/Core/lora.c 

OBJS += \
./Middlewares/Third\ Party/Lora/Core/lora.o 

C_DEPS += \
./Middlewares/Third\ Party/Lora/Core/lora.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third\ Party/Lora/Core/lora.o: ../Middlewares/Third\ Party/Lora/Core/lora.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Core/lora.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


