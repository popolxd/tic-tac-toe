#include "print.h"
#include "game.h"
#include <stdio.h>

int main() {

    int x_to_move = 1;
    int engine = 1;

    char board[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    print_board(board);

    while (1) {

        int row, col;
        print_bullshit();

        if (x_to_move == engine) {
            board[minimax(1, x_to_move, board)] = ((x_to_move) ? 'X' : 'O');
        } else {
            get_move(board, x_to_move);
        }

        print_board(board);
        
        if (check_for_win(x_to_move, board)) {
            print_winner(x_to_move);
            break;
        } else if (check_for_draw(board)) {
            print_draw();
            break;
        }

        x_to_move = !x_to_move;
    }

    return 0;
}