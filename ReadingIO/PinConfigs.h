#pragma once
//#include "stm32f0xx_hal_gpio.h"

//Port B
#define LT_in GPIO_PIN_7
#define RT_in GPIO_PIN_6

#define Cruise_in GPIO_PIN_5
#define Cplus_in GPIO_PIN_4
#define Cminus_in GPIO_PIN_3

//Port D
#define Hazards_in GPIO_PIN_2

//Port C
#define Headlights_in GPIO_PIN_12
#define Regen_in GPIO_PIN_11
#define Reverse_in GPIO_PIN_10

//Port A
#define Eco_in GPIO_PIN_0
#define Horn_in GPIO_PIN_1
#define CLED_out GPIO_PIN_2
