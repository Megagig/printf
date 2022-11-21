#include "main.h"

/**
<<<<<<< HEAD
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
=======
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], ibuf), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buffer, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
>>>>>>> b77708640c0f57f7e864666049b42b006affa18e
	return (len);
}
