#include "Header.h"

void reverse_string(char string[])
{
	int length = 0,j=0, i=0;
	char c = '\0',d='\0';

	while (string[j] != NULL)
	{
		j += 1;
		length += 1;
	}
	printf("%d\n", length);
	while (i < (length)/2)
	{
		c = string[i];
		string[i] = string[length -1 - i];
		string[length - 1 - i] = c;

		++i;

	}

	



}