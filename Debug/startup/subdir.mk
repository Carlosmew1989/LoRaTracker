################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/sysmem.c 

S_UPPER_SRCS += \
../startup/startup_stm32l072xx.S 

OBJS += \
./startup/startup_stm32l072xx.o \
./startup/sysmem.o 

S_UPPER_DEPS += \
./startup/startup_stm32l072xx.d 

C_DEPS += \
./startup/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup/%.o: ../startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


