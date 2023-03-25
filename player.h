#pragma once
#include "mylib.h"

struct Info {
	string name;
	int scores = 0;
}; 

void initPlayer(Info &player) {
	cout << "Enter Your Name: ";
	getline(cin, player.name);
}

void showScores(Info Player) {
	gotoxy(50, 0);
	TextColor(11);
	cout << "YOUR SCORES: " << Player.scores;
}

void showTime(int &hrs, int &mins, int &secs, bool _checkEmptyBoard) {
	if (secs > 0) {
		secs --;
	}
	if (secs == 0) {
		mins --;
		secs = 59;
	}
	if (mins == 0) {
		hrs --;
		if (hrs > 0) {
			mins = 59;
		}
		else {
			mins = 0;
		}
	}	

	gotoxy(80, 0);
	TextColor(12);
	cout << "YOUR TIME: ";
	cout << setfill('0') << setw(2) << hrs << " : " << setfill('0') << setw(2) << mins << " : " << setfill('0') << setw(2) << secs;
	
	sleep(1);
}

void winerWinerChickenDinner(Info Player) {
	TextColor(11);
	gotoxy(50, 10);
    cout << "__  ______  __  __  _      ______  _  __";
    gotoxy(50, 11);
    cout << "\\ \\/ / __ \\/ / / / | | /| / / __ \\/ |/ /";
    gotoxy(50, 12);
    cout << " \\  / /_/ / /_/ /  | |/ |/ / /_/ /    /";
    gotoxy(50, 13);
    cout << " /_/\\____/\\____/   |__/|__/\\____/_/|_/";
    
    gotoxy(45, 18);
    TextColor(6);
    cout << "Chuc mung ";
    TextColor(12);
    cout << Player.name;
    TextColor(6);
    cout << " da chien thang game Pikachu =))";
    
    gotoxy(55, 20);
    TextColor(11);
    cout << "You won with ";
    cout << Player.scores << " scores";
    
    TextColor(12);
	gotoxy(80, 25);
	cout << "(�`�.���) (�`�.���)";
	gotoxy(80, 26);
	cout << "`�.�(�`�.���)� .�";
	gotoxy(80, 27);
	cout << "װ� ` �.�.�� װ�";
}
