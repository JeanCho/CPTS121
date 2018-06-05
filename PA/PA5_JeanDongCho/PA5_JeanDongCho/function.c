#include "Header.h"


int roll_die(void)
{
	int die = 0;
	die = rand() % 6 + 1;
	return die;
}
void roll_dice(int dice[], int maxitems)
{
	int index = 0;

	while (index <maxitems)
	{
		dice[index] = roll_die();
		++index;
	}
	

}

void print_gamerule(void)
{
	printf("######## The Rule Of Yahtzee ########\n");
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of \n");
	printf("thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of \n");
	printf("boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then \n");
	printf("the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may \n");
	printf("not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper \n");
	printf("section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The \n");
	printf("lower section contains a number of poker like combinations.\n\n");
}

int combination(int choice, int combo[])
{
	int userinput = 0;


	if (combo[choice - 1] == 0)
	{
		printf("Please select one that you haven't used\n");
		userinput = 0;
	}
	else 
	{
		combo[choice - 1] == 0;
		userinput = 1;
	
	}
	
	return userinput;
	
}

int calculate_combo(int input, int dice[])
{
	int index = 0,score=0;
	if (input==1)
	{
		for (index = 0; index < 5; ++index)
		{
			if (dice[index] == 1)
			{
				score += 1;
			}
		}
	}

	else if (input == 2)
	{
		for (index = 0; index < 5; ++index)
		{
			if (dice[index] == 2)
			{
				score += 2;
			}
		}
	}

	else if (input == 3)
	{ 
		for (index = 0; index < 5; ++index)
		{
			if (dice[index] == 3)
			{
				score += 3;
			}
		}
	}

	else if (input == 4)
	{
		for (index = 0; index < 5; ++index)
		{
			if (dice[index] == 4)
			{
				score += 4;
			}
		}
	}

	else if (input == 5)
	{ 
		for (index = 0; index < 5; ++index)
		{
			if (dice[index] == 5)
			{
				score += 5;
			}
		}
	}

	else if (input == 6)
	{
		for (index = 0; index < 5; ++index)
		{
			if (dice[index] == 6)
			{
				score += 6;
			}
		}
	}

	else if (input == 7)
	{
		for (index = 0; index < 5; ++index)
		{
			score += dice[index];
		}
	}

	else if (input == 8)
	{
		for (index = 0; index < 5; ++index)
		{
			score += dice[index];
		}
	}

	else if (input == 9)
	{
		score += 25;
	}

	else if (input == 10)
	{ 
		score += 30;
	}


	else if (input == 11)
	{ 
		score += 40;
	}

	else if (input == 12)
	{
		score += 50;
	}

	else if (input == 13)
	{ 
		for (index = 0; index < 5; ++index)
		{
			score += dice[index];
		}
	}



	return score;
}

int check_combo(int input, int dice[])//return 1 if true 0 if false
{
	int pair=0;

	if (input == 7)
	{
		if (check_pair(dice)==6)
		{
			printf("Three Of A Kind\n");

			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (input == 8)
	{
		if (check_pair(dice) == 12)
		{
			printf("Four Of A Kind\n");

			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (input == 9)
	{
		if (check_pair(dice) == 8)
		{
			printf("Full House\n");

			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (input == 10)
	{
		if (check_strait(dice) == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (input == 11)
	{
		if (check_strait(dice) == 2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (input == 12)
	{
		if (check_pair(dice) == 20)
		{
			printf("Yahtzee!!\n\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (input == 13)
	{ 
		return 1;
	}

	else
	{
		return 1;
	}
}

void check_message(int check)
{
	if (check ==0)
	{
		printf("Please choose valid score box");
	}
	
}
int check_pair(int dice[])
{
	int index = 0, pair = 0;
	for (index = 0; index < 5; ++index)
	{
		if (dice[0] == dice[index])
		{
			pair += 1;

		}
		
		
		if (dice[1] == dice[index])
		{
			pair += 1;

		}
		if (dice[2] == dice[index])
		{
			pair += 1;

		}
		if (dice[3] == dice[index])
		{
			pair += 1;

		}
		if (dice[4] == dice[index])
		{
			pair += 1;

		}
		

		
	}
	pair -= 5;
	return pair;
}

void combo_message(int pair)
{
	if (pair==2)
	{
		printf("One Pair\n");
	}
	else if (pair == 4)
	{
		printf("Two Pair\n");
	}
	else if (pair == 6)
	{
		printf("Three Of A Kind\n");
	}
	else if (pair == 10)
	{
		printf("Full House");
	}
	else if (pair == 12)
	{
		printf("Four Of A Kind\n");
	}

	else if (pair == 20)
	{
		printf("Yahtzee!!\n\n");
	}

	

}

int check_strait(int dice[])
{
	int die_pattern[6] = {0,0,0,0,0,0 },index=0,value=0;
	int *die_pointer = dice[5], *pattern_array=die_pattern;
	
	for (index = 0; index < 6; ++index)
	{
		die_pattern[index] = 0;

	}
	for (index = 0; index < 5; ++index)
	{
		value = dice[index];
		die_pattern[value-1] += 1;
		
	}

	
	if (die_pattern[0] == 1 && die_pattern[1] == 1 && die_pattern[2] == 1 && die_pattern[3] == 1)
	{
		return 1;
	}
	else if (die_pattern[1] == 1 && die_pattern[2] == 1 && die_pattern[3] == 1 && die_pattern[4] == 1)
	{
		return 1;
	}
	else if (die_pattern[2] == 1 && die_pattern[3] == 1 && die_pattern[4] == 1 && die_pattern[5] == 1)
	{
		return 1;
	}
	else if (die_pattern[0] == 1 && die_pattern[1] == 1 && die_pattern[2] == 1 && die_pattern[3] == 1 && die_pattern[4]==1 && die_pattern[5]==1)
	{
		return 2;
	}
}