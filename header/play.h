#pragma once
#include "mylib.h"

void play() {
	// ===== INIT MAIN MENU =====
	
	system("cls");
	int choiceInMenu = MainMenu();
	
	if (choiceInMenu == 1) {
		system("cls");
		levels();
		int key = 0;
		while (key = getch()) {
			if (key == KEY_LEFT) {
				system("cls");
				play();
				break;
			}
		}
	}
	
	if (choiceInMenu == 2) {
		credits();
		int key = 0;
		while (key = getch()) {
			if (key == KEY_LEFT) {
				system("cls");
				play();
				break;
			}
		}
	}

	if (choiceInMenu == 3) {
		leaderboard();
		int key = 0;
		while (key = getch()) {
			if (key == KEY_LEFT) {
				system("cls");
				play();
				break;
			}
		}
	}

	if (choiceInMenu == 4) {
		howToPlay();
		int key = 0;
		while (key = getch()) {
			if (key == KEY_LEFT) {
				system("cls");
				play();
				break;
			}
		}
	}
	
	if (choiceInMenu == 5) {
		cout << "EXIT";
		return;
	}
}
