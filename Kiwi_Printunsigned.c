#include "main.h"
#include <stdarg.h>
#include <unistd.h>


/**
 * print_unsigned -  This will display an unsigned number to the terminal
 * @chr:  The arguments being used in the function
 * @buffer: The array of buffer to display output
 * @flags:  This rounds up the active flags of this function
 * @width: This reference width in the function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_unsigned(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(chr, unsigned long int);

	num = convert_size_unsigned int(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	l++;

	return (draft_unsigned int(0, a, buffer, flags, width, precision, size));
}

/**
 * print_oct -  This displays an unsigned int nr in octal notation
 * @chr: The arguments in the function
 * @buffer: The array of buffer to display the output
 * @flags:  This will round up the active flags of this function
 * @width: This will help acquire the  width in this function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_oct(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{

	int c = BUFF_SIZE - 2;
	unsigned long int num = va_arg(chr, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned int(num, size);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[c--] = '0';

	c++;

	return (draft_unsigned int(0, c, buffer, flags, width, precision, size));
}
/**
 * print_hex - This displays an unsigned int in hexadecimal notation
 * @chr: The arguments in this function
 * @buffer: The array of buffer to display the output
 * @flags:  This will round up the active flags of this function
 * @width: This will help acquire the  width in this function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_hex(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(chr, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_HEXA- This displays an unsigned int in upper hexadecm notation
 * @chr: The arguments in this function
 * @buffer: The array of buffer to display the output
 * @flags: This will round up the active flags of this function
 * @width: This will help acquire the  width in this function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_HEXA(va_list chr, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_HEXA(chr, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hex - This will display a hexadecimal number in lower or upper
 * @chr: The arguments in this function
 * @map_to: The array of values to map the number to
 * @buffer: The array of buffer to display the output
 * @flags: This will round up the active flags of this function
 * @flag_ch: This will round up the active flags in the function
 * @width: This will help acquire the  width in this function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_hex(va_list chr, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int f = BUFF_SIZE - 2;
	unsigned long int num = va_arg(chr, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[f--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[f--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[f--] = flag_ch;
		buffer[f--] = '0';
	}

	f++;

	return (draft_unsigned int(0, f, buffer, flags, width, precision, size));
}
