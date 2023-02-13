################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
CLCD_4BIT.lss \

FLASH_IMAGE += \
CLCD_4BIT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: CLCD_4BIT.elf secondary-outputs

# Tool invocations
CLCD_4BIT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CLCD_4BIT.map -mmcu=atmega328p -o "CLCD_4BIT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CLCD_4BIT.lss: CLCD_4BIT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CLCD_4BIT.elf  >"CLCD_4BIT.lss"
	@echo 'Finished building: $@'
	@echo ' '

CLCD_4BIT.hex: CLCD_4BIT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex CLCD_4BIT.elf  "CLCD_4BIT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CLCD_4BIT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p CLCD_4BIT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CLCD_4BIT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
