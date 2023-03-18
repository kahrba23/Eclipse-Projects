################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_programe.c \
../DIO_program.c \
../NRF_programe.c \
../PORT_Programe.c \
../SPI_programe.c \
../main.c 

OBJS += \
./CLCD_programe.o \
./DIO_program.o \
./NRF_programe.o \
./PORT_Programe.o \
./SPI_programe.o \
./main.o 

C_DEPS += \
./CLCD_programe.d \
./DIO_program.d \
./NRF_programe.d \
./PORT_Programe.d \
./SPI_programe.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


