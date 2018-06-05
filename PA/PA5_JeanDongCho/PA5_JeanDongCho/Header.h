#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int roll_die(void);
void roll_dice(int dice[],int maxitems);
void print_gamerule(void);
int combination(int choice,int combo[]);
int calculate_combo(int input,int dice[]);
int check_combo(int input,int combo[]);
void check_message(int check);
int check_pair(int dice[]);
void combo_message(int pair);
int check_strait(int dice[]);