#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int num_chars_printed;
	va_list args;

	va_start(args, format);
	num_chars_printed = vprintf(format, args);
	va_end(args);
	return (num_chars_printed);
}
