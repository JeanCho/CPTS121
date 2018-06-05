#include "Header.h"


void build_sentence(char Sentence[20][100],sentence list)
{
	int r = 0;
	srand((unsigned)time(NULL));
	for(int i=0; i<20 ; i++)
	{
			r = rand() % 5;
			strcat(Sentence[i],list.article[r]);
			r = rand() % 5;
			strcat(Sentence[i],list.noun[r]);
			r = rand() % 5 ;
			strcat(Sentence[i],list.verb[r]);
			r = rand() % 5;
			strcat(Sentence[i],list.preposition[r]);
			r = rand() % 5 ;
			strcat(Sentence[i],list.article[r]);
			r = rand() % 5 ;
			strcat(Sentence[i],list.noun[r]);
		
		
	}
	
}

void display_array(char  sentence[20][100])
{
	for (int i = 0; i < 20; i++)
	{
		
			printf("%s", sentence[i]);
		
		
		printf("\n");
	}


}