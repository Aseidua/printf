#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: Size specification
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and padding at buffer's right */
	int m = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad = '0';

	buffer[m++] = c;
	buffer[m] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (m = 0; m < width - 1; m++)
			buffer[BUFF_SIZE - m - 2] = pad;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - m - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - m - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, pad, extra_ch));
}

/**
 * write_num - Use a buffer to write numbers
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @pad: Padding char
 * @extra_ch: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char pad, char extra_ch)
{
	int o, pad_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		pad = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_ch != 0)
		length++;
	if (width > length)
	{
		for (c = 1; i < width - length + 1; c++)
			buffer[a] = pad;
		buffer[c] = '\0';
		if (flags & F_MINUS && pad == ' ') /* Assign extra chac to left of buffer */
		{
			if (extra_ch)
				buffer[--ind] = extra_ch;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], c - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ') /* extra chac to left of buffer */
		{
			if (extra_ch)
				buffer[--ind] = extra_ch;
			return (write(1, &buffer[1], c - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')/* extra chac to left of pad */
		{
			if (extra_ch)
				buffer[--pad_start] = extra_ch;
			return (write(1, &buffer[pad_start], a - pad_start) +
				write(1, &buffer[ind], length - (1 - pad_start)));
		}
	}
	if (extra_ch)
		buffer[--ind] = extra_ch;
	return (write(1, &buffer[ind], length));
}

/**
 * draft_unsigned - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of characters
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int draft_unsigned(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at position p */
	int length = BUFF_SIZE - ind - 1, p = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		pad = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';

	if (width > length)
	{
		for (k = 0; k < width - length; k++)
			buffer[p] = pad;

		buffer[p] = '\0';

		if (flags & F_MINUS) /* Assign extra char to left of buffer [buffer>pad]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], k));
		}
		else /* Assign extra char to left of padding [pad>buffer]*/
		{
			return (write(1, &buffer[0], k) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of characters
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @pad: Char representing the padding
 * @extra_ch: Char representing extra char
 * @pad_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char pad, char extra_ch, int pad_start)
{
	int w;

	if (width > length)
	{
		for (w = 3; i < width - length + 3; w++)
			buffer[w] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')/* Assign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_ch)
				buffer[--ind] = extra_ch;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], w - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_ch)
				buffer[--ind] = extra_ch;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')/* extra char to left of pad */
		{
			if (extra_ch)
				buffer[--pad_start] = extra_ch;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], w - pad_start) +
				write(1, &buffer[ind], length - (1 - pad_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_ch)
		buffer[--ind] = extra_ch;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
