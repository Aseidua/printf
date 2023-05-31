#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * nab_size - Calculates the size to use for this argument
 * @b: List of arguments to be printed.
 * @format: The parameter in question
 * Return: Precision.
 */
int nab_size(const char *format, int *b)
{
	int curr_b = *b + 1;
	int size = 0;

	if (format[curr_b] == 'l')
		size = S_LONG;
	else if (format[curr_b] == 'h')
		size = S_SHORT;

	if (size == 0)
		*b = curr_b - 1;
	else
		*b = curr_b;

	return (size);
}
