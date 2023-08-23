#include "main.h"

/**
 * is_printable - This_will_evaluate_if_a_char_is_printable_or_not.
 * @c: The_char_to_be_evaluated.
 * Return: It must always returns 1 if c is printable, otherwise returns 0
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}

	return (0);
}

/**
 * append_hexa_code - It_append_ASCII_code_in_hexadecimal_code_to_buffers.
 * @buffer: This_is_the_array_of_chars.
 * @i: The_Index_at_which_to_start_appending.
 * @ascii_code: This_provides_ASCII_CODE.
 * Return: It must always returns 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	/* Hexadecimal_format_code_is_always 2 digits_long */
	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - This_verifies_if_a_char_is_a_digit.
 * @c: The_char_to_be_evaluated.
 * Return: It must always returns 1 if c is a digit, otherwise returns 0
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}

	return (0);
}

/**
 * convert_size_number - This_casts_a_number_to_the_specified_size.
 * @num: The_number_must_be_casted.
 * @size: The_number_that_is_indicating_the_type_to_be_must_always_be_casted.
 *
 * Return: Always casted value of num
 */

long int convert_size_number(long int num, int size)
{
	switch (size)
	{
		case S_LONG:
			return num;
		case S_SHORT:
			return (short)num;
		default:
			return (int)num;
	}
}

/**
 * convert_size_unsgnd - This_will_cast_a_number_to_the_specified_size.
 * @num: The_number_must_be_casted.
 * @size: The_number_indicating_the_type_must_be_casted.
 *
 * Return: Always casted value of num
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	switch (size)
	{
		case S_LONG:
			return num;
		case S_SHORT:
			return (unsigned short)num;
		default:
			return (unsigned int)num;
	}
}
