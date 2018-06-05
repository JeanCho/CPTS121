#include "Header.h"


int read_file(FILE* infile)
{
	int num = 0,alladd=0;
	while (!feof(infile))
	{


		fscanf(infile, "%d", &num);
		alladd += num;
	}

	return alladd;

}

void check_prime(int sum)
{
	int i = 2,check=0,pon=0;
	while (i<(sum+1))
	{
		check = sum%i;
		if (check==0)
		{
			pon += 1;
		}

		i += 1;
	}
	if (pon > 1)
	{
		printf("It's not a prime number\n");

	}

	else
	{
		printf("it's prime\n");
	}

}