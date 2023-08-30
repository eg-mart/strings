#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
	clock_t before = clock();
	const char *pattern = "abcdefghijklmnopqrstuvwxy"
						  "abcdefghijklmnopqrstuvwxy"
						  "abcdefghijklmnopqrstuvwxy"
						  "abcdefghijklmnopqrstuvwxy"
						  "abcdefghijklmnopqrstuvwxyz";
	FILE *fp = fopen("test.txt", "r");
	char line[49000];
	my_fgets(line, 49000, fp);
	clock_t diff = clock() - before;
	printf("reading file: %ld mcs\n\n", diff * 1000000 / CLOCKS_PER_SEC);

	before = clock();
	char *res = my_strstr_hash(line, pattern);
	diff = clock() - before;
	printf("hash:\t%4ld mcs,\taddress: %p\n", diff * 1000000 / CLOCKS_PER_SEC, res);

	before = clock();
	res = my_strstr(line, pattern);
	diff = clock() - before;
	printf("naive:\t%4ld mcs,\taddress: %p\n", diff * 1000000 / CLOCKS_PER_SEC, res);
	
	before = clock();
	res = strstr(line, pattern);
	diff = clock() - before;
	printf("stdlib:\t%4ld mcs,\taddress: %p\n", diff * 1000000 / CLOCKS_PER_SEC, res);

	return 0;
}
