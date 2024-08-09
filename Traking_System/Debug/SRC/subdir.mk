################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/ADC_program.c \
../SRC/DIO_program.c \
../SRC/External_Interrupt_program.c \
../SRC/GI_program.c \
../SRC/KEYPAD_program.c \
../SRC/LCD_program.c \
../SRC/LED_program.c \
../SRC/SSD_program.c \
../SRC/Timer_program.c \
../SRC/UART_Program.c \
../SRC/WDT_Program.c \
../SRC/app.c 

OBJS += \
./SRC/ADC_program.o \
./SRC/DIO_program.o \
./SRC/External_Interrupt_program.o \
./SRC/GI_program.o \
./SRC/KEYPAD_program.o \
./SRC/LCD_program.o \
./SRC/LED_program.o \
./SRC/SSD_program.o \
./SRC/Timer_program.o \
./SRC/UART_Program.o \
./SRC/WDT_Program.o \
./SRC/app.o 

C_DEPS += \
./SRC/ADC_program.d \
./SRC/DIO_program.d \
./SRC/External_Interrupt_program.d \
./SRC/GI_program.d \
./SRC/KEYPAD_program.d \
./SRC/LCD_program.d \
./SRC/LED_program.d \
./SRC/SSD_program.d \
./SRC/Timer_program.d \
./SRC/UART_Program.d \
./SRC/WDT_Program.d \
./SRC/app.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/%.o: ../SRC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


