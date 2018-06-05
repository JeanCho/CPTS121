#include "Header.h"

int main(void)
{
	double theta = 0.0, distance = 0.0, velocity = 0.0, time = 0.0, height = 0.0;

	printf("Type theta,distance,and velocity:\n");
	scanf("%lf%lf%lf", &theta, &distance, &velocity);
	time = calculate_time(distance, velocity, theta);
	height = calculate_height(velocity, theta, time);
	printf("Time:%lf Height:%lf", time, height);


}