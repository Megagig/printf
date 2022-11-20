#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @arg_type: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */

typedef struct print
{
	char *arg_type;
	int (*f)(va_list, char *, unsigned int);
} print_type;

int _printf(const char *format, ...);
int print_buf(char *str, int buff);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int get_id_no(const char *s, int index);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);
int print_char(va_list arguments, char *buf, unsigned int ibuf);
int print_int(va_list arguments, char *buf, unsigned int ibuf);
int print_unt(va_list arguments, char *buf, unsigned int ibuf);
int print_hex(va_list arguments, char *buf, unsigned int ibuf);
int print_int(va_list arguments, char *buf, unsigned int ibuf);
int print_str(va_list arguments, char *buf, unsigned int ibuf);
int print_oct(va_list arguments, char *buf, unsigned int ibuf);
int print_upx(va_list arguments, char *buf, unsigned int ibuf)
#endif
