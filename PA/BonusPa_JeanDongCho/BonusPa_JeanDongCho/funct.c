#include "Header.h"



char *rec_reverse(char *str, int length)
{
	char temp = '\0';
	if (length >1)
	{
		//swap
		temp = *str;
		*str = *(str + length - 1);
		*(str + length - 1) = temp;

		str = *rec_reverse(str + 1, length - 1);
	}
	else
	{
		return str;
	}
}

char *my_fgets(char *s, int n, FILE *stream)
{
	s = (char*)malloc(n * sizeof(char));
	fgets(s, n, stream);

	return s;
}