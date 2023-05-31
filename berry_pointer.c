#include "main.h"
#include <stdarg.h>
#include <unistd.h>


/**
 * print_pointer - Prints the value of a pointer variable
 * @chr: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags of this function
 * @width: get width of this function
 * @precision: Precision specification in the function
 * @size: Size specifier needed in this function
 * Return: Number of characters printed.
 */
int print_pointer(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_ch = 0, pad = ' ';
	int ind = BUFF_SIZE - 2, length = 2, pad_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(chr, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		extra_ch = '+', length++;
	else if (flags & F_SPACE)
		extra_ch = ' ', length++;

	ind++;

	/*return (write(1, &buffer[g], BUFF_SIZE - g - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, pad, extra_ch, pad_start));
}

/**
 * print_non_printable - Prints ascii codes in hexadecimal
 * @chr: List of arguments in this function
 * @buffer: Buffer array to handle the output
 * @flags:  Calculates active flags of this function
 * @width: get width of this function
 * @precision: Precision specification needed
 * @size: Size specifier in this function
 * Return: Number of chars printed
 */
int print_non_printable(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = 0, offset = 0;
	char *str = va_arg(est, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a + offset] = str[a];
		else
			offset += fix_hex_code(str[a], buffer, a + offset);

		a++;
	}

	buffer[a + offset] = '\0';

	return (write(1, buffer, a + offset));
}

/**
 * print_rev - Prints the reverse format of the string.
 * @chr: Arguments in the function
 * @buffer: Buffer array to handle the output
 * @flags:  Calculates active flags of this function
 * @width: get width of this function
 * @precision: Precision specification needed
 * @size: Size specifier in this function
 * Return: Numbers of chars printed
 */

int print_rev(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int a, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (a = 0; str[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char z = str[a];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @chr: brief of arguments in this function
 * @buffer: Buffer array to handle the output
 * @flags:  Calculates active flags in this function
 * @width: Get the  width in this function
 * @precision: Precision specification needed
 * @size: Size specifier needed in this function
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int a, b;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(chr, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				x = out[b];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[b])
		{
			x = str[a];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
