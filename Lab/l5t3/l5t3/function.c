#include "Header.h"

int remainder(int num1, int num2)
{
	int remainder = 0;
	remainder = num1%num2;
	return remainder;
}int loopremainder(int num1, int num2)
{
	int rdr,og1,og2,result;
	og1 = num1;
	og2 = num2;
	rdr = remainder(og1, og2);
	while (rdr!=0)
	{
		og1 = og2;
		og2 = rdr;
		rdr = remainder(og1, og2);
		if (rdr==0)
		{
			result = og2;
		}
	}
	return og2;
}

int greatest_common_divisor(int num1, int num2)
{
	int divre=1;
	divre = loopremainder(num1, num2);
	
	return divre;
}