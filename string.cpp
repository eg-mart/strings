#include <stdio.h>
#include "string.h"

int my_puts(const char *s)
{
	int c = '\0';
	while ((c = putchar(*s++)) > 0)
		;
	putchar('\n');
	return c;
}

char *strchr(char *cs, char c)
{
	while (*cs++ != c)
		;
	return --cs;
}
