#include <stdio.h>
#include <string.h>
#define  CHARACTER 1
#define INTEGER 2
#define EXIT 3


typedef struct acount
{
	int SSN;
	double age;
} Account;


typedef struct stats
{
	int total_hits;
	int total_misses;
	int total_shots;
	double hits_misses;

}Stats;
void update_stats2(Stats *curr_stats_ptr, int hit);
Stats update_stats(Stats curr_stats, int hit);