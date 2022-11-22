#include "main.h"

/**
 *get_modifier - finds the modifier and invokes corresponding func
 *@s:format string
 *@handler:handler struct
 *Return:1 if modifier is valid
 */
int get_modifier(char *s, han_s *handler)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = 1;
		handler->h_mod = 1;
		break;
	case 'l':
		i = 1;
		handler->l_mod = 1;
		break;
	}
	return (i);
}
