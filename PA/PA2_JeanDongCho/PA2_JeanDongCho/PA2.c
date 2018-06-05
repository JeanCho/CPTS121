/*******************************************************************************************
* Programmer: Your Name                                                                 *
* Class: CptS 121, Spring  2017; Lab Section 5                                         *
* Programming Assignment:2                                                     *
* Date: January 28, 2017                                                                *
* Description: This program gets input from user and do the laws and equation for them with the function				*
*******************************************************************************************/


#include "Header.h"

int main(void)
{
	char plaintext_character=0.0;
	int  a=0;

	double mass=0, acceleration=0, force=0, radius=0, height=0, syvolume=0, u=0, v=0, f=0, theta=0, tan_theta=0, vout=0, r1=0, r2=0, vin=0, x1=0, x2=0, y1=0, y2=0, distance=0, x=0, z=0, py=0;


	
	calculate_newtons_2nd_law( mass,  acceleration); // call each function
	calculate_volume_cylinder(radius, height); 
	perform_character_encoding( plaintext_character);
	calculate_gauss_lens( u,  v);
	calculate_tangent( theta);
	calculate_resistive_divider( r1,  r2,  vin);
	calculate_distance_between_2pts( x1,  y1,  x2,  y2);
	calculate_general_equation( a,  x,  z);


	return 0;
	


}

//end of main function
