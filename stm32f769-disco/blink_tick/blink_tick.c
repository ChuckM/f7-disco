/*
 * This version of blink sets up the clock tree to generate
 * a nice solid 5 hz blink using the Systick timer with 1 mS
 * ticks as the reference. It puts out a heartbeat tick on
 * CN2 so you can connect an oscilloscope and see how accurate
 * it is.
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
	rcc_periph_clock_enable(RCC_GPIOJ);
	gpio_mode_setup(GPIOJ, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13 | GPIO5);
	gpio_clear(GPIOJ, GPIO13);
	gpio_set(GPIOJ, GPIO13);
	while (1) {
		gpio_toggle(GPIOJ, GPIO5 | GPIO13);
		/* sleep 200 mS
		 *  ...defined in ../clock.c (api in ../util/util.h)
		 */
		msleep(200);
	}
}
