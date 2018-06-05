#include "Header.h"

int main(void)
{
	Account acc1 = { 0,0.0 };
	Stats p1_stats = { 0,0,0,0.0 }, p2_stats = { 0,0,0,0.0 };
	Account custmers[100] = { {000000,0.0} };
	FILE *input = fopen("data.csv", "r");
	char line[100] = "", *token_ptr = NULL;
	char *token_array[5] = { NULL };
	int length = 0, count = 0, customer_num = 0;
	p1_stats = update_stats(p1_stats, 1);
	update_stats2(&p1_stats, 0);
	//2017-03-22, String in C
	if (input != NULL)
	{
		puts("File successfuly loaded\n");
		while (!feof(input))
			fgets(line, 100, input);
		puts(line);
		//get the first token in the line
		token_array[0] = strtok(line, ",");
		while (token_array[count] != NULL)
		{
			++count;
			puts(token_ptr);
			length = strlen(token_ptr);
			//puts(&line[length + 1]);
			token_array[count] = strtok(NULL, ",");
		}// done spliting one line
		//acc1.SSN = atoi(token_array[2]);//find if that string is in memory
		//printf("SSN: %d\n", acc1.SSN);
		//acc1.age = atof(token_array[3]);

		custmers[customer_num].SSN = atoi(token_array[2]);
		customers[customer_num].age = atof(token_array[3]);
		printf("age: %lf\n", customers[customer_num].age)
		customer_num++;
	}
}
	return 0;
}