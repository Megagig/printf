#include "main.h"

/**
 * _printf - printf function main source code
 * @format: the format code args
 * Takes variable number arguments
 * Return: returns string length
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, o, len = 0;

	matchConversion match[] = {
		{"%s", printf_string},
		{"%c", printf_char}, {"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec},
		{"%r", printf_srev}, {"%R", printf_rot13},
		{"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex},
		{"%X", printf_HEX}, {"%S", printf_exclusive_string},
		{"%p", printf_pointer}};

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] != '\0'))
		return (-1);
Here:
	while (format[i] != '\0')
	{
		o = 13;
		while (o >= 0)
		{
			if (match[o].id[0] == format[i] && match[o].id[1] == format[i + 1])
			{
				len += match[o].f(args);
				i = i + 2;
				goto Here;
			}
			o--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
