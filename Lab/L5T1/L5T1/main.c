#include "Header.h"


int main(void)
{
	FILE *infile = NULL;
	int income1 = 0, income2 = 0, income3 = 0, income4 = 0,total=0;
	char result = '\0';
	infile = fopen("salaries.txt", "r");
	income1 = read_int(infile);
	income2 = read_int(infile);
	income3 = read_int(infile);
	income4 = read_int(infile);
	total = income1 + income2 + income3 + income4;
	result = taxbracket(total);
	printf("%c\n", result);

	return 0;
}