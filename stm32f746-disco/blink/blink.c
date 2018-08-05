/*
 * The canonical minimal example, use the default clock
 * tree and blink USER LED #1 (connected to PI1).
 * The simple delay gives about an 8 hz blink.
 * NB: The LED is hard to see, it is next to the black pushbutton
 */
#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int
main(void)
{
	rcc_periph_clock_enable(RCC_GPIOI);
	gpio_mode_setup(GPIOI, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO1);
	gpio_clear(GPIOI, GPIO1);

	while (1) {
		gpio_toggle(GPIOI, GPIO1);
		for (int i = 0; i < 1000000; i++) {
			__asm__("NOP");
		}
	}
}
