#include "Header.h"

int main(void)
{
	int index = 0,check=0,wrong=0;
	char guess = '\0', word[6] = { 'c','a','r','r','o','t' }, gray[6] = {'?','?','?','?','?','?'};
	char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };


	while (word != gray)
	{
		printf("Guess the word\n");
		scanf(" %c", &guess);
		
		check = 0;
		for (int i = 0; i < 6; i++)
			if (guess == word[i])
			{
				gray[i] = guess;
				check += 1;
			}
		if (check >0)
		{
			printf("You guessed correctly");
		}
		else if(check <= 0)
		{
			printf("Worng Guess\n");
			wrong += 1;
		}

		for (int i = 0; i < 6; i++)
			printf("Your Guess[%d]: %c\n", i, gray[i]);
		if (wrong == 1)
		{
			printf(" o\n");
		}
		if (wrong == 2)
		{
			printf("/|\\n");
		}
		if (wrong == 3)
		{
			printf(" | \n");
		}
		if (wrong == 4)
		{
			printf("/ \\n");
			printf("Game over\n");
				return 0;
		}
		
	}
}