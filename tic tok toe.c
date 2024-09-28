#include <stdio.h>

#define size 3

void initializeBoard(char *board);
void displayBoard(char *board);
int checkwin(char *board);
void makemove(char *board, int player);

int main() {
    char board[size][size];
    int currentplayer = 1, result = -1;
    initializeBoard(&board[0][0]);
    while (result == -1) {
        displayBoard(&board[0][0]);
        makemove(&board[0][0], currentplayer);
        result = checkwin(&board[0][0]);
        if (result == -1) {
            currentplayer = (currentplayer % 2) + 1;
        }
    }
    displayBoard(&board[0][0]);
    if (result == 1) {
        printf("Player %d wins!\n", currentplayer);
    } else {
        printf("It is a draw!\n");
    }
    return 0;
}

void initializeBoard(char *board) {
    for (int i = 0; i < size * size; i++) {
        *(board + i) = '1' + i;
    }
}

void displayBoard(char *board) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", *(board + i * size + j));
            if (j < size - 1) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i < size - 1) {
            printf("---|---|---\n");
        }
    }
}

void makemove(char *board, int player) {
    int move;
    char mark = (player == 1) ? 'x' : 'o';
    do {
        printf("Player %d, enter your move (1-9): ", player);
        scanf("%d", &move);
    } while (move < 1 || move > 9 || *(board + move - 1) == 'x' || *(board + move - 1) == 'o');
    *(board + move - 1) = mark;
}

int checkwin(char *board) {
    int winComb[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
        {0, 4, 8}, {2, 4, 6}  // diagonals
    };
    for (int i = 0; i < 8; i++) {
        if (*(board + winComb[i][0]) == *(board + winComb[i][1]) && *(board + winComb[i][1]) == *(board + winComb[i][2])) {
            return 1;
        }
    }
    for (int i = 0; i < size * size; i++) {
        if (*(board + i) != 'x' && *(board + i) != 'o') {
            return -1;
        }
    }
    return 0;
}
