#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void welcome_screen(void);
int manual_or_random(void);
void initialize_game_board(char matrix[10][10]);
void display_board(char matrix[10][10] ,int i,int j);
void  manually_place_ships_on_board(char matrix[10][10]);
void randomly_place_ships_on_board(char matrix[10][10]);
int check_shot(char matrix[10][10],int x, int y);
void is_winner(int score, int p);
void update_board(char matrix[10][10],int check, int x, int y);
void output_current_move(FILE *outfile,int player,int x, int y,int hom);
void check_if_sunk_ship(char matrix[10][10], int *cdestroyed, int *bdestroyed, int *rdestroyed, int *sdestroyed, int *ddestroyed);
void output_stats(FILE *outfile, int p1shot, int p2shot,int total_turn,int winner, int p1_score, int p2_score);
int select_who_starts_first(void);
