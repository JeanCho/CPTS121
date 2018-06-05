#include "Header.h"

int factorial(int num)
{
	int fact = 1, i = 1;

	while (i <= num)
	{
		fact = fact*i;
		i += 1;
	}

	return fact;

}