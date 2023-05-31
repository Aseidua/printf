#include "main.h"

/**
 * get_flags - Calculates active flags of this function
 * @format: Formatted string in which to print the arguments
 * @d: take a parameter in question
 * Return: Flags in the function
 */
int get_flags(const char *format, int *d)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int b, curr_d;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_d = *d + 1; format[curr_d] != '\0'; curr_d++)
	{
		for (b = 0; FLAGS_CH[b] != '\0'; b++)
			if (format[curr_d] == FLAGS_CH[b])
			{
				flags |= FLAGS_ARR[b];
				break;
			}

		if (FLAGS_CH[b] == 0)
			break;
	}

	*d = curr_d - 1;

	return (flags);
}
