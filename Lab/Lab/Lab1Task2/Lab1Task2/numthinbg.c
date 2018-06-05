#include <stdio.h>

int main(void)
{
	double num1, num2 = 5, added ;
	double fnum1 = 5.5, fnum2 = 2.1, subtracted, multiplied,divided, fdivided;

	printf("Enter sthing that is a number: \n");
	scanf("%lf", &num1);
	printf("num1 = %lf\n", num1);
	printf("num2 = %lf\n", num2);

	added = num1 + num2;
	printf("float num1 = %.2lf\n", fnum1);
	printf("float num1 = %.2lf, float num 2 = %.2lf \n", fnum1, fnum2);

	subtracted = fnum1 - fnum2;
	multiplied = num1 * fnum1;
	divided = num1 / num2;
	fdivided = num1 / fnum2;

	printf("num1 + num2  = %d\n", added);
	printf("subtracted fnum1 - fnum2 = %.2lf\n", subtracted);
	printf("multiplied num1 * fnum1 = %.2lf\n", multiplied);
	printf("divided num1 / num2 = %.2lf\n", divided);
	printf("divided num1 / fnum2 = %.2lf\n", fdivided);

}