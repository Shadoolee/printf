#include "main.h"

/**
 * handle_print - This_will_prints_an_argument_based_on_its_type.
 * @fmt: It's_a_formatted_string_in_which_to_print_the_arguments.
 * @list: It_list_all_of_the_arguments_to_be_printed.
 * @ind: The_Index.
 * @buffer: This_is_a_buffer_array_to_handle_print.
 * @flags: This_calculates_all_the_active_flags.
 * @width: get_width
 * @precision: The_precision_specification.
 * @size: Size_of_specifier.
 * Return: Always return 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
		{
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
		}
	}

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
		{
			return (-1);
		}

		unknow_len += write(1, "%%", 1);

		if (fmt[*ind - 1] == ' ')
		{
			unknow_len += write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
			{
				--(*ind);
			}
			if (fmt[*ind] == ' ')
			{
				--(*ind);
			}
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}

	return (printed_chars);
}
