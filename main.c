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


