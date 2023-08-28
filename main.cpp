#include "string.h"
#include <stdio.h>

int main()
{
	my_puts("testing function puts...");
	char *v = my_strchr("find a letter here", 't');
	printf("%c%c%c\n", *(v - 1), *v, *(v + 1));
	printf("%lu\n", my_strlen("hello"));
	char dest[10] = "";
	char src[] = "ABC";
	printf("%s", my_strcpy(dest, src));
	printf("%s", my_strcat(dest, "DEF"));
	char f[512] = "";

	printf("%lu\n", my_getline(f, 512));
	my_puts(f);

	return 0;
}
