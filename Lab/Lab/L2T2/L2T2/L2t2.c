#include <stdio.h>

int main(void) 
{
	double weight, feet, BMI, inch;

	printf("Please enter your weight and feet\n");
	scanf("%lf%lf", &weight, &feet);
	inch = feet * 12;
	BMI = (weight / (inch*inch)) * 703;
	printf("Your BMI = %lf", BMI);





}