#include "Header.h"

Stats update_stats(Stats curr_stats, int hit)
{
	if (hit ==1)
	{
		curr_stats.total_hits += 1;
	}
	else//if it's miss
	{
		curr_stats.total_misses += 1;
	}
	curr_stats.total_shots += 1;
	return curr_stats;
}

void update_stats2(Stats *curr_stats_ptr, int hit)
{
	if (hit == 1)
	{
		(*curr_stats_ptr).total_hits += 1;
	}

	else
	{
		curr_stats_ptr->total_misses+=1;
	}
}

char determine_letter_grade(int score)
{
	double grade = '0';

	if (score >= 90)
	{
		grade = 'A';
	}

	
	else if (score >= 80)
	{
		grade = 'B';
	}

	else if (score >= 70)
	{
		grade = 'C';
	}


	else if (score >= 60)
	{
		grade = 'D';
	}

	else
	{
		grade = 'F';
	}


	return grade;
}

void switchswitch(FILE *infile)
{
	int option = 0,count =0,numb=0;
	char character = '\0';
	for (count=0; count <10; count+=1)
	{
		printf("%d", count);

	}
	if (infile != NULL)
	{
		while ((option < 1) || (option > 3))
		{
			printf("1.read a char\n");
			printf("2.read an int\n");
			printf("3.Exit.\n");
			scanf("%d", &option);
		}
		if (option == 1)
		{
			while (!feof(infile))//read entire file contents
			{
				fscanf(infile, "%c",character);
				putc(character, stdout); //stdin
			}
		}




		/*switch (option)
		{
		case CHARACTER: fscanf(infile, "%c", &character);
			printf("character:%c\n", character);
			break;

		case INTEGER: fscanf(infile, "%d", &numb);
			printf("number:%d\n", numb);
			break;
		case EXIT:printf("Exit\n");

	}*/
	
	}
}