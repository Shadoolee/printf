#include "main.h"

/**
 * get_size - This_calculates_the_size_to_cast_the_argument
 * @format: It's_a_formatted_string_in_which_to_print_all_the_arguments
 * @i: It_list_arguments_to_be_printed.
 * Return: It must always returns precision.
 */

int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	switch (format[curr_i])
	{
		case 'l':
			size = S_LONG;
			break;
		case 'h':
			size = S_SHORT;
			break;
		default:
			size = 0;
			curr_i--;
			break;
	}

	*i = curr_i;

	return (size);
}
