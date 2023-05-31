#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - This will print a character to the terminal
 * @chr:  The list of arguments in this function
 * @buffer: The array of buffer to handle  print
 * @flags:  This will round up the active flags in this function
 * @width: The width in question
 * @precision: The precision in question
 * @size: The size in question
 * Return: The total number of  characters to be displayed
 */
int print_char(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(chr, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string -  This will print string to the terminal
 * @chr: The arguments in this function
 * @buffer: This array of buffer will handle the print
 * @flags:  This will round up the active flags in this function
 * @width: The width in question
 * @precision: The precision specification in the function
 * @size: The size specifier in this function
 * Return: The total number of characters  to be printed
 */
int print_string(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, s;
	char *str = va_arg(chr, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; k > 0; k--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; s > 0; k--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent - This will print a percent sign to the terminal
 * @chr: The arguments in the function
 * @buffer: The array of buffer to print
 * @flags:  This rounds up active flags in the function
 * @width: The width in question
 * @precision: The precision in the question
 * @size: The size specifier in the function
 * Return: The number of characters to be displayed
 */
int print_percent(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 * print_int -  This is the print int functiona
 * @chr:  The arguments in this functions
 * @buffer: The buffer array to display the print
 * @flags:  This will round up the active flags in the function
 * @width: This will help acquire the  width in this function
 * @precision: This represents the precision specifier of this function
 * @size: This is the size specifier in this function
 * Return: The total number of characters to ben displayed
 */
int print_int(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	int q = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(chr, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_number(is_negative, c, buffer, flags, width, precision, size));
}

/**
 * print_binary -  This will display an unsigned number
 * @chr:  The arguments in this function
 * @buffer: The buffer of array to display the print in this function
 * @flags:  This will round up the active flags of this function
 * @width:  This will attain the width of this function
 * @precision:  This will specify the precision needed
 * @size: This will specify the size needed
 * Return: The total number of characters to be displayed
 */
int print_binary(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int e, r, n, sum;
	unsigned int t[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	e = va_arg(types, unsigned int);
	r = 2147483648; /* (2 ^ 31) */
	t[0] = e / r;
	for (n = 1; n < 32; n++)
	{
		r /= 2;
		a[n] = (e / r) % 2;
	}
	for (n = 0, sum = 0, count = 0; n < 32; n++)
	{
		sum += a[n];
		if (sum || n == 31)
		{
			char z = '0' + a[n];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

