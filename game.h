#ifndef GAME_H
#define GAME_H

#define current_char ((x_to_move) ? 'X' : 'O')
// #define max(x, y) ((x > y) ? x : y)
// #define min(x, y) ((x < y) ? x : y)

#include <stdio.h>

void make_move(int row, int col, char board[9], int x_to_move);
int check_for_win(int x_to_move, char board[9]);
void get_move(char board[9], int x_to_move);
int check_for_draw(char board[9]);
int minimax(int initial_call, int x_to_move, char board[9]);

#endif