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

using namespace std;

void gotoxy(int x__, int y__)
{
  	COORD coord;

    coord.X = x__;
    coord.Y = y__;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// https://tuicocach.com/viet-ham-thay-doi-mau-chu-trong-man-hinh-console-c-c/
void TextColor(int x)//X là mã màu
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
