#include "main.h"

/***********************_WRITE_HANDLE_***********************/
/**
 * handle_write_char - It_prints_a_string.
 * @c: It's_char_types.
 * @buffer: The_buffer_array_will_handle_print.
 * @flags:  It_will_calculates_active_flags.
 * @width: get_width.
 * @precision: Precision_of_specifier
 * @size: Size_of_specifier
 *
 * Return: Always return number of chars printed.
 */

int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	/* char_is_stored_at_left_and_paddind_at_buffer's_right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/***********************_WRITE_NUMBER_***********************/

/**
 * write_number - It_prints_a_string.
 * @is_negative: This_Lists_of_arguments.
 * @ind: The_char_types.
 * @buffer: This_is_a_buffer_array_to_handle_print.
 * @flags: It_calculates_the_active_flags.
 * @width: get_width.
 * @precision: The_precision_of_specifier.
 * @size: The_size_specifier.
 *
 * Return: It returns number of chars printed.
 */

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - This_writes_a_number_using_a_bufffer.
 * @ind: The_Index_which_the_number_starts_on_the_buffer.
 * @buffer: The_buffer_array_to_handle_print.
 * @flags: It_calculates_the_active_flags.
 * @width: get_width.
 * @prec: The_precision_of_a_specifier.
 * @length: The_number_of_lengths.
 * @padd: The_Pading_of_ char.
 * @extra_c: The_extra_of_char.
 *
 * Return: Always return number of printed chars.
 */

int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no_char_is_printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width_is_displayed_with_padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign_extra_char_to_left_of_buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra_char_to_left_of_buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra_char_to_left_of_padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - This_writes_an_unsigned_number.
 * @is_negative: The_number_will_indicates_if_the_num_is_negative.
 * @ind: The_Index_at_which_the_number_starts_in_the_buffer.
 * @buffer: These_are_array_of_chars.
 * @flags: The_flags_specifiers.
 * @width: The_width_specifier.
 * @precision: The_precision_of_specifier.
 * @size: The_size_of_specifier.
 *
 * Return: Always returns number of written chars.
 */

int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The_number_is_stored_at_the_bufer's_right_and_starts_at_position_i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no_char_is_printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Assign_extra_char_to_left_of_buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Assign_extra_char_to_left_of_padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - This_Writes_a_memory_address.
 * @buffer: The_arrays_of_chars.
 * @ind: The_Index_at_which_the_number_start_in_the_buffer.
 * @length: The_length_of_the_ number.
 * @width: The_width_specifier.
 * @flags: The_flags_of_specifier.
 * @padd: The_char_that_is_representing_the_padding.
 * @extra_c: The_char_representing_the_extra_char.
 * @padd_start: The_Index_at_which_the_padding_should_start.
 *
 * Return: Always return number of written chars.
 */

int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Assign_extra_char_to_left_of_buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra_char_to_left_of_buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra_char_to_left_of_padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
