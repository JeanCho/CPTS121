#include <stdio.h>


int main(void)
{
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0,
	 slope=0;
	
	printf("Type coordinates of 2 points:\n");
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);
	printf("Coordinates: (%lf,%lf),(%lf,%lf)\n", x1, y1, x2, y2);
	
	slope = (x2 - x1) / (y2 - y1);
	printf("the slope is %lf\n", slope);
	double midpointx,midpointy;
	midpointx = (x2 + x1) / 2;
	midpointy = (y1 + y2) / 2;
	printf("Midpoint:(%lf,%lf\n)", midpointx, midpointy);
	double perslope;
	perslope = -(1 / slope);
	printf("perpendicular slope: %lf\n", perslope);
	double yinter;
	yinter = midpointy - perslope*midpointx;
	printf("yintercept:%lf\n", yinter);
	printf("y = %lfm + %lf", perslope, yinter);
	
}