#include "Header.h"

int select_who_starts_first(void)
{
	//if coin =0 p1 go first, if coin=1, p2 go first
	int coin = 0;
	srand(time(NULL));
	coin = rand() % 2;
	return coin;
}
void welcome_screen(void)
{
	printf("=====Battleship=====\n");
	printf("Rules of the Game\n");
	printf("1.This is a two player game.\n2.Player1 is you and Player2 is the computer.\n3Guess where(0~9,0~9) the enemy ship is and fire your cannon\n");
	printf("Press any key to start the game.\n");
	system("pause");
	system("cls");
}
int manual_or_random(void)
{
	int choice = 0;
	do
	{
		printf("1. Enter positions of ships manually.\n");
		printf("2. Allow the program to randomly select positions of ships.\n");
		scanf("%d", &choice);
	} while (choice != 1 && choice != 2);

	return choice;

}
void initialize_game_board(char matrix[10][10])
{
	

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			matrix[i][j] = '-';
	}
	
}

void display_board(char matrix[10][10], int i, int j)
{
	for (int x = 0; x < i; x++)
	{
		for (int y = 0; y < j; y++)
		{
			printf("%c", matrix[x][y]);
		}
		printf("\n");
	}
	printf("\n\n");
}

int check_shot(char matrix[10][10],int x, int y)
{
	int check = 0;
	if (matrix[y][x] == '-' || matrix[y][x] =='*' || matrix[y][x]=='m')
	{
	
		check = 0;
		printf("Missed\n");
	}
	else
	{
		check = 1;
		printf("Hit!\n");
	}
	return check;
}

void update_board(char matrix[10][10], int check,int x, int y)
{
	
	if (check == 1)
	{
		matrix[y][x] = '*';
		
		
		
	}
	else
	{
		matrix[y][x] = 'm';
		
		
		
	}

	
}

void check_if_sunk_ship(char matrix[10][10],int *cdestroyed, int *bdestroyed, int *rdestroyed, int *sdestroyed, int *ddestroyed)
{
	int ccount = 0, bcount = 0, rcount = 0, scount = 0, dcount = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (matrix[i][j] =='c')
			{
				ccount += 1;
			}
			if (matrix[i][j] == 'b')
			{
				bcount += 1;
			}
			if (matrix[i][j] == 'r')
			{
				rcount += 1;
			}
			if (matrix[i][j] == 's')
			{
				scount += 1;
			}
			if (matrix[i][j] == 'd')
			{
				dcount += 1;
			}
			
		}
		
	}
	if (ccount == 0 && *cdestroyed !=1)
	{
		printf("Carrier destoyed\n");
		*cdestroyed = 1;
	}
	if (bcount == 0 && *bdestroyed !=1)
	{
		printf("Battleship destoyed\n");
		*bdestroyed = 1;
	}
	if (rcount == 0 && *rdestroyed !=1)
	{
		printf("Cruiser destoyed\n");
		*rdestroyed = 1;
	}
	if (scount == 0 && *sdestroyed !=1)
	{
		printf("Submarine destoyed\n");
		*sdestroyed = 1;
	}
	if (dcount == 0 && *ddestroyed)
	{
		printf("Destroyer destoyed\n");
		*ddestroyed = 1;
	}

}
void output_current_move(FILE *outfile,int player, int x, int y,int hom)
{
	if (player == 0)
	{
		fprintf(outfile, "Player1's Turn\n");
	}
	else
	{
		fprintf(outfile,"Player2's Turn\n");
	}
	fprintf(outfile,"Shot fired to (%d,%d)\n", x, y);
	if (hom == 1)
	{
		fprintf(outfile, "Hit\n");
	}
	else
	{
		fprintf(outfile, "Missed\n");
	}

}
void output_stats(FILE *outfile, int p1shot, int p2shot, int total_turn, int winner,int p1_score, int p2_score)
{
	if (winner == 0)
	{
		fprintf(outfile, "Player1 Won\n");
	}
	else
	{
		fprintf(outfile, "Player2 Won\n");
	}
	fprintf(outfile, "*** Game Statistics ***\n\n");
	fprintf(outfile,"Total shots fired by Player1: %d\n",p1shot);
	fprintf(outfile, "Total number of hit by Player1: %d\n\n",p1_score);

	fprintf(outfile,"Total shots fired by Player2: %d\n", p2shot);
	fprintf(outfile, "Total number of hit by Player2: %d\n\n", p2_score);
	fprintf(outfile,"Total turn took: %d\n",total_turn);

}


