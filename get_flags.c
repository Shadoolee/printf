#include "main.h"

/**
 * get_flags - It_calculates_all_active_flags.
 * @format: The_formatted_string_in_which_to_print_all_the_arguments.
 * @i: It_takes_a_parameter.
 * Return: It must always returns flags:
 */

int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		int flag_found = 0;

		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				flag_found = 1;
				break;
			}
		}

		if (!flag_found)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
