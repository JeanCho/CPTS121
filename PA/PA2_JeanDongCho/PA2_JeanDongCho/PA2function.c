#include "Header.h"

/*********************************************************************************
inout:duble-mass and acceleration
output:double force
**********************************************************************************/
double calculate_newtons_2nd_law(double mass, double acceleration) //inout:duble-mass and acceleration ; output:double force
{
	double force = 0.0;
	printf("Newton's Second Law of Motion\n");
	printf("Please enter the mass and acceleration <both floating point values> for Newton's second Law:\n"); //get the variable from user
	scanf("%lf%lf", &mass, &acceleration);
	force = mass * acceleration;
	printf("Newton's Second Law:Force = mass * acceleration = %lf * %lf = %lf\n", mass, acceleration, force);

	return force;

}

/*********************************************************************************
inout:double radius,height
output:double volume of cylinder
**********************************************************************************/

double calculate_volume_cylinder(double radius, double height)
{
	double syvolume = 0.0;
	printf("\nVplume of a cylinder\n");
	printf("Please enter the radius and height of cylinder <both floating pointvalues>\n");
	scanf("%lf%lf", &radius, &height);
	syvolume = PI *radius*radius*height;
	printf("Volume of Sylinder: PI * %lf ^2 * %lf = %lf\n\n", radius, height, syvolume);

	return syvolume;
}

/*********************************************************************************
inout: char 1character 
output:character with uppercase

**********************************************************************************/

char perform_character_encoding(char plaintext_character)
{
	char encchar;
	printf("Character encoding = (plaintext_character - 'a')+ 'A' \n");
	printf("Please enter the character 'plaintext_character:'\n");
	scanf(" %c", &plaintext_character);
	printf("%c", plaintext_character); //check which user entered
	encchar = (plaintext_character - 'a') + 'A'; //perform character encoding
	printf("Character encoding = %c -'a' = %c\n\n", plaintext_character, encchar);



	return encchar;
}

/*********************************************************************************
input:double
output:force(double)

**********************************************************************************/


double calculate_gauss_lens(double u, double v)
{
	double force = 0.0;
	printf("Gauss Lens Formula(solve for f): 1 / f = 1 / u + 1 / v, where u is the object distance, v is the image distance, and f is the focal length of the lens\n");
	printf("Please enter float value of U and V:\n");
	scanf("%lf%lf", &u, &v);
	force = 1 / (1 / v + 1 / u);
	printf("f = %lf\n\n", force);
	return force;

}


/*********************************************************************************
input:double
output:double(tangent)

**********************************************************************************/

double calculate_tangent(double theta)
{
	double tan_theta = 0.0;
	printf("Tangent: tan_theta = sin (theta) / cos (theta)");
	printf("Please enter float value of theta\n");
	scanf("%lf", &theta);
	tan_theta = sin(theta) / cos(theta);
	printf("Tangent: tna_theta = %lf\n\n", tan_theta);
	return tan_theta;
}

/*********************************************************************************
input:three double
output:double(calculated resistive divider)

**********************************************************************************/

double calculate_resistive_divider(double r1, double r2, double vin)
{
	double vout = 0.0;
	printf("Resistive divider: vout = r2 / (r1 + r2) * vin");
	printf("Please enter float value of r1,r2, and vin:\n");
	scanf("%lf%lf%lf", &r1, &r2, &vin);
	vout = r2 / (r1 + r2)*vin;
	printf("Vout = %lf\n\n", vout);
	return vout;
}

/*********************************************************************************
input:two coordiantes(double)
output:double(calculated distance of 2 coordinate)

**********************************************************************************/

double calculate_distance_between_2pts(double x1, double y1, double x2, double y2)
{
	double distance = 0.0;
	printf("Distance between two points: distance = square root of ((x1 - x2)^2 + (y1 - y2)^2)");
	printf("Please enter float value of x1,x2,and y1,y2:\n");
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);
	distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	printf("Distance = %lf\n\n", distance);

	return distance;
}


/*********************************************************************************
input:one integer,two doubles
output:double(calculated genera equation)

**********************************************************************************/


double calculate_general_equation(int a, double x, double z)
{
	double py = 0.0;
	printf("General equation: y = a / (a %%2) - (63 / -17) + x * z");
	printf("Please enter integer 'a', float x and z :\n");
	scanf("%d%lf%lf", &a, &x, &z);
	py = a / (a % 2) - (63 / (-17)) + x * z;
	printf("General equation: y = %lf", py);

	return py;



}