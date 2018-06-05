#include "Header.h"


int main(void)
{
	int r = 0;
	r = randomgen();
	printf("\n\n answer:%d\n", r);
	game(r);


	return 0;
}