#pragma once
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACE 32	// select First Pokemon
#define ENTER 13	// select Second Pokemon

#define EASY 101
#define HARD 104

using namespace std;

int n_rows = 8, n_cols = 8, n_types = 26;

vector<int> countAlphabets = {2, 4, 2, 2, 8, 2, 2, 4, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4};

char** pokemons = new char*[n_rows];

int x = 0, y = 0;	// index trong mang khi lua chon pokemon
int _x = -1, _y = -1;	// index trong mang cua pokemon thu 2

char bg[20][41];


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
