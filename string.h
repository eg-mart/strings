#include <stddef.h>
#include <stdio.h>

int my_puts(const char *s);
char *my_strchr(char *cs, char c);
size_t my_strlen(const char *cs);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, size_t n);
char *my_fgets(char *s, int n, FILE *stream);
char *my_strdup(char *s);
size_t my_getline(char *line, int max);