void is_winner(int score,int p)//return 0 if p2 wins 1 if p1 wins
{
	if (score >= 17)
	{
		printf("Game Over\n");
		if (p == 0)
		{
			printf("Player1 Won\n");
		}
		else if (p==1)
		{
			printf("Player 2 won\n");
		}
		
	}
	
}




void  manually_place_ships_on_board(char matrix [10][10])
{
	int x1=0, x2=0, x3=0, x4=0, x5=0, y1=0, y2=0, y3=0, y4=0, y5=0,validity=0,compare=0;

	printf("Ships can only be deployed vertically or horizontally\n");
	printf("And you can not deploy more than 1 ship in same coordinate\n\n");
	validity = 0;
	while (validity != 1)
	{

		printf("Please enter the five cells to place the Carrier across:\n");
		//scanf("%d%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &x5, &y5);
		scanf("%d", &x1);
		scanf("%d", &y1);
		scanf("%d", &x2);
		scanf("%d", &y2);
		scanf("%d", &x3);
		scanf("%d", &y3);
		scanf("%d", &x4);
		scanf("%d", &y4);
		scanf("%d", &x5);
		scanf("%d", &y5);

		if (((x1 == x2) & (x2== x3) & (x3 == x4) & (x4 == x5)) | (y1 == y2 & y2 == y3 & y3== y4 & y4 == y5))
		{
			validity = 1;
		}
		else
		{
			printf("Please deploy it in valid way\n");

		}
	}
		matrix[y1][x1] = 'c';
		matrix[y2][x2] = 'c';
		matrix[y3][x3] = 'c';
		matrix[y4][x4] = 'c';
		matrix[y5][x5] = 'c';
		display_board(matrix, 10, 10);

		validity = -1;
		while (validity != 1)
		{
			validity = -1;
			printf("Please enter the four cells to place the Battleship across:\n");
			//scanf("%d%d%d%d%d%d%d%d%", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
			scanf("%d", &x1);
			scanf("%d", &y1);
			scanf("%d", &x2);
			scanf("%d", &y2);
			scanf("%d", &x3);
			scanf("%d", &y3);
			scanf("%d", &x4);
			scanf("%d", &y4);
			if (((x1 == x2) & (x2 == x3) & (x3 == x4)) | (y1 == y2 & y2 == y3 & y3 == y4 ))
			{
				validity += 1;
			}

			//check if there is not other ship
			if (matrix[y1][x1] == '-' && matrix[y2][x2] == '-' && matrix[y3][x3] == '-' && matrix[y4][x4] == '-')
			{
				validity += 1;
			}
			else if (validity !=1)
			{
				printf("Please deploy it in valid way\n");

			}
			
		}
		matrix[y1][x1] = 'b';
		matrix[y2][x2] = 'b';
		matrix[y3][x3] = 'b';
		matrix[y4][x4] = 'b';
		display_board(matrix, 10, 10);

		validity = -1;
		while (validity != 1)
		{
			validity = -1;
			printf("Please enter the three cells to place the Cruiser across:\n");
			//scanf("%d%d%d%d%d%d%", &x1, &y1, &x2, &y2, &x3, &y3);
			scanf("%d", &x1);
			scanf("%d", &y1);
			scanf("%d", &x2);
			scanf("%d", &y2);
			scanf("%d", &x3);
			scanf("%d", &y3);
			if (((x1 == x2) & (x2 == x3)) | (y1 == y2 & y2 == y3))
			{
				validity += 1;
			}
			//check if there is other ship
			if (matrix[y1][x1] == '-' && matrix[y2][x2] == '-' && matrix[y3][x3] == '-' )
			{
				validity += 1;
			}
			else if (validity != 1)
			{
				printf("Please deploy it in valid way\n");

			}

		}
		matrix[y1][x1] = 'r';
		matrix[y2][x2] = 'r';
		matrix[y3][x3] = 'r';
		display_board(matrix, 10, 10);

		validity = -1;
		while (validity != 1)
		{
			validity = -1;
			printf("Please enter the three cells to place the Submarine across:\n");
			//scanf("%d%d%d%d%d%d%", &x1, &y1, &x2, &y2, &x3, &y3);
			scanf("%d", &x1);
			scanf("%d", &y1);
			scanf("%d", &x2);
			scanf("%d", &y2);
			scanf("%d", &x3);
			scanf("%d", &y3);
			
			if (((x1 == x2) & (x2 == x3)) | (y1 == y2 & y2 == y3))
			{
				validity += 1;
			}
			//check if there is other ship
			if (matrix[y1][x1] == '-' && matrix[y2][x2] == '-' && matrix[y3][x3] == '-')
			{
				validity += 1;
			}
			else if (validity != 1)
			{
				printf("Please deploy it in valid way\n");

			}

		}
		matrix[y1][x1] = 's';
		matrix[y2][x2] = 's';
		matrix[y3][x3] = 's';
		display_board(matrix, 10, 10);

		validity = -1;
		while (validity != 1)
		{
			validity = -1;
			printf("Please enter the two cells to place the Destroyer across:\n");
			//scanf("%d%d%d%d%d%d%", &x1, &y1, &x2, &y2);
			scanf("%d", &x1);
			scanf("%d", &y1);
			scanf("%d", &x2);
			scanf("%d", &y2);
			if (x1 == x2  || y1 == y2 )
			{
				validity += 1;
			}
			//check if there is other ship
			if (matrix[y1][x1] == '-' && matrix[y2][x2] == '-' )
			{
				validity += 1;
			}
			else if (validity != 1)
			{
				printf("Please deploy it in valid way\n");

			}

		}
		matrix[y1][x1] = 'd';
		matrix[y2][x2] = 'd';
		display_board(matrix, 10, 10);
		
		

}
void randomly_place_ships_on_board(char matrix[10][10])
{
	int x1=0, x2=0, x3=0, x4=0, x5=0, y1=0, y2=0, y3=0, y4=0, y5=0,coin=0,check=0;
	srand(time(NULL));
	coin = rand() % 2;
	if (coin == 0)
	{
		x1 = rand() % 10;
		x2 = x1;
		x3 = x1;
		x4 = x1;
		x5 = x1;

		y1 = rand() % 10 ;
		if (y1<=5)
		{
			y2 = y1 +1;
			y3 = y2 + 1;
			y4 = y3 + 1;
			y5 = y4 + 1;
		}
		else if (y1 > 5)
		{
			y2 = y1 - 1;
			y3 = y2 - 1;
			y4 = y3 - 1;
			y5 = y4 - 1;

		}
		
	} 
	else if (coin == 1)
	{
		y1 = rand() % 10;
		y2 = y1;
		y3 = y1;
		y4 = y1;
		y5 = y1;

		x1 = rand() % 10 ;
		if (x1 <= 5)
		{
			x2 = x1 +1;
			x3 = x2 + 1;
			x4 = x3 + 1;
			x5 = x4 + 1;

		}
		else
		{
			x2 = x1 - 1;
			x3 = x2 - 1;
			x4 = x3 - 1;
			x5 = x4 - 1;
		}
		

	}

	matrix[x1][y1] = 'c';
	matrix[x2][y2] = 'c';
	matrix[x3][y3] = 'c';
	matrix[x4][y4] = 'c';
	matrix[x5][y5] = 'c';

	coin = rand() % 2;
	check = 0;
	if (coin == 0)
		do {
			x1 = rand() % 10;
			x2 = x1;
			x3 = x1;
			x4 = x1;

			y1 = rand() % 10;
			if (y1 <= 4)
			{
				y2 = y1 + 1;
				y3 = y2 + 1;
				y4 = y3 + 1;
			}
			else
			{
				y2 = y1 - 1;
				y3 = y2 - 1;
				y4 = y3 - 1;
			}
			if (matrix[x1][y1] == '-' && matrix[x2][y2] == '-' && matrix[x3][y3] == '-' && matrix[x4][y4] == '-')
			{
				check = 1;
			}

		} while (check == 0);
	
	else if (coin == 1)
	do{
		y1 = rand() % 10 ;
		y2 = y1;
		y3 = y1;
		y4 = y1;
		
		x1 = rand() % 10 ;
		if (x1 <= 4)
		{
			x2 = x1 + 1;
			x3 = x2 + 1;
			x4 = x3 + 1;
		}
		else
		{
			x2 = x1 - 1;
			x3 = x2 - 1;
			x4 = x3 - 1;
		}
		if (matrix[x1][y1] == '-' && matrix[x2][y2] == '-' && matrix[x3][y3] == '-' && matrix[x4][y4] == '-')
		{
			check = 1;
		}
		

	}while (check==0);
	matrix[x1][y1] = 'b';
	matrix[x2][y2] = 'b';
	matrix[x3][y3] = 'b';
	matrix[x4][y4] = 'b';
	check = 0;
	
	coin = rand() % 2;
	if (coin == 0)
	do{
		x1 = rand() % 10;
		x2 = x1;
		x3 = x1;
		
		y1 = rand() % 10;
		if (y1 <= 3)
		{
			y2 = y1 + 1;
			y3 = y2 + 1;
			
		}
		else
		{
			y2 = y1 - 1;
			y3 = y2 - 1;
			
		}
		if (matrix[x1][y1] == '-' && matrix[x2][y2] == '-' && matrix[x3][y3] == '-')
		{
			check = 1;
		}
		
	}while (check ==0);
	else if (coin == 1)
	do{
		y1 = rand() % 10 ;
		y2 = y1;
		y3 = y1;
		
		x1 = rand() % 10 ;
		if (x1 <= 3)
		{
			x2 = x1 + 1;
			x3 = x2 + 1;
			
		}
		else
		{
			x2 = x1 - 1;
			x3 = x2 - 1;
		
		}
		if (matrix[x1][y1] == '-' && matrix[x2][y2] == '-' && matrix[x3][y3] == '-')
		{
			check = 1;
		}
		

	}while (check =0);
	matrix[x1][y1] = 'r';
	matrix[x2][y2] = 'r';
	matrix[x3][y3] = 'r';
	
	check = 0;
	coin = rand() % 2;
	if (coin == 0)
	do{
		x1 = rand() % 10;
		x2 = x1;
		x3 = x1;

		y1 = rand() % 10;
		if (y1 <= 3)
		{
			y2 = y1 + 1;
			y3 = y2 + 1;

		}
		else
		{
			y2 = y1 - 1;
			y3 = y2 - 1;

		}
		if (matrix[x1][y1] == '-' && matrix[x2][y2] == '-' && matrix[x3][y3] == '-')
		{
			check = 1;
		}
		
	}while (check==0);
	else if (coin == 1)
	do{
		y1 = rand() % 10;
		y2 = y1;
		y3 = y1;

		x1 = rand() % 10;
		if (x1 <= 3)
		{
			x2 = x1 + 1;
			x3 = x2 + 1;

		}
		else
		{
			x2 = x1 - 1;
			x3 = x2 - 1;

		}
		if (matrix[x1][y1] == '-' && matrix[x2][y2] == '-' && matrix[x3][y3] == '-')
		{
			check = 1;
		}
		
	}while (check ==0);
	matrix[x1][y1] = 's';
	matrix[x2][y2] = 's';
	matrix[x3][y3] = 's';

	check = 0;
	coin = rand() % 2;
	if (coin == 0)
	do{
		x1 = rand() % 10 ;
		x2 = x1;
		
		y1 = rand() % 10 ;
		if (y1 <= 2)
		{
			y2 = y1 + 1;
		}
		else
		{
			y2 = y1 - 1;
		}
		if (matrix[x1][y1] == '-' && matrix[x2][y2] == '-' )
		{
			check = 1;
		}
		
	} while (check==0);
	else if (coin == 1)
	do{
		y1 = rand() % 10;
		y2 = y1;
		
		x1 = rand() % 10 ;
		if (x1 <= 2)
		{
			x2 = x1 + 1;
		}
		else
		{
			x2 = x1 - 1;
		}
		if (matrix[x1][y1] == '-' && matrix[x2][y2] == '-')
		{
			check = 1;
		}

	} while (check==0);
	matrix[x1][y1] = 'd';
	matrix[x2][y2] = 'd';

	
}