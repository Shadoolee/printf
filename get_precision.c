#include "main.h"

/**
 * get_precision - This_will_calculate_the_precision_for_printing
 * @format: The_formatted _string_in_which_to_print_the_arguments
 * @i: Pointer_to_the_current_index_in_the_format_string
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
	curr_i++; /* Move_past_the_dot_character */

	if (format[curr_i] == '*')
	{
		precision = va_arg(list, int);
		curr_i++; /* Move_past_the '*' */
	}
	else
	{
		while (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
			curr_i++;
		}
	}

	*i = curr_i - 1;

	return (precision);
}
