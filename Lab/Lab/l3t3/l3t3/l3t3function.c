#include "Header.h"



double get_score(void)
{
	double score;
	printf("Insert Score:\n");
	scanf("%lf", &score);

	return score;

}

double examtotal(double exam1, double exam2)
{
	double examtotal;
	examtotal = (exam1 + exam2) * 30 / 100;
	return examtotal;
}

double labtotal(double lab1, double lab2)
{
	double labtotal;
	labtotal = (lab1 + lab2) * 5 / 100;
	return labtotal;
}
double projecttotal(double project1, double project2)
{
	double projecttotal;
	projecttotal = (project1 + project2) * 15 / 100;
	return projecttotal;
}
double weight_average(double examtotal, double labtotal, double projecttotal)
{
	double waverage;
	waverage = (examtotal + labtotal + projecttotal)/100;
	return waverage;
}