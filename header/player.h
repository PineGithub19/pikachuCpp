#pragma once
#include "mylib.h"

struct Info {
	char name[256];
	int scores = 0;
}; 

void initPlayer(Info &Player) {
	cout << "Enter Your Name: ";
	cin.getline(Player.name, 255);
}

void showScores(Info Player) {
	gotoxy(50, 0);
	TextColor(11);
	cout << "YOUR SCORES: " << Player.scores;
}

// void printSteps(int Steps) {
// 	gotoxy(50, 10);
// 	TextColor(11);
// 	cout << "YOUR REMAINING STEPS: ";
// 	if (Steps >= 25) 
// 		TextColor(10);
// 	else if (Steps >= 10 && Steps < 25)
// 		TextColor(5);
// 	else if (Steps < 10)
// 		TextColor(12);
// 	(Steps != -1) ? cout << setfill('0') << setw(2) << Steps : cout << "Inf";
// }

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
}

void loserloserChicken(Info Player) {
    TextColor(12);
	gotoxy(50, 10);
	cout << "__  ______  __  __  __   ____  ________";
	gotoxy(50, 11);
	cout << "\\ \\/ / __ \\/ / / / / /  / __ \\/ __/ __/";
	gotoxy(50, 12);
	cout << " \\  / /_/ / /_/ / / /__/ /_/ /\\ \\/ _/";
	gotoxy(50, 13);
	cout << " /_/\\____/\\____/ /____/\\____/___/___/";

	gotoxy(45, 18);
    TextColor(6);
    cout << "HAHAHAHA ";
    TextColor(12);
    cout << Player.name;
    TextColor(6);
    cout << " da thua game Pikachu =))";
    
    gotoxy(55, 20);
    TextColor(11);
    cout << "You lose with ";
    cout << Player.scores << " scores";
}
