#include "Header.h"

int roll_die(void)
{
	int die = 0;

	die = rand() % 6 +1;

	return die;

}

int calculate_sum_dice(int die1_value, int die2_value)
{
	int summed = 0;
	summed = die1_value + die2_value;
	return summed;
}

int roll_and_sum(void)
{
	int die1 = 0, die2 = 0,sum=0;
	
	printf("Rolling two dice\n");
	srand((unsigned int)time(NULL));
	die1 = rand() % 6 + 1;
	
	die2 = rand() % 6 + 1;
	sum = calculate_sum_dice(die1, die2);
	printf("Die1:%d, Die2:%d\n", die1, die2);
	printf("Result:%d\n\n", sum);
	return sum;
}


void print_game_rules(void)
{
	printf("Welcome to the Crap Game\n\n");
	printf("##########The Rule Of Game##########\n");
	printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\nAfter the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called craps), the player loses (i.e. the house wins).\n If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's 'point.'\n To win, you must continue rolling the dice until you 'make your point.' The player loses by rolling a 7 before making the point.\n");
	printf("\n");
}
double get_bank_balance(void)
{
	double bank = 0.0;
	printf("Please enter your initial bank amount:\n");
	scanf("%lf", &bank);
	printf("You typed:%.2lf\n\n", bank);
	return bank;
}

double get_wager_amount(void)
{
	double wager = 0.0;

	printf("Please enter how much you want to wage\n");
	scanf("%lf", &wager);
	printf("Wager:%.2lf\n", wager);
	return wager;
}
int check_wager_amount(double wager, double balance)
{
	double check=0.0;
	
	check = balance - wager;
	if (check >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int is_win_loss_or_point(int sum_dice)
{
	int result = 0;
	if (sum_dice == 7 || sum_dice == 11)//if win
	{
		result = 1;
	}
	//if lose
	else if (sum_dice == 1 || sum_dice == 2 || sum_dice == 12)
	{
		result = 0;
	}
	else//if its point
	{
		printf("point value saved:%d\n",sum_dice);
		result = -1;
	}
	return result;
}
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	int result = 33;
	if (sum_dice ==7)
	{
		result = 0;
	}
	else if (sum_dice == point_value)
	{
		result = 1;
	}
	else
	{
		result = -2;
	}
	return result;
}
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	double bank = bank_balance;
	if (add_or_subtract ==1)
	{
		bank += wager_amount;
		bank += wager_amount;
		
	}
	else if (add_or_subtract ==0)
	{
		bank = bank_balance;
		
		
	}
	else
	{
		
		bank = bank_balance;
	}
	return bank;
}

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	printf("%dth roll\n", number_rolls);

	if (number_rolls == 1)
	{
		if (win_loss_neither == 1)
		{
			printf("Beginner's luck was true!\n");
			printf("You won. Your wager had added to your balance\n");
		}
		else if (win_loss_neither == 0)
		{
			printf("It's ok to fail at first time.\n");
			printf("You lost..\n You lost your wage\n");
		}
		else if (win_loss_neither==-1)
		{
			printf("Maybe there is a second chance.\n");
			printf("It's a Point.\n");
		}
		else
		{
			printf("Still did not hit the point\n");
		}
	}

	else if (number_rolls == 7)
	{
		if (win_loss_neither == 1)
		{
			printf("The power of lucky 7 is in you!\n");
			printf("You won. Your wager had added to your balance\n");
		}
		else if (win_loss_neither == 0)
		{
			printf("Even the lucky 7 could not helped you.\n");
			printf("You lost.. You lost your wage\n");
		}
		else if (win_loss_neither == -1)
		{
			printf("Maybe there could be lucky 8.");
			printf("It's a Point.\n");
		}
		else
		{
			printf("Still did not hit the point\n");
		}
	}

	else if (number_rolls == 10)
	{
		if (win_loss_neither == 1)
		{
			printf("Celebration for your 10th dice!\n");
			printf("You won. Your wager had added to your balance\n");
		}
		else if (win_loss_neither == 0)
		{
			printf("Maybe you'll get better luck for 11th turn.\n");
			printf("You lost.. You lost your wage\n");
		}
		else if (win_loss_neither ==-1)
		{
			printf("Forget 10, pray for 11th");
			printf("It's a Point.\n");
		}
		else
		{
			printf("Still did not hit the point\n");
		}
	}
	else
	{
		if (win_loss_neither == 1)
		{

			printf("You won. Your wager had added to your balance\n");
		}
		else if (win_loss_neither == 0)
		{

			printf("You lost.. You lost your wage\n");
		}
		else if (is_win_loss_or_point==-1)
		{

			printf("It's a Point.\n");
		}
		else
		{
			printf("Still did not hit the point\n");
		}
	}
	printf("Initial bank balance:%.2lf\n", initial_bank_balance);
	printf("Current bank balance:%.2lf\n\n", current_bank_balance);
}

