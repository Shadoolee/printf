#include "main.h"

/***********************_PRINT_UNSIGNED_NUMBER_***********************/
/**
 * print_unsigned - Prints_an_unsigned_number
 * @types: List_a_of_arguments
 * @buffer: Buffer_array_to_handle_print
 * @flags: Calculates_active flags
 * @width: get_width
 * @precision: Precision_specification
 * @size: Size_specifier
 * Return: Number of chars printed
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*************_PRINT_UNSIGNED_NUMBER_IN_OCTAL_****************/
/**
 * print_octal - Prints_an_unsigned_number_in_octal_notation
 * @types: Lista_of_arguments
 * @buffer: Buffer_array_to_handle_print
 * @flags: Calculates_active_flags
 * @width: get_width
 * @precision: Precision_specification
 * @size: Size_specifier
 * Return: Number of chars printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************_PRINT_UNSIGNED_NUMBER_IN_HEXADECIMAL_************/
/**
 * print_hexadecimal - Prints_an_unsigned_number_in_hexadecimal_notation
 * @types: List_types_of_arguments
 * @buffer: Buffer_array_to_handle_print
 * @flags: Calculates_active_flags
 * @width: get_width
 * @precision: Precision_specification
 * @size: Size_of_specifier
 * Return: Number of chars printed
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/***********_PRINT_UNSIGNED_NUMBER_IN_UPPER_HEXADECIMAL_************/
/**
 * print_hexa_upper - Prints_an_unsigned_number_in_upper_hexadecimal_notation
 * @types: List_types_of_arguments
 * @buffer: Buffer_array_to_handle_print
 * @flags: Calculates_the_active_flags
 * @width: get_width
 * @precision: Precision_specification
 * @size: Size_of_specifier
 * Return: Number of chars printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************_PRINT_HEXA_NUM_IN_LOWER_OR_UPPER_************/
/**
 * print_hexa - Prints_a_hexadecimal_number_in_lower_or_upper
 * @types: List_of_arguments
 * @map_to: Array_of_the_ values_to_map_the_number_to
 * @buffer: Buffer_array_to_handle_print
 * @flags:  Calculates_active_flags
 * @flag_ch: Calculates_active flags_ch
 * @width: get_width
 * @precision: Precision_specification
 * @size: Size_the_specifier
 * @size: Size_the_ specification
 * Return: Number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
