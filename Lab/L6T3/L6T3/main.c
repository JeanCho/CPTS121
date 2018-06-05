#include "Header.h"

void fibonacci(int num)
{
	printf("Fibonacci:%d\n\n", num);

}
	
int fspark(int num)
{
	int fn = 0;
	if (num==0)
	{
		return 0;
	}

	else if (num ==1)
	{
		return 1;
	}

	else
	{
		fn = fspark(num - 1) + fspark(num - 2);
		
		return fn;
	}
}
