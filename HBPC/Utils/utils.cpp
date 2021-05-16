#include "utils.h"

#include <arduino.h>

int serial_putc(char c, FILE*)
{
	Serial.write(c);

	return c;
}

int printf_begin(void)
{
	fdevopen(&serial_putc, 0);
	return 1;
}

int printf_inited = printf_begin();


