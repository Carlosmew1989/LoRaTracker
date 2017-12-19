################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third\ Party/Lora/Mac/region/Region.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionAS923.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionAU915.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionCN470.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionCN779.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionCommon.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionEU433.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionEU868.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionIN865.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionKR920.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionUS915-Hybrid.c \
../Middlewares/Third\ Party/Lora/Mac/region/RegionUS915.c 

OBJS += \
./Middlewares/Third\ Party/Lora/Mac/region/Region.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionAS923.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionAU915.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionCN470.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionCN779.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionCommon.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionEU433.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionEU868.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionIN865.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionKR920.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionUS915-Hybrid.o \
./Middlewares/Third\ Party/Lora/Mac/region/RegionUS915.o 

C_DEPS += \
./Middlewares/Third\ Party/Lora/Mac/region/Region.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionAS923.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionAU915.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionCN470.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionCN779.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionCommon.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionEU433.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionEU868.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionIN865.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionKR920.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionUS915-Hybrid.d \
./Middlewares/Third\ Party/Lora/Mac/region/RegionUS915.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third\ Party/Lora/Mac/region/Region.o: ../Middlewares/Third\ Party/Lora/Mac/region/Region.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/Region.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionAS923.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionAS923.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionAS923.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionAU915.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionAU915.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionAU915.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionCN470.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionCN470.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionCN470.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionCN779.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionCN779.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionCN779.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionCommon.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionCommon.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionCommon.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionEU433.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionEU433.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionEU433.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionEU868.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionEU868.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionEU868.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionIN865.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionIN865.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionIN865.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionKR920.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionKR920.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionKR920.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionUS915-Hybrid.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionUS915-Hybrid.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionUS915-Hybrid.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Third\ Party/Lora/Mac/region/RegionUS915.o: ../Middlewares/Third\ Party/Lora/Mac/region/RegionUS915.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Middlewares/Third Party/Lora/Mac/region/RegionUS915.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


