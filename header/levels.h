#pragma once
#include "mylib.h"

void printBoxOfLevel(string boxOfLevel[], int x_level, int y_level) {
    for (int i = 0; i < 3; i++) {
        gotoxy(x_level, y_level);
        cout << boxOfLevel[i] << endl;
        y_level ++;
    }   
} 

void levels() {
    ShowConsoleCursor(false);
    // 15 x 3
    string boxOfLevel[3] = {
        "x---------------x",
        "|               |",
        "x---------------x"
    };

    TextColor(10);
    gotoxy(40, 0);
    cout << " ___       _______   ___      ___ _______   ___       ________      ";
    gotoxy(40, 1);
    cout << "|\\  \\     |\\  ___ \\ |\\  \\    /  /|\\  ___ \\ |\\  \\     |\\   ____\\     ";
    gotoxy(40, 2);
    cout << "\\ \\  \\    \\ \\   __/|\\ \\  \\  /  / | \\   __/|\\ \\  \\    \\ \\  \\___|_    ";
    gotoxy(40, 3);
    cout << " \\ \\  \\    \\ \\  \\_|/_\\ \\  \\/  / / \\ \\  \\_|/_\\ \\  \\    \\ \\_____  \\   ";
    gotoxy(40, 4);
    cout << "  \\ \\  \\____\\ \\  \\_|\\ \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\____\\|____|\\  \\  ";
    gotoxy(40, 5);
    cout << "   \\ \\_______\\ \\_______\\ \\__/ /     \\ \\_______\\ \\_______\\____\\_\\  \\ ";
    gotoxy(40, 6);
    cout << "    \\|_______|\\|_______|\\|__|/       \\|_______|\\|_______|\\_________\\";
    gotoxy(40, 7);
    cout << "                                                        \\|_________|";

    TextColor(11);
    printBoxOfLevel(boxOfLevel, 20, 20);
    gotoxy(6 + 20, 21);
    cout << "EASY";

    TextColor(10);
    printBoxOfLevel(boxOfLevel, 45, 20);
    gotoxy(5 + 45, 21);
    cout << "NORMAL";

    TextColor(9);
    printBoxOfLevel(boxOfLevel, 70, 20);
    gotoxy(5 + 70, 21);
    cout << "MEDIUM";

    TextColor(12);
    printBoxOfLevel(boxOfLevel, 95, 20);
    gotoxy(6 + 95, 21);
    cout << "HARD";

    TextColor(5);
    printBoxOfLevel(boxOfLevel, 120, 20);
    gotoxy(6 + 120, 21);
    cout << "ASIA";

    char key_choice = 0;
    int Steps;
    
    switch(key_choice = getch()) {
    	case EASY:
            system("cls");
            EventDispatches_EASY();
    	break;
    	case NORMAL:
            system("cls");
            EventDispatches_NORMAL();
    	break;
        case MEDIUM:
            system("cls");
            EventDispatches_MEDIUM();
		break;
		case HARD:
            system("cls");
            EventDispatches_HARD();
		break;
		case ASIA:
            system("cls");
			cout << "ASIA";
		break;
	}
}