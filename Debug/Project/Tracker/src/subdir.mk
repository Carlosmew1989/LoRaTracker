################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project/Tracker/src/bsp.c \
../Project/Tracker/src/debug.c \
../Project/Tracker/src/hw_gpio.c \
../Project/Tracker/src/hw_rtc.c \
../Project/Tracker/src/hw_spi.c \
../Project/Tracker/src/main.c \
../Project/Tracker/src/mlm32l0xx_hal_msp.c \
../Project/Tracker/src/mlm32l0xx_hw.c \
../Project/Tracker/src/mlm32l0xx_it.c \
../Project/Tracker/src/vcom.c 

OBJS += \
./Project/Tracker/src/bsp.o \
./Project/Tracker/src/debug.o \
./Project/Tracker/src/hw_gpio.o \
./Project/Tracker/src/hw_rtc.o \
./Project/Tracker/src/hw_spi.o \
./Project/Tracker/src/main.o \
./Project/Tracker/src/mlm32l0xx_hal_msp.o \
./Project/Tracker/src/mlm32l0xx_hw.o \
./Project/Tracker/src/mlm32l0xx_it.o \
./Project/Tracker/src/vcom.o 

C_DEPS += \
./Project/Tracker/src/bsp.d \
./Project/Tracker/src/debug.d \
./Project/Tracker/src/hw_gpio.d \
./Project/Tracker/src/hw_rtc.d \
./Project/Tracker/src/hw_spi.d \
./Project/Tracker/src/main.d \
./Project/Tracker/src/mlm32l0xx_hal_msp.d \
./Project/Tracker/src/mlm32l0xx_hw.d \
./Project/Tracker/src/mlm32l0xx_it.d \
./Project/Tracker/src/vcom.d 


# Each subdirectory must supply rules for building sources it contributes
Project/Tracker/src/%.o: ../Project/Tracker/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DUSE_HAL_DRIVER -DREGION_EU868 -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/CMSIS/Include" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Crypto" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Phy" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Utilities" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Core" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Project/Tracker/inc" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/B-L072Z-LRWAN1" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Middlewares/Third Party/Lora/Mac/region" -I"C:/Users/Carlos/Desktop/LoRa/Software/LoRaWorkspace/LoRaTracker/Drivers/BSP/MLM32L07X01/Phy" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


