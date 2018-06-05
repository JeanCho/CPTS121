#include "Header.h"

int main(void)
{
	student student1;
	student * pointer = &student1;
	int r = 0;
	sentence list1; 
	char sentence[20][100] = { "\0" };
	student1.name = "Jean";
	pointer->age = 19;

	list1.article[0] ="the ";
	list1.article[1] = "a ";
	list1.article[2] = "one ";
	list1.article[3] = "some ";
	list1.article[4] = "any ";
	list1.noun[0] = "boy";
	list1.noun[1] = "girl";
	list1.noun[2] = "dog";
	list1.noun[3] = "town";
	list1.noun[4] = "car";
	list1.verb[0] = " drove";
	list1.verb[1] = " jumped";
	list1.verb[2] = " ran";
	list1.verb[3] = " walked";
	list1.verb[4] = " skipped";
	list1.preposition[0] = " to";
	list1.preposition[1] = " from";
	list1.preposition[2] = " under";
	list1.preposition[3] = " over";
	list1.preposition[4] = " on";
	
	build_sentence(sentence, list1);
	display_array(sentence);

	return 0;


}