/*
 * This is a bit more interesting, it requires you to
 * use the serial port that the discovery board presents
 * in order to change the blink rate.
 */

#include <stdio.h>
#include <stdlib.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "../util/util.h"

int
main(void)
{
	float	blink_rate;
	char	buf[128];

	clock_setup();
	console_setup(115200);

	rcc_periph_clock_enable(RCC_GPIOJ);
	gpio_mode_setup(GPIOJ, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5 | GPIO13);
	gpio_clear(GPIOJ, GPIO5);
	gpio_set(GPIOJ, GPIO13);
	
	printf("\nBlink tool. press ^C to restart at any time.\n");
	while (1) {
		printf("Enter blink rate (in Hz): ");
		fflush(stdout);
		fgets(buf, 127, stdin);
		blink_rate = atof(buf);
		if (blink_rate < 0.000005) {
			printf("Enter a blink rate in Hertz\n");
		} else {
			uint32_t del;
			del = (uint32_t) (1000.0 / blink_rate);
			printf("\nBlinking at %f Hz ... \n", 1000.0 / (float) del);
			while(1) {
				gpio_toggle(GPIOJ, GPIO5 | GPIO13);
				msleep(del);
			}
		}
	}
}
