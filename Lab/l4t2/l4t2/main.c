#include "Header.h"


int main(void)
{
	int totalM = 0;
	char a1 = '\0', a2 = '\0', a3 = '\0', a4 = '\0', a5 = '\0', a6 = '\0', a7 = '\0';

	
	printf("All - Star Game appearance = $25, 000");
	a1 = y_n();
	if (a1 == 'y')
	{
		totalM += 25000;
		
	}
	printf("Regular season MVP = $75, 000");
	a2 = y_n();
	if (a2 == 'y')
	{
		totalM += 75000;
		return totalM;
	}
	printf("World Series MVP = $100, 000");
	a3 = y_n();
	if (a3 == 'y')
	{
		totalM += 100000;
		return totalM;
	}
	printf("Gold Glove award = $50, 000");
	a4 = y_n();
	if (a4 == 'y')
	{
		totalM =totalM+ 50000;
	}
	printf("Silver Slugger award = $35, 000");
	a5 = y_n();
	if (a5 == 'y')
	{
		totalM = totalM + 35000;
	}
	printf(" Home run champ = $25, 000");
	a6 = y_n();
	if (a6 == 'y')
	{
		totalM = totalM + 25000;
	}
	printf("Batting average champ = $25, 000");
	a7 = y_n();
	if (a7 == 'y')
	{
		totalM += 25000;
	}
	printf("$$$$$$$$ : %d", totalM);
	return 0;
}