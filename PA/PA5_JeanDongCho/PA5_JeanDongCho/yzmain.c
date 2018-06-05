#include "Header.h"
/*******************************************************************************************
* Programmer: Your Name                                                                 *
* Class: CptS 121, Spring  2017; Lab Section 5                                         *
* Programming Assignment:5                                                    *
* Date: March 06, 2017                                                                *
* Description: This program will playyatzee game between player1 and player2.				*
*******************************************************************************************/

int main(void)
{
	int die1 = 0, die2 = 0, die3 = 0, die4 = 0, die5 = 0, dienum = 1, rollnum = 0, numreroll = 0,scorep1=0,scorep2=0;
	int option = 0, dice[5] = { 0,0,0,0,0 }, combo[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };// ={0};
	int index = 0,rerollnum=0,rerollcount=0,round=1,combochoice=0,changecombo=0,score=0,combocheck=0,comboremain=0;
	char anykey = '\n',reply='\n';

	do
	{
		printf("1.Print game rules.\n");
		printf("2.Start a game of Yahtzee.\n");
		printf("3.Exit\n");

		scanf("%d", &option);

		if (option == 1)//print out game rule when 1 is typed
		{
			print_gamerule();
		}


	} while (option <= 1 || option >3); //input

	if (option == 3)//Exit
	{
		printf("Good Bye\n");
		return 0;
	}
	do //repetition for entire game rounds
	{
		printf("Round#%d\n", round);
			printf("Player1 Begins\n");
			printf("Please enter any key to roll five dice\n");
			system("pause");//press anykey to continue
			rollnum = 1;
			srand((unsigned int)time(NULL));
			roll_dice(dice, 5);

			printf("You rolled:\n");
			for (index = 0; index < 5; ++index)
			{
				dienum = index + 1;

				printf("dice #%d: %d\n", dienum, dice[index]);
				
			}
			
			printf("Do you want to re roll some dice for other combination?(y/n)\n");
			scanf(" %c", &reply);
			while (reply != 'n' && rollnum < 3)
			{
				printf("How many dice you want to roll?\n");
				scanf("%d", &numreroll);
				for (rerollcount = 0; rerollcount < numreroll; ++rerollcount)
				{
					printf("Please select which die to re roll(1-5)\n");
					scanf("%d", &rerollnum);
					dice[rerollnum - 1] = roll_die();
					printf("Die #%d is: %d now.\n", rerollnum, dice[rerollnum - 1]);
				}
				++rollnum;
				if (rollnum != 3)
				{
					printf("Do you want to reroll some dice again?\n");
					scanf(" %c", &reply);
				}
			}
			
		

		printf("Your dice:\n");
		for (index = 0; index < 5; ++index)
		{
			dienum = index + 1;

			printf("dice #%d: %d\n", dienum, dice[index]);
			
		}
		comboremain = 0;
		do
		{
		
			printf("Please selecet your combination\n");
			printf("1. Sum of 1's        7. Three-of-a-kind\n");
			printf("2. Sum of 2's        8. Four-of-a-kind\n");
			printf("3. Sum of 3's        9. Full house\n");
			printf("4. Sum of 4's        10. Small straight\n");
			printf("5. Sum of 5's        11. Large straight\n");
			printf("6. Sum of 6's        12. Yahtzee\n");
			printf("13.Chance\n");

			scanf("%d", &combochoice);
			
			combocheck = check_combo(combochoice, dice);
			if (combocheck == 1)
			{
				comboremain = combination(combochoice, combo);
			}
			else if(combocheck ==0)
			{
				printf("Please choose valid combination\n\n");
			}
		} while (comboremain != 1);

		changecombo = combochoice - 1;
		combo[changecombo] = 0;
		scorep1=calculate_combo(combochoice,dice);
		printf("Player1 score:%d\n\n", scorep1);
		printf("Please press any key to continue");
		system("pause");//press anykey to continue
		system("cls");//clear screen
	

		//player2's turn
		printf("Round#%d\n", round);
		printf("Player2 Begins");
		printf("Please enter any key to roll five dice\n");
		system("pause");//press anykey to continue
		rollnum = 1;
		srand((unsigned int)time(NULL));
		roll_dice(dice, 5);

		printf("You rolled:\n");
		for (index = 0; index < 5; ++index)
		{
			dienum = index + 1;

			printf("dice #%d: %d\n", dienum, dice[index]);
			dienum += 1;
		}

		printf("Do you want to re roll some dice for other combination?(y/n)\n");
		scanf(" %c", &reply);
		while (reply != 'n' && rollnum < 3)
		{
			printf("How many dice you want to roll?\n");
			scanf("%d", &numreroll);
			for (rerollcount = 0; rerollcount < numreroll; ++rerollcount)
			{
				printf("Please select which die to re roll(1-5)\n");
				scanf("%d", &rerollnum);
				dice[rerollnum - 1] = roll_die();
				printf("Die #%d is: %d now.\n", rerollnum, dice[rerollnum - 1]);
			}
			++rollnum;
			if (rollnum != 3)
			{
				printf("Do you want to reroll some dice again?\n");
				scanf(" %c", &reply);
			}
		}



		printf("Your dice:\n");
		for (index = 0; index < 5; ++index)
		{
			dienum = index + 1;
			printf("dice #%d: %d\n", dienum, dice[index]);
			dienum += 1;
		}
		comboremain = 0;
		do
		{

			printf("Please selecet your combination\n");
			printf("1. Sum of 1's        7. Three-of-a-kind\n");
			printf("2. Sum of 2's        8. Four-of-a-kind\n");
			printf("3. Sum of 3's        9. Full house\n");
			printf("4. Sum of 4's        10. Small straight\n");
			printf("5. Sum of 5's        11. Large straight\n");
			printf("6. Sum of 6's        12. Yahtzee\n");
			printf("13.Chance\n");

			scanf("%d", &combochoice);

			combocheck = check_combo(combochoice, dice);
			if (combocheck == 1)
			{
				comboremain = combination(combochoice, combo);
			}
			else if(combocheck ==0)
			{
				printf("Please choose valid combination\n\n");
			}
		} while (comboremain != 1);

		changecombo = combochoice - 1;
		combo[changecombo] = 0;
		scorep2 += calculate_combo(combochoice, dice);
		printf("Player2 score:%d\n\n", scorep2);
		printf("Please press any key to continue");
		system("pause");//press anykey to continue
		system("cls");//clear screen


	
	
		++round;
		

	} while (round < 14);
	
	if (scorep1 > scorep2)
	{
		printf("player1 won");
	}
	else if (scorep2 > scorep1)
	{
		printf("player2 won");
	}
	else
	{
		printf("Score Draw");
	}

	return 0;
}

