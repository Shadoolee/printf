#include "main.h"

/**
 * get_precision - This_will_calculate_the_precision_for_printing
 * @format: The_formatted _string_in_which_to_print_the_arguments
 * @i: It_list_all_of_the_arguments_to_be_printed.
 * @list: This_will_list_all_of_arguments.
 * Return: It must always return precision
 */

int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = curr_i - 1;

	return (precision);
}
