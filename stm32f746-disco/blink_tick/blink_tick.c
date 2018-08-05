/*
 * This version of blink sets up the clock tree to generate
 * a nice solid 5 hz blink using the Systick timer with 1 mS
 * ticks as the reference.
 *
 * NB: Clock tree setup is in ../util/clock.c
 */

#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "../util/util.h"

int
main(void)
{
	clock_setup();
	rcc_periph_clock_enable(RCC_GPIOI);
	gpio_mode_setup(GPIOI, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO1);
	gpio_clear(GPIOI, GPIO1);
	while (1) {
		gpio_toggle(GPIOI, GPIO1);
		/* sleep 200 mS
		 *  ...defined in ../clock.c (api in ../util/util.h)
		 */
		msleep(200);
	}
}
