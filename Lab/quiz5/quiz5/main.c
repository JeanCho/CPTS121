#include <stdio.h>

void intdiv(int *res, int *num1, int *num2);

int main(void)
{
	int result = 0, num1 = 83, num2 = 17, *num1ptr = NULL, *num2ptr = NULL;

	printf("Result %d,num1 %d, num2 %d\n\n", result, num1, num2);

	printf("address:%d,num1 %d,num2 %d\n\n", &result, &num1, &num2);
	num1ptr = &num1;
	num2ptr = &num2;
	intdiv(&result, num1ptr, num2ptr);

	printf("address:%d,num1 %d,num2 %d\n\n", &result, &num1, &num2);
	printf("Result %d,num1 %d, num2 %d\n\n", result, num1, num2);

	
}
1
void intdiv(int *res, int *num1, int *num2)
{
	printf("res %d num1 %d num2 %d\n", res, num1, num2);
	*res = *num1 / *num2;

	printf("div %d by %d is %d\n", *num1, *num2, *res);
}