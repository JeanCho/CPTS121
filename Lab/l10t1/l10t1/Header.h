#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct student
{
	int age;
	char* name;
}student;

typedef  struct sentence
{
	char noun[5], verb[5], preposition[5], article[5];

}sentence;

void build_sentence(char Sentence[20][100],sentence list);
void display_array(char sentence[20][100]);