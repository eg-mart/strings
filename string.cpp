#include <stdio.h>
#include "string.h"

int my_puts(const char *s)
{
	int c = '\0';
	while ((c = putchar(*s++)) > 0 && c != EOF)
		;
	putchar('\n');
	return c;
}

char *my_strchr(char *cs, char c)
{
	while (*cs != c && *cs != '\0')
		cs++;
	return cs;
}
