#include "Header.h"

main(void)
{
	int result = 0;
	FILE *infile = NULL;
	
	infile = fopen("numlist.txt", "r");
	result = read_file(infile);
	printf("Sum of all number:%d\n\n", result);
	check_prime(result);

	return 0;

}