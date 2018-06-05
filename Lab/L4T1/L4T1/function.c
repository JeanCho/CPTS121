#include "Header.h"

char get_y_n(void)
{
	char reply;
	printf("\nPlease enter your answer y/n \n");
	scanf(" %c", &reply);

	return reply;
}
double q1sedentary(void)
{	
	char qa1;
	double q1g;
	printf("Is the person sedentary?");
	qa1 = get_y_n();
	
	if (qa1 == 'y')
	{
		q1g = 1.2;
		return q1g;
	
	}
	else
	{
		q1g = q2lowact();
		return q1g;
	}
}
double q2lowact(void)
{
	char qa2;
	double q2g;
	printf("Doese the person perfom low activity?");
	qa2 =  get_y_n();

	if (qa2 == 'y')
	{
		q2g = 1.375;
		return q2g;

	}
	else
	{
		q2g = q3modact();
		return q2g;
	}

}
double q3modact(void)
{
	char qa3;
	double q3g;
	printf("Doese the person perfom moderate activity?");
	qa3 = get_y_n();

	if (qa3 == 'y')
	{
		q3g = 1.55;
		return q3g;

	}
	else
	{
		q3g = q4highact();
		return q3g;
	}


}
double q4highact(void) 
{
	char qa4;
	double q4g;
	printf("Doese the person perfom high activity?");
	qa4 = get_y_n();

	if (qa4 == 'y')
	{
		q4g = 1.725;
		return q4g;

	}
	else
	{
		q4g = q5extraact();
		return q4g;
	}


}
double q5extraact(void)
{
	char qa5;
	double q5g;
	printf("Doese the person perfom extra activity?");
	qa5 = get_y_n();

	if (qa5 == 'y')
	{
		q5g = 1.9;
		return q5g;

	}
	else
	{
		q5g = q1sedentary();
		return q5g;
	}
}
double menBMR(double pounds, double inches, int age)
{
	double BMR;
	BMR = 66 + (6.23 * pounds) + (12.7 * inches) - (6.8 * age);
	return BMR;

}
double womenBMR(double pounds, double inches, int age)
{
	double BMR;
	66 + (6.23 * pounds) + (12.7 * inches) - (6.8 * age);
	return BMR;

}