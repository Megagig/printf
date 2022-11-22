#include "main.h"
/**
 *get_flags - acts responsively when a flag is invoked
 *@c:flag character
 *@f:struct flags pointer
 *Return:0 - flag invoked,1 otherwise
 */
int get_flags(char c, han_s *f)
{
	int i = 0;

	switch (c)
	{
	case '+':
		(*f).plus = 1;
		i = 1;
		break;
	case ' ':
		(*f).space = 1;
		i = 1;
		break;
	case '#':
		(*f).hash = 1;
		i = 1;
		break;
	case '-':
		(*f).minus = 1;
		i = 1;
		break;
	case '0':
		(*f).zero = 1;
		i = 1;
		break;
	}
	return (i);
}
