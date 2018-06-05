#include "Header.h"

int main(void)
{
	FILE *infile = fopen("lab4t1.txt", "r");
	int age = 0;
	double  height=0.0,mBMR = 0.0,pounds = 0.0,inches = 0.0,guideline = 0.0,calories = 0.0;
	char qa1 = '\0', qa2 = '\0', qa3 = '\0',qa4 = '\0', qa5 = '\0',gender = '\0';

	fscanf(infile, "%d", &age);
	fscanf(infile, "%c", &gender);
	fscanf(infile, "%lf", &height);
	fscanf(infile, "%lf", &pounds);

	inches = height*12;
	mBMR = menBMR(pounds, inches, age);
	guideline = q1sedentary();
	calories = mBMR*guideline;
	printf("Recomended Calories:%lf\n", calories);
	fclose(infile);

	return 0;
	


}