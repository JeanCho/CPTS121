#include "Header.h"

int main(void)
{
	char getstr = NULL;
	FILE *stream = fopen("string.txt", "r");
	getstr = *my_fgets(&getstr, 5, stream);
	printf("%s", getstr);


}