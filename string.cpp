#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "string.h"

struct Hash {
	unsigned long value;
	unsigned long coeff;
	unsigned long last_coeff;
};

struct Hash hash(const char *s, size_t n);
unsigned long my_pow(unsigned long x, unsigned long n);

int my_puts(const char *s)
{
	assert(s != NULL);
	
	int c = '\0';
	while (*s != '\0' && c != EOF)
		c = putchar(*s++);
	putchar('\n');
	return c;
}

char *my_strchr(char *cs, char c)
{
	assert(cs != NULL);

	while (*cs != c && *cs != '\0')
		cs++;
	if (*cs == '\0' && c != '\0')
		return NULL;
	return cs;
}

size_t my_strlen(const char *cs)
{
	assert(cs != NULL);

	size_t i = 0;
	while (*cs++ != '\0')
		i++;
	return i;
}

char *my_strcpy(char *dest, const char *src)
{
	assert(dest != NULL);
	assert(src != NULL);

	char *tmp = dest;
	while ((*tmp++ = *src++) != '\0') {
		putchar('\0');
	}
	return dest;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
	assert(dest != NULL);
	assert(src != NULL);

	char *tmp = dest;
	while ((*tmp++ = *src++) != '\0' && --n > 0)
		;
	return dest;
}

char *my_strcat(char *dest, const char *src)
{
	assert(dest != NULL);
	assert(src != NULL);

	char *tmp = dest;
	while (*tmp != '\0')
		tmp++;
	while ((*tmp++ = *src++) != '\0')
		;
	return dest;
}

char *my_strncat(char *dest, const char *src, size_t n)
{
	assert(dest != NULL);
	assert(src != NULL);

	char *tmp = dest;
	while (*tmp != '\0')
		tmp++;
	while ((*tmp++ = *src++) != '\0' && --n > 0)
		;
	*tmp = '\0';
	return dest;
}

char *my_fgets(char *s, size_t n, FILE *stream)
{
	assert(s != NULL);
	assert(stream != NULL);
	
	char *tmp = s;
	int c = 0;
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
	assert(s != NULL);
	
	char *p = NULL;

	p = (char*) calloc(my_strlen(s) + 1, sizeof(char));
	if (p != NULL)
		my_strcpy(p, s);
	return p;
}

size_t my_getline(char **line, size_t *max, FILE *stream)
{
	assert(line != NULL);
	assert(stream != NULL);
	assert(max != NULL);
	assert((*line == NULL && *max == 0) || *line != NULL);

	const size_t BUFF_SIZE = 1024;
	
	char *buff = (char*) calloc(BUFF_SIZE, sizeof(char));
	if (buff == NULL)
		return 0;
	int capacity = BUFF_SIZE;
	int c = 0;
	int cnt = 1;

	size_t n = 0;
	while ((c = fgetc(stream)) != EOF) {
		buff[n] = (char) c;
		capacity--;
		n++;

		if (capacity <= 0) {
			buff = (char*) realloc(buff, ++cnt * BUFF_SIZE * sizeof(char));
			if (buff == NULL)
				return 0;
			capacity = BUFF_SIZE;
		}

		if (c == '\n')
			break;
	}

	if (c == EOF && (n == 0 || ferror(stream)))
		return 0;

	buff[n] = '\0';
	
	if (*line == NULL || *max == 0) {
		*line = (char*) calloc(n, sizeof(char));
		if (*line == NULL)
			return 0;
		*max = n;
	} else if (*max < n) {
		*line = (char*) realloc(*line, n);
		if (*line == NULL)
			return 0;
		*max = n;
	}

	my_strcpy(*line, buff);

	return n;
}

unsigned long my_pow(unsigned long x, unsigned long n)
{
	if (n == 1)
		return x;
	if (n % 2 == 1)
		return x * my_pow(x, n - 1);
	unsigned long tmp = my_pow(x, n / 2);
	return tmp * tmp;
}

struct Hash hash(const char *s, size_t n)
{
	unsigned long last_coeff = 1;
	for (size_t i = 0; i < n - 1; i++)
		last_coeff = last_coeff << 5;
	unsigned long hash = 0;

	while (n-- > 0) {
		hash = hash << 5;
		hash = hash + (unsigned long) *s++;
	}

	return { hash, 0, last_coeff };
}

char *my_strstr_hash(const char *str, const char *pattern)
{
	size_t p_len = my_strlen(pattern);
	struct Hash p_hash = hash(pattern, p_len);
	struct Hash str_hash = hash(str, p_len);

	for (size_t i = 0; str[i + p_len - 1] != '\0'; i++) {
		if (str_hash.value == p_hash.value) {
			bool flag = true;
			for (size_t j = 0; j < p_len; j++) {
				if (str[i + j] != pattern[j]) {
					flag = false;
					break;
				}
			}

			if (flag)
				return (char*) str + i;
		}
		
		str_hash.value = str_hash.value - (unsigned long) str[i] * str_hash.last_coeff;
		str_hash.value = str_hash.value << 5;
		str_hash.value = str_hash.value + (unsigned long) str[i + p_len];
	}

	return NULL;
}
	

char *my_strstr(const char *str, const char *pattern)
{
	assert(str != NULL);
	assert(pattern != NULL);

	const char *tmp = pattern;
	const char *pos = str;

	while (*str != '\0') {
		pos = str;
		while (*tmp == *str) {
			if (*tmp == '\0' || *str == '\0')
				break;
			tmp++;
			str++;
		}
		if (*tmp == '\0')
			return (char*) pos;
		tmp = pattern;
		str = pos + 1;
	}

	return NULL;
}