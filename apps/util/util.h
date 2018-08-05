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

typedef enum term_colors_enum {
	NONE, RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE
} TERM_COLOR;

void console_setup(int baud_rate);
uint32_t console_getnumber (void);
void console_color_disable(void);
void console_color_enable(void);
char *console_color(TERM_COLOR c);
void console_baud(int baud_rate);
int console_gets(char *s, int len);
void console_puts(char *s);
char console_getc(int wait);
void console_putc(char c);

