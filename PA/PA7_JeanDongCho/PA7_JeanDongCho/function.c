#include "Header.h"

void print_gamerule(void)
{
	printf("1.Each player draw five cards\n2.Each player choose up to 3 card to re-draw\n");
	printf("3.Each player bet,call,die or check");
}

/* shuffle cards in deck */
void shuffle (int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand () % 4;
			column = rand () % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

void changecard(int wDeck[][13],int change,int cr[], int cc[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0,temp;   /* card counter */
	int u = 0,r=0,c=0;
					/* for each of the 52 cards, choose slot of deck randomly */
	u = change;
	for (row = 0; row <= 3; row++)
	{
		/* loop through columns of wDeck for current row */
		for (column = 0; column <= 12; column++)
		{
			
			if (wDeck[row][column] == change+10)
			{
				cr[change - 1] = row;
				cc[change - 1] = column;
				r = row;
				c = column;
				
					//wDeck[row][column] = change;
			}
				
				
//change the value of card with +10th card(it is still sth random)
			
		}

	}
	
	for (row = 0; row <= 3; row++)
	{
		/* loop through columns of wDeck for current row */
		for (column = 0; column <= 12; column++)
		{

			if (wDeck[row][column] == change)
			{
				wDeck[row][column] = change + 10;

			}

		}
	}
	wDeck[r][c] = change;
}
/* deal cards in deck */

void deal (const int wDeck[][13], const char *wFace[], const char *wSuit[],int ndraw, int cr[], int cc[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0,c1=0,c2=0,c3=0,c4=0,c5=0;   /* card counter */


 
	/* deal each of the 52 cards */
	
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == ndraw)
				{
					//printf ("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					cr[ndraw-1] = row;
					cc[ndraw-1] = column;
				}
			
			}
		}
	
}

void displaycard(const int wDeck[][13], const char *wFace[], const char *wSuit[], int ndraw, int cr[], int cc[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;   /* card counter */
	int i = 0,rw=0,cl=0;
											/* deal each of the 52 cards */

	for (row = 0; row <= 3; row++)
	{
		/* loop through columns of wDeck for current row */
		for (column = 0; column <= 12; column++)
		{
			/* if slot contains current card, display card */
			if (wDeck[row][column] == ndraw)
			{
				rw = cr[ndraw-1];
				cl = cc[ndraw-1];
				printf("%5s of %-8s%c", wFace[cl], wSuit[rw], card % 2 == 0 ? '\n' : '\t');
				
			}

		}
	}
}

void bubblesort(int cr[],int cc[])
{
	int c, d, swap,len,rswp;


	len = 5;



	for (c = 0; c < (len + 1); c++)
	{
		for (d = 0; d < len - 1; d++)
		{
			if (cc[d] > cc[d + 1]) /* For decreasing order use < */
			{
				swap = cc[d];
				rswp = cr[d];
				cc[d] = cc[d + 1];
				cr[d] = cr[d + 1];
				cc[d + 1] = swap;
				cr[d + 1] = rswp;
				
			}
		}
	}
	

}

int paircheck(int cc[])
{
	int pair = 0;
	for (int i = 0; i < 5; i++)
	{
		if (cc[i] == cc[1] || cc[i] == cc[2] || cc[i] == cc[3] || cc[i] == cc[4] || cc[i] == cc[0])
		{
			pair += 1;
		}
	}
	pair = pair - 5;
	if (pair ==2)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

int twopaircheck(int cc[])
{
	int pair = 0;
	for (int i = 0; i < 5; i++)
	{
		if (cc[i] == cc[1] || cc[i] == cc[2] || cc[i] == cc[3] || cc[i] == cc[4] || cc[i] == cc[0])
		{
			pair += 1;
		}
	}
	pair -= 5;
	if (pair == 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int threekindcheck(int cc[])
{
	int pair = 0;
	for (int i = 0; i < 5; i++)
	{
		if (cc[i] == cc[1] || cc[i] == cc[2] || cc[i] == cc[3] || cc[i] == cc[4] || cc[i] == cc[0])
		{
			pair += 1;
		}
	}
	pair -= 5;
	if (pair == 6)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int fourkindcheck(int cc[])
{
	int pair = 0;
	for (int i = 0; i < 5; i++)
	{
		if (cc[i] == cc[1] || cc[i] == cc[2] || cc[i] == cc[3] || cc[i] == cc[4] || cc[i] == cc[0])
		{
			pair += 1;
		}
	}
	pair -= 5;
	if (pair >= 12)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int housecheck(int cc[])
{
	int pair = 0;
	for (int i = 0; i < 5; i++)
	{
		if (cc[i] == cc[1] || cc[i] == cc[2] || cc[i] == cc[3] || cc[i] == cc[4] || cc[i] == cc[0])
		{
			pair += 1;
		}
	}
	pair -= 5;
	if (pair == 10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int flushcheck(int cr[])
{
	if (cr[0] == cr[1] == cr[2] == cr[3] == cr[4])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int straightcheck(int cr[],int cc[])
{
	int pair = 0;
	bubblesort(cr,cc);
	for (int i = 0; i < 4; i++)
	{
		if (cc[i+1] ==cc[i]+1)
		{
			pair += 1;
		}
	}
	if (pair >= 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void dealer_change(int dcr[], int dcc[], int wDeck[][13])
{
	int change = 0;
	if (paircheck(dcc) == 0 && twopaircheck(dcc) == 0 && threekindcheck(dcc) == 0 && fourkindcheck(dcc) == 0 && flushcheck(dcc) == 0 && straightcheck(dcr,dcc) == 0)
	{
		printf("Dealer got bad hands and now he is changing his card\n");
		for (change = 6; change < 9;change++)
		{
			changecard(wDeck, change, dcr, dcc);
		}
	}
}

int cal_score(int cr[], int cc[])
{
	int p1 = 0, p2 = 0, k3 = 0, k4 = 0, house = 0, fl = 0, st = 0,score=0;

	p1 = paircheck(cc);
	p2 = twopaircheck(cc);
	k3 = threekindcheck(cc);
	k4 = fourkindcheck(cc);
	house = housecheck(cc);
	fl = flushcheck(cc);
	st = straightcheck(cr, cc);
	score = 0;
	if (p1 ==1)
	{
		score += 1;
	}
	if (p2 == 1)
	{
		score += 10;
	}
	if (k3 == 1)
	{
		score += 100;
	}
	if (k4 == 1)
	{
		score += 1000;
	}
	if (house == 1)
	{
		score += 900;
	}
	if (fl == 1)
	{
		score += 800;
	}
	if (st == 1)
	{
		score += 700;
	}
	return score;
}
int check_win(int cr[], int cc[], int dcr[], int dcc[])
{
	int dscore = 0, pscore = 0;
	dscore = cal_score(dcr, dcc);
	pscore = cal_score(cr, cc);
	if(pscore >dscore)
	{
		printf("You won, the money is yours\n");
		return 1;
	}
	else if(pscore <dscore)
	{
		printf("You lost, you lost your wager");
		return 0;
	}
	
	else if (pscore == dscore)
	{
		if (dcr[5] > cr[5])
		{
			printf("You lost, you lost your wager");
			return 0;
		}
		else if (dcr[5] < cr[5])
		{
			printf("You won, the money is yours\n");
			return 1;
		}
		else
		{
			printf("Tied, wager returned to your banak\n");
			return 2;
		}
	}
}
int return_bet(int bank, int wager, int win)
{
	int result = 0;
	if (win == 0)
	{
		result = bank;
	}
	else if (win == 1)
	{
		result = bank + wager * 2;
	}
	else
	{
		result = bank+wager;
	}
}