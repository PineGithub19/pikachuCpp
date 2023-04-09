#pragma once
#include "mylib.h"

void calTime(int &prev_time, int &time_left) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int curr_time = ltm->tm_sec;    // THOI GIAN HIEN TAI

    if (abs(curr_time - prev_time == 1) && time_left >= 0) {
        time_left --;
    }
    prev_time = curr_time;
}

void showTime(int time_left) {
//	ShowConsoleCursor(false);
    int _minutes = time_left / 60;
    int _seconds = time_left % 60;
	gotoxy(120, 0);
    TextColor(7);
    cout << setfill('0') << setw(2) << _minutes << " : " << setfill('0') << setw(2) << _seconds;
    if (_seconds == 0) {
        _minutes --;
    }
}
