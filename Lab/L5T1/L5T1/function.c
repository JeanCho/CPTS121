#include "Header.h"

int read_int(FILE *infile)
{
	int fint = 0;

	fscanf(infile, "%d", &fint);

	return fint;
}

char taxbracket(int income)
{
	char result='\0';
	if (income > 200000)
	{
		result = 'h';
	}

	else if (15000 < income && income <= 200000)
	{
		result = 'm';
	}

	else if (income <= 15000)
	{
		result = 'l';
	}
	else
	{
		result = taxbracket(income);
	}

	return result;



}
