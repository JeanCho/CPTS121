#include "Header.h"


char y_n(void)
{
	char reply = '\0';
	printf("\nPlease enter your answer y/n\n");
	scanf(" %c", &reply);
	return reply;

}