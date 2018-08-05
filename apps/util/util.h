/*
 * Prototype for the utility functions used in multiple demos
 *
 * Peripherals on the discovery card:
 *	Serial port USART1
 *	LEDs -  LED1 PJ13, LED2 PJ5, Arduino PA12, overcurrent PD4
 *	Clock source - 25Mhz external clock (HSE)
 */
#pragma once
#include <stdint.h>

/** set up clock tree and systick counter */
void clock_setup(void);

/** sleep for 'ms' milleseconds */
void msleep(uint32_t ms);

