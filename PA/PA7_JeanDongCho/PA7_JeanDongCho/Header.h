#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card
{
	int faceIndex;
	int suitIndex;

}Card;
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], int ndraw, int cr[],int cc[]);
void displaycard(const int wDeck[][13], const char *wFace[], const char *wSuit[], int ndraw, int cr[], int cc[]);
void bubblesort(int cr[],int cc[]);
void print_gamerule(void);
int paircheck(int cc[]);
int twopaircheck(int cc[]);
int threekindcheck(int cc[]);
int fourkindcheck(int cc[]);
int flushcheck(int cr[]);
int straightcheck(int cr[],int cc[]);
int housecheck(int cc[]);
void changecard(int wDeck[][13],int change,int cr[], int cc[]);
void dealer_change(int dcr[], int dcc[],int wDeck[][13]);
int check_win(int cr[],int cc[], int dcr[], int dcc[]);
int return_bet(int bank, int wager, int win);
int cal_score(int cr[], int cc[]);