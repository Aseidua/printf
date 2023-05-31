#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * fix_hex_code - Fix ascii in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @n: List of arguments to be printed.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int fix_hex_code(char ascii_code, char buffer[], int n)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hex format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[n++] = '\\';
	buffer[n++] = 'x';

	buffer[n++] = map_to[ascii_code / 16];
	buffer[n] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Sends a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsigned - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
