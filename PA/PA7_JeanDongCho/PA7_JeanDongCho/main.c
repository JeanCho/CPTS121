#include "Header.h"

int main(void)
{
	/* initialize suit array */
	const char *suit[4]= { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };
	int ndraw = 0,dcount=0,i=0,pbank=0,pwage=0;
	/* initalize deck array */
	int deck[4][13] = { 0 },option=0;
	int cardrow[5] = { 0 }, cardcol[5] = { 0 }, dcardrow[10] = { 0 }, dcardcol[10] = { 0 },change = 0, numchange = 0;
	int win = 0,bet=0,inibank=0;
	printf("Playing poker\n\n");
	do
	{
		printf("1.Print game rules.\n");
		printf("2.Start a game.\n");
		printf("3.Exit\n");

		scanf("%d", &option);

		if (option == 1)//print out game rule when 1 is typed
		{
			print_gamerule();
		}


	} while (option <= 1 || option >3);
	if (option == 3)//Exit
	{
		printf("Good Bye\n");
		return 0;
	}
	printf("Please enter your initial bank(integer)\n");
	scanf("%d", &pbank);
	inibank = pbank;

	while (pbank < inibank * 2 )
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				deck[i][j] = 0;
			}
		}
		srand((unsigned)time(NULL)); /* seed random-number generator */
		ndraw = 1;
		dcount = ndraw;
		shuffle(deck);
		
		printf("\n\n\n\n You are getting your hands\n");
		while (ndraw < dcount + 5)
		{
			deal(deck, face, suit, ndraw, cardrow, cardcol);
			displaycard(deck, face, suit, ndraw, cardrow, cardcol);
			ndraw += 1;

		}
		printf("How many card do you want to change?(0-3)\n");
		scanf("%d", &numchange);
		if (numchange != 0)
		{
			for (int i = 0; i < numchange; i++)
			{
				printf("Please type the card number (1 to 5) to change\n");
				scanf("%d", &change);


				changecard(deck, change, cardrow, cardcol);


			}
		}
		i = 1;
		printf("Your hand is now\n");
		bubblesort(cardrow, cardcol);
		while (i < 6)
		{
			displaycard(deck, face, suit, i, cardrow, cardcol);
			i++;
		}
		dcount += 5;
		// deal dealer's hand
		printf("\nDealer is getting his card...\n");
		while (ndraw < dcount + 5)
		{
			deal(deck, face, suit, ndraw, dcardrow, dcardcol);
			
			ndraw += 1;

		}
		dealer_change(dcardrow, dcardcol, deck);
		
		bubblesort(dcardrow, dcardcol);
		do{
			printf("Please enter your bet(integer)\n");
			scanf("%d", &pwage);
			if (pwage > pbank)
			{
				printf("You don't have enough money for that wager\n");
			}
		} while (pwage>pbank);
		pbank -= pwage;
		printf("\n\nDealer's hand\n");
		for (i = 6; i < 11; i++)
		{
			displaycard(deck, face, suit, i, dcardrow, dcardcol);
		}
		win = check_win(cardrow, cardcol, dcardrow, dcardcol);
		pbank = return_bet(pbank, pwage, win);
		printf("Your bank is now %d", pbank);
		if (pbank <= 0)
		{
			break;
		}
	}//whole game loop
	if (pbank == 0)
	{
		printf("You ran out of money\n");
		printf("Game Over\n");
	}
	else if (pbank >= inibank * 2)
	{
		printf("A man with black suit came near you \n");
		printf("He gently ask you to leave the casino\n");
		printf("You left casino more than twice as your initial bank\n");
		printf("Game Over\n");
	}
	return 0;
}
