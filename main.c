#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

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

    fruitX = 1 + rand() % 13;
    fruitY = 1 + rand() % 13;

    gameOver = false;

    tailLength = 0;
}

void boardView() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            bool isTail = false;

            for (int k = 0; k < tailLength; k++) {
                if (tailX[k] == j && tailY[k] == i) {
                    isTail = true;
                    break;
                }
            }

            if (headY == i && headX == j) {
                printf("O");
            } else if (fruitY == i && fruitX == j) {
                printf("F");
            } else if (i == 0 || j == 0 || i == 14 || j == 14 ) {
                printf("#");
            } else if (isTail) {
                printf("o");
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
            dir = 'a';
        }
        if (key == 'd') {
            dir = 'd';
        }
    }
}

void logic() {
    // Рух хвоста
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = headX;
    tailY[0] = headY;

    for (int i = 1; i < tailLength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

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
        fruitX = 1 + rand() % 13;
        fruitY = 1 + rand() % 13;
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

int main() {
    setup();

    while (!gameOver) {
        system("cls");
        input();
        logic();
        boardView();

        Sleep(1000);
    }

    printf("\nGAME OVER\n");
    return 0;
}