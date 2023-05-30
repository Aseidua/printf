#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Prints formatted output to the standard output stream.
 * @format: A string that specifies the output format.
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

 int count = 0;
const char *ptr = format;

    while (*ptr != '\0')
    {
        if (*ptr == '%')
        {
            ptr++;


            switch (*ptr)
            {
                case '%':
                {
                    putchar('%');
                    count++;
                    break;
                }
                case 'C':
                {
                    int ch = va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                }
                case 'S':
                {
                    char *str = va_arg(args, char *);
                    fputs(str, stdout);
                    count += strlen(str);
                    break;
                }

            }
        }
        else
        {
            putchar(*ptr);
            count++;
        }

        ptr++;
    }

    va_end(args);

    return count;
}
