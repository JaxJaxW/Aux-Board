################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subsystem-can-driver/helper-code/subdir.mk
-include Core/Src/subsystem-can-driver/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SolarGators_Auxiliary_SteeringWheelPROTOTYPE_V0.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SolarGators_Auxiliary_SteeringWheelPROTOTYPE_V0.list \


# All Target
all: SolarGators_Auxiliary_SteeringWheelPROTOTYPE_V0.elf secondary-outputs

# Tool invocations
SolarGators_Auxiliary_SteeringWheelPROTOTYPE_V0.elf: $(OBJS) $(USER_OBJS) D:\Documents\Solar\ Gators\ Programming\SolarGators_Auxiliary_SteeringWheelPROTOTYPE_V0\STM32F072RBTX_FLASH.ld
	arm-none-eabi-g++ -o "SolarGators_Auxiliary_SteeringWheelPROTOTYPE_V0.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"D:\Documents\Solar Gators Programming\SolarGators_Auxiliary_SteeringWheelPROTOTYPE_V0\STM32F072RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="SolarGators_Auxiliary_SteeringWheelPROTOTYPE_V0.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SolarGators_Auxiliary_SteeringWheelPROTOTYPE_V0.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SolarGators_Auxiliary_SteeringWheelPROTOTYPE_V0.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
