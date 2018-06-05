#include "Header.h"

int main(void)
{
	FILE *infile = NULL;
	int size = 0, n = 0, arrays[5] = { 0 }, index = 0, a=1, b=1;
	int p = &a;
	infile = fopen("Text.txt", "r");
	for (int i = 0; i < 5; i++)
		fscanf(infile,"%d",&arrays[i]);
	
	for (int i = 0; i < 5; i++)
		printf("%d\n", arrays[i]);

	plus(&

}