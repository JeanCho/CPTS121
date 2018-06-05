#include "Header.h"

int main(void)
{
	int num = 33,fnum=0,i=1;

	fnum = fspark(num);
	fibonacci(fnum);
	while (i<num+1)
	{
		fnum = fspark(i);
		fibonacci(fnum);
		i += 1;
	}


	return 0;
}