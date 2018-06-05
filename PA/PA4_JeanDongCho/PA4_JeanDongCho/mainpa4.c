#include "Header.h"

int main(void)
{
	int option =0,die = 0,diecount=0,wager_check=0,result_check=0,point_check=0,point_value=0,pointdie=0,point_wager=0;
	double initial_balance=0.0,balance = 0.0,wager=0.0,tempt_balance=0.0;
	char anykey = '\0';

	
		do
		{
			printf("1.Play game.\n");
			printf("2.Exit\n");

			scanf("%d", &option);

		} while (option < 1 || option >2); //input

		if (option == 2)
		{
			return 0;
		}

		print_game_rules();
		
		printf("Game Start\n\n");
		balance = get_bank_balance();
		initial_balance = balance;
		while (balance > 0)
		{
			tempt_balance = balance;
			wager = get_wager_amount();
			tempt_balance -= wager;
			wager_check = check_wager_amount(wager, balance);
			while (wager_check == 0) //loop if user typed more than wager
			{
				printf("You don't have enough balance for that.\n");
				printf("Your balance:%.2lf\n", balance);
				printf("Please wage again\n");
				wager = get_wager_amount();
				wager_check = check_wager_amount(wager, balance);
			}
			balance -= wager;



			printf("Press any Key (except Enter) to roll your dice\n\n\n");
			scanf(" %c",&anykey);
			srand((unsigned int)time(NULL));
			die = roll_and_sum();
			diecount += 1;
			result_check = is_win_loss_or_point(die);
			balance = adjust_bank_balance(balance, wager, result_check);
			chatter_messages(diecount, result_check, initial_balance, balance);
			while (result_check == -1||result_check ==-2)
			{

				point_value = die;
				printf("Point Value:%d\n", point_value);
				point_wager = get_wager_amount();
				wager_check = check_wager_amount(point_wager, balance);

				while (wager_check == 0) //loop if user typed more than wager
				{
					printf("You don't have enough balance for that.\n");
					printf("Your balance:%.2lf\n", tempt_balance);
					printf("Please wage again\n");
					point_wager = get_wager_amount();
					wager_check = check_wager_amount(point_wager, balance);
				}
				balance -= point_wager;
				printf("Press any Key (except Enter) to roll your dice\n\n\n");
				scanf(" %c", &anykey);

				srand((unsigned int)time(NULL));
				pointdie = roll_and_sum();
				diecount += 1;
				point_check = is_point_loss_or_neither(pointdie, point_value);
				wager += point_wager;
				balance = adjust_bank_balance(balance, wager, point_check);
				chatter_messages(diecount, point_check, initial_balance, balance);
				result_check = point_check;
			}

		}
		printf("Game Over\n");



	
	
	return 0;
}