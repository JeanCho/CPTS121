#include <stdio.h>

int main(void)
{
	double HP = 0, CP = 0, CR = 0, RHP=0, RCP=0,BCS=0;
	printf("Please enter team'sscore in the Harris Poll(1~2850),Coaches Poll(1~1475),and computer ranking(0~1)\n\n");
	scanf("%lf%lf%lf", &HP, &CP, &CR);
	RHP = HP / 2850;
	RCP = CP / 1475;
	BCS = (RHP + RCP + CR) / 3;

	printf("BCS totalscore: %lf", BCS);

}