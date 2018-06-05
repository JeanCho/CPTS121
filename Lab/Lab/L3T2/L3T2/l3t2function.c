#include "Header.h"

double calculate_time(double distance, double velocity, double theta)
{
	double time;
	time = (distance) / (velocity * cos(theta));
	return time;

}



double calculate_height(double velocity, double theta, double time)
{
	double height;
	height = velocity * sin(theta) * time - ((G * time * time) / 2);
	return height;
}