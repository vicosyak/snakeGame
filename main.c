#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int gameBoard[15][15];
int headX, headY;
int fruitX, fruitY;
int tailX[100], tailY[100], tailLength;
bool gameOver;

void setup() {
    srand(time(NULL));

    headX = 8;
    headY = 8;

    fruitX = rand() % 15;
    fruitY = rand() % 15;

    gameOver = false;

    tailLength = 0;
}

char boardView() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (headY == i && headX == j) {
                printf("0");
            } else if (fruitY == i && fruitX == j) {
                printf("F");
            } else if (i == 0 || j == 0 || i == 14 || j == 14 ) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


