/*
 * The canonical minimal example, use the default clock
 * tree and blink USER LED #1 (connected to PJ13).
 * The simple delay gives about a 6 hz blink.
 */
#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int
main(void)
{
	rcc_periph_clock_enable(RCC_GPIOJ);
	gpio_mode_setup(GPIOJ, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
	gpio_clear(GPIOJ, GPIO13);

	while (1) {
		gpio_toggle(GPIOJ, GPIO13);
		for (int i = 0; i < 1000000; i++) {
			__asm__("NOP");
		}
	}
}
