#include "string.h"
#include <stdio.h>

int main()
{
	my_puts("testing function puts...");
	char *v = strchr("find a letter here", 't');
	printf("%c%c%c", *(v - 1), *v, *(v + 1));

	return 0;
}
