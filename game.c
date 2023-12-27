#include "game.h"

void make_move(int row, int col, char board[9], int x_to_move) {

    if (board[row*3 + col] == '-') {
        board[row*3 + col] = current_char;
    }
}

void get_move(char board[9], int x_to_move) {
    int row, col;

    scanf("%d %d", &row, &col);

    if (board[row*3 + col] == '-') {
        make_move(row, col, board, x_to_move);
    } else {
        printf("Invalid move!\n");
        get_move(board, x_to_move);
    }
}

int check_for_win(int x_to_move, char board[9]) {

    for (int i = 0; i < 3; i++) {
        if (board[i*3] == board[i*3 + 1] && board[i*3] == board[i*3 + 2] && board[i*3] == current_char) {
            return 1;
        }

        if (board[i] == board[i + 3] && board[i] == board[i + 6] && board[i] == current_char) {
            return 1;
        }
    }

    if (board[0] == board[4] && board[0] == board[8] && board[0] == current_char) {
        return 1;
    }
    if (board[2] == board[4] && board[2] == board[6] && board[2] == current_char) {
        return 1;
    }

    return 0;
}

int check_for_draw(char board[9]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == '-') {
            return 0;
        }
    }

    return 1;
}

int minimax(int initial_call, int x_to_move, char board[9]) {
    int best_eval;
    int best_move;

    if (x_to_move) {

        best_eval = -2;
        best_move = -1;

        for (int i = 0; i < 9; i++) {

            if (board[i] == '-') {
                board[i] = current_char;

                if (check_for_win(x_to_move, board)) {
                    board[i] = '-';
                    return (initial_call) ? i : 1;
                } else if (check_for_draw(board)) {
                    board[i] = '-';
                    return (initial_call) ? i : 0;
                }

                int result = minimax(0, !x_to_move, board);

                if (result > best_eval) {
                    best_eval = result;
                    best_move = i;
                }

                board[i] = '-';
            }
        }

    } else {

        best_eval = 2;
        best_move = -1;

        for (int i = 0; i < 9; i++) {

            if (board[i] == '-') {
                board[i] = current_char;

                if (check_for_win(x_to_move, board)) {
                    board[i] = '-';
                    return (initial_call) ? i : -1;
                } else if (check_for_draw(board)) {
                    board[i] = '-';
                    return (initial_call) ? i: 0;
                }

                int result = minimax(0, !x_to_move, board);

                if (result < best_eval) {
                    best_eval = result;
                    best_move = i;
                }

                board[i] = '-';
            }
        }
    }

    if (initial_call) {
        return best_move;
    } else {
        return best_eval;
    }
}