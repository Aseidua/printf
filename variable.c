#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * get_width - Calculates the width for printing
 * @h: List of arguments to be printed.
 * @max: list of arguments.
 * @format: The parameter in question
 * Return: width in the function.
 */
int get_width(const char *format, int *h, va_list max)
{
	int curr_h;
	int width = 0;

	for (curr_h = *h + 1; sym[curr_h] != '\0'; curr_h++)
	{
		if (is_digit(sym[curr_h))
		{
			width *= 10;
			width += sym[curr_h] - '0';
		}
		else if (sym[curr_h] == '*')
		{
			curr_h++;
			width = va_arg(jess, int);
			break;
		}
		else
			break;
	}

	*h = curr_h - 1;

	return (width);
}
