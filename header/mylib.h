#pragma once
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <fstream>

#include <mmsystem.h>	// chay file nhac

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACE 32	// select First Pokemon
#define ENTER 13	// select Second Pokemon

#define EASY 101    // e
#define NORMAL 110  // n
#define MEDIUM  109 //  m
#define HARD 104    // h
#define ASIA 97 // a

#define PLAY 112
#define CREDITS 99
#define LEADERBOARD 108
#define HOWTOPLAY 63
#define ESC 27

#define HINT 33 // !
#define REFRESH 114 //  r
#define RESTART 116 // t

using namespace std;

int n_rows = 8, n_cols = 8, n_types = 26;

vector<int> countAlphabets = {2, 4, 2, 2, 8, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4};

char** pokemons = new char*[n_rows];

int x = 0, y = 0;	// index trong mang khi lua chon pokemon
int _x = -1, _y = -1;	// index trong mang cua pokemon thu 2

void gotoxy(int x__, int y__)
{
  	COORD coord;

    coord.X = x__;
    coord.Y = y__;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// https://tuicocach.com/viet-ham-thay-doi-mau-chu-trong-man-hinh-console-c-c/
void TextColor(int x)//X l� m� m�u
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

//https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt#:~:text=You%20can%20hide%20the%20cursor%20by%20calling%20SetConsoleCursorInfo%20.%20.&text=Also%20make%20sure%20to%20set,100%2C%20else%20SetConsoleCursorInfo%20will%20fail.
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

