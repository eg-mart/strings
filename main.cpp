#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
	const char *pattern = "klmnopqrstuvwxyz";
	FILE *fp = fopen("test.txt", "r");
	char line[49000];
	my_fgets(line, 49000, fp);

	clock_t before = clock();
	char *res = my_strstr_hash(line, pattern);
	clock_t diff = clock() - before;
	printf("hash: %ld mcs, addres: %p\n", diff * 1000000 / CLOCKS_PER_SEC, res);

	before = clock();
	res = my_strstr(line, pattern);
	diff = clock() - before;
	printf("without hash: %ld mcs, addres: %p\n", diff * 1000000 / CLOCKS_PER_SEC, res);
	
	before = clock();
	res = strstr(line, pattern);
	diff = clock() - before;
	printf("stdlib: %ld mcs, addres: %p\n", diff * 1000000 / CLOCKS_PER_SEC, res);

	return 0;
}
