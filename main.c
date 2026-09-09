#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int gameBoard[15][15];
int headX, headY;
int fruitX, fruitY;
int tailX[100], tailY[100], tailLength;
bool gameOver;
char dir;

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

void input() {
    if (_kbhit()) {
        char key = _getch();

        if (key == 'w') {
            dir = 'w';
        }
        if (key == 's') {
            dir = 's';
        }
        if (key == 'a') {
            d ir = 'a';
        }
        if (key == 'd') {
            dir = 'd';
        }
    }
}

void logic() {
    // Рух голови
    if (dir == 'w') {
        headY--;
    } else if (dir == 's') {
        headY++;
    } else if (dir == 'a') {
        headX--;
    } else if (dir == 'd') {
        headX++;
    }

    // Поїдання фрукту
    if (headX == fruitX && headY == fruitY) {
        tailLength++;
        fruitX = rand() % 13;
        fruitY = rand() % 13;
    }

    // Рух хвоста
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = headX;
    tailY[0] = headY;

    for (int i = 0; i < tailLength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    if (headX == 0 || headY == 0 || headX == 14 || headY == 14) {
        gameOver = true;
    }
    for (int i = 0; i < tailLength; i++) {
        if (headX == tailX[i] && headY == tailY[i]) {
            gameOver = true;
        }
    }
}