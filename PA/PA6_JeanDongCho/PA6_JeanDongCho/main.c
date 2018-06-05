#include "Header.h"

int main(void)
{
	int mor = 0,coin=0,x=0,y=0,p1_score=0,p2_score=0,check=0;
	int c2destroyed = 0, b2destroyed = 0, r2destroyed = 0, s2destroyed = 0, d2destroyed = 0;
	int p1shot=0, p2shot=0, total_turn=0, cdestroyed =0, bdestroyed = 0, rdestroyed = 0, sdestroyed = 0, ddestroyed = 0;
	char matrix[10][10],cpu_matrix[10][10],ghost[10][10];
	FILE *outfile = fopen("Battle_stat", "w");

	srand(time(NULL));
	welcome_screen();//display rules
	initialize_game_board(matrix);//initialize board but do not show them in screen
	initialize_game_board(cpu_matrix);
	initialize_game_board(ghost);
	display_board(matrix, 10, 10); //display matrix to screen
	mor = manual_or_random();// ask user whether he or she wil manually deploy or automatically deploy
	if (mor ==1)
	{
		manually_place_ships_on_board(matrix);
	}
	else if (mor == 2)
	{
		randomly_place_ships_on_board(matrix);
	}
	display_board(matrix, 10, 10);
	randomly_place_ships_on_board(cpu_matrix);//deploy cpu's board
	system("cls");
	printf("Press any key to start the battle\n");
	system("pause");
	coin = select_who_starts_first(); //determine who has first turn
	if (coin == 0) //if p1 go first
	{
		printf("Player1(user) starts first.\n ");
		system("pause");
		printf("Please enter the coor dinate x y to shoot\n");// get coordinate to shoot
		scanf("%d", &x);
		scanf("%d", &y);
		p1shot += 1;
		check = check_shot(cpu_matrix, x,y);// check if it got hit
		if (check ==1)
		{
			p1_score += 1;
			
		}
		update_board(cpu_matrix, check, x, y); // update board depending on the result
		update_board(ghost, check, x, y);
		check_if_sunk_ship(cpu_matrix, &c2destroyed, &b2destroyed, &r2destroyed, &s2destroyed, &d2destroyed);
		output_current_move(outfile, 0, x, y, check);//write the log to outfile
		
		printf("Player2's sea:\n");
		display_board(ghost, 10, 10);// ghost sea that only show user whether shot got hit or missed, does not show the enemy's ship

		printf("Player2(cpu)'s turn.\n");
		x = rand() % 10;
		y = rand() % 10;
		printf("Player2 fired\n");
		p2shot += 1;
		check = check_shot(matrix, x, y);
		if (check == 1)//if its hit
		{
			p1_score += 1;
			
		}
		update_board(matrix, check, x, y);
		check_if_sunk_ship(matrix, &cdestroyed, &bdestroyed, &rdestroyed, &sdestroyed, &ddestroyed);
		output_current_move(outfile, 1, x, y, check);
		display_board(matrix, 10, 10);
		total_turn += 1;
	}
	else
	{
		printf("Player2(cpu) starts first.\n");
		x = rand() % 10;
		y = rand() % 10;
		p2shot += 1;
		printf("Player2 fired\n");
		check = check_shot(matrix, x, y);
		if (check == 1)//if its hit
		{
			p2_score += 1;
		}
		update_board(matrix, check, x, y);
		check_if_sunk_ship(matrix, &cdestroyed, &bdestroyed, &rdestroyed, &sdestroyed, &ddestroyed);

		output_current_move(outfile, 1, x, y, check);
		printf("Your board\n");

		display_board(matrix, 10, 10);

		printf("Player1's turn.\n ");
		printf("Please enter the coor dinate x y to shoot\n");
		scanf("%d", &x);
		scanf("%d", &y);
		p1shot += 1;
		check = check_shot(cpu_matrix, x, y);
		if (check == 1)
		{
			p1_score += 1;
		}
		update_board(cpu_matrix, check, x, y);
		update_board(ghost, check, x, y);
		check_if_sunk_ship(cpu_matrix, &c2destroyed, &b2destroyed, &r2destroyed, &s2destroyed, &d2destroyed);

		output_current_move(outfile, 0, x, y, check);
		
		printf("Player2's sea:\n");
		display_board(ghost, 10, 10);
		total_turn += 1;
	}
	
	while (p1_score < 17 && p2_score < 17)
	{
		if (coin == 0)// player2 started the game first
		{
			printf("Player1's turn.\n ");
			printf("Please enter the coor dinate x y to shoot\n");
			
			scanf("%d", &x);
			scanf("%d", &y);
			p1shot += 1;
			check = check_shot(cpu_matrix, x, y);
			if (check == 1)
			{
				p1_score += 1;
			}
			update_board(cpu_matrix, check, x, y);
			update_board(ghost, check, x, y);
			check_if_sunk_ship(cpu_matrix, &c2destroyed, &b2destroyed, &r2destroyed, &s2destroyed, &d2destroyed);

			output_current_move(outfile, 0, x, y, check);
			
			printf("Player2's sea:\n");
			display_board(ghost, 10, 10);


			printf("Player2(cpu)'s turn.\n");
			x = rand() % 10;
			y = rand() % 10;
			p2shot += 1;
			check = check_shot(matrix, x, y);
			if (check == 1)//if its hit
			{
				p2_score += 1;
			}
			update_board(matrix, check, x, y);
			output_current_move(outfile, 1, x, y, check);
			check_if_sunk_ship(matrix, &cdestroyed, &bdestroyed, &rdestroyed, &sdestroyed, &ddestroyed);
			printf("Your board\n");
			display_board(matrix, 10, 10);
			total_turn += 1;
		}
		else
		{
			printf("Player2(cpu)'s turn.\n");
			x = rand() % 10;
			y = rand() % 10;
			p2shot += 1;
			check = check_shot(matrix, x, y);
			if (check == 1)//if its hit
			{
				p2_score += 1;
			}
			update_board(matrix, check, x, y);
			check_if_sunk_ship(matrix, &cdestroyed, &bdestroyed, &rdestroyed, &sdestroyed, &ddestroyed);

			output_current_move(outfile, 1, x, y, check);
			printf("Your board\n");
			display_board(matrix, 10, 10);

			printf("Player1's turn.\n ");
			printf("Please enter the coor dinate x y to shoot\n");
		
			scanf("%d", &x);
			scanf("%d", &y);
			p1shot += 1;
			check = check_shot(cpu_matrix, x, y);
			if (check == 1)
			{
				p1_score += 1;
			}
			update_board(cpu_matrix, check, x, y);
			update_board(ghost, check, x, y);
			check_if_sunk_ship(cpu_matrix, &c2destroyed, &b2destroyed, &r2destroyed, &s2destroyed, &d2destroyed);

			output_current_move(outfile, 0, x, y, check);
			
			printf("Player2's sea:\n");
			display_board(ghost, 10, 10);
			total_turn += 1;
		}
	}
	if(p1_score ==17)
	{
		is_winner(p1_score, 0);
		output_stats(outfile, p1shot, p2shot, total_turn, 0, p1_score,p2_score);
	}
	
	if (p2_score == 17)
	{
		is_winner(p2_score, 0);
		output_stats(outfile, p1shot, p2shot, total_turn, 1,p1_score, p2_score);
	}


	fclose(outfile);
	return 0;
}