/*
 * clock.c 
 *
 * Bare minimum clock functions for the board.
 *
 * Copyright (C) 2018, Charles McManis
 * Contributed to the public domain, August 2018
 */

#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>
#include "../util/util.h"

static volatile uint32_t __systick_millis;
static volatile uint32_t __systick_delay;
void
sys_tick_handler(void)
{
	++__systick_millis;
	if (__systick_delay > 0) {
		--__systick_delay;
	}
}

/*
 * Set up the clock for 168Mhz and enable
 * the SysTick handler to run every millisecond.
 */
void
clock_setup(void)
{
	rcc_clock_setup_hse(&rcc_3v3[RCC_CLOCK_3V3_168MHZ], 25);

	/* set up the SysTick subsystem */
	systick_set_reload(168000);
	systick_set_clocksource(STK_CSR_CLKSOURCE_AHB);
	systick_counter_enable();
	systick_interrupt_enable();

}

void
msleep(uint32_t ms)
{
	__systick_delay = ms;
	while (__systick_delay > 0) { __asm__("nop"); }
}
