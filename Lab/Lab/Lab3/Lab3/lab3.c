#include <stdio.h>

double get_weight(void);// prompt pounds
double get_height(void);
double converFTI(double feet);
double calculate_bmi(double pounds, double inches);
void display_bmi(double bmi);

int main(void)
{
	double pound, feet, inch, bmi;
	pound = get_weight();
	feet = get_height();
	inch = converFTI(feet);
	bmi = calculate_bmi(pound, inch);
	display_bmi(bmi);
	return 0;
}


double get_weight(void)
{
	double pounds;
	printf("Insert your weight in pounds");
	scanf("%lf", &pounds);
	return pounds;
}

double get_height(void)
{
	double feet;		
	printf("Insert your height in feet");
	scanf("%lf", &feet);
	return feet;

}
double converFTI(double feet)
{
	double inches;
	inches = feet * 12;
	return inches;
}

double calculate_bmi(double pounds, double inches)
{
	double bmi;
	bmi = (pounds / (inches*inches)) * 703;
	return bmi;
}

void display_bmi(double bmi)
{
	printf("Your bmi: %lf", bmi);
	return 0;
}
