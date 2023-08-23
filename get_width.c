#include "main.h"

/**
 * get_width - It_calculates_the_width_for_printing.
 * @format: This_is_a_formatted_string_in_that_print_the_arguments.
 * @i: This_is_an_arguments_to_be_printed.
 * @list: It_list_the_arguments.
 * Return: It must always return width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
