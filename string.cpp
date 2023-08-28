#include <stdlib.h>
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

size_t my_strlen(const char *cs)
{
	size_t i = 0;
	while (*cs++)
		i++;
	return i;
}

char *my_strcpy(char *dest, const char *src)
{
	char *tmp = dest;
	while ((*tmp++ = *src++))
		;
	return dest;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
	char *tmp = dest;
	while ((*tmp++ = *src++) && --n > 0)
		;
	return dest;
}

char *my_strcat(char *dest, const char *src)
{
	char *tmp = dest;
	while (*tmp != '\0')
		tmp++;
	while ((*tmp++ = *src++))
		;
	return dest;
}

char *my_strncat(char *dest, const char *src, size_t n)
{
	char *tmp = dest;
	while (*tmp != '\0')
		tmp++;
	while ((*tmp++ = *src++) && --n > 0)
		;
	*tmp = '\0';
	return dest;
}

char *my_fgets(char *s, int n, FILE *stream)
{
	char *tmp = s;
	int c;
	while (--n > 0 && (c = fgetc(stream)) != EOF)
		if ((*tmp++ = (char) c) == '\n')
			break;

	if (c == EOF && (tmp == s || ferror(stream)))
		return NULL;

	*tmp = '\0';
	return s;
}

char *my_strdup(char *s)
{
	char *p;

	p = (char*) malloc(my_strlen(s) + 1);
	if (p != NULL)
		my_strcpy(p, s);
	return p;
}

size_t my_getline(char *line, int max)
{
	if (my_fgets(line, max, stdin) == NULL)
		return 0;
	return my_strlen(line);
}