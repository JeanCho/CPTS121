#include "Header.h"

int randomgen(void)
{
	int r = 0;

	srand(time(NULL));
	r = (rand()%201) -100;
	return r;

}

void game(num)
{
	int guess = 0;

	printf("Time to guess the number..\n\n");
	do
	{
		
		printf("Type your guess:\n");
		scanf("%d", &guess);

		if (guess>100 || guess<-100)
		{
			printf("Please type number between -100~~100\n");

		}

		else if (guess < num)
		{
			printf("Wrong, it's bigger than that\n");

		}
		else if (guess > num)
		{
			printf("Wrong, it's smaller than that\n");
		}
		else if (guess == num)
		{
			printf("You are right. The answer was %d\n", num);
		}
		


	} while (guess != num);

}