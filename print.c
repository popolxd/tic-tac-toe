#include "print.h"

void print_board(char board[9]) {

    print_mult_chars('-', 7);
    
    for (int i = 0; i < 3; i++) {
        printf("|");

        for (int j = 0; j < 3; j++) {
            printf("%c|", board[i*3 + j]);
        }
        print_mult_chars('-', 7);
    }
}

void print_mult_chars(char c, int num) {
    printf("\n");

    for (int i = 0; i < num; i++) {
        printf("%c", c);
    }

    printf("\n");
}

void print_bullshit() {
    printf("Insert your move: (row col)\n");
}

void print_winner(int x_to_move) {
    printf("Player %c won!\n", (x_to_move) ? 'X' : 'O');
}

void print_draw() {
    printf("Draw!\n");
}