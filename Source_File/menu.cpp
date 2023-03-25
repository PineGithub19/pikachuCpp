#include "Header_File/menu.h"

void printMenuFrame(string menuFrame[], int x_menu, int y_menu) {
	for (int i = 0; i < 5; i++) {
		gotoxy(x_menu, y_menu);
		cout << menuFrame[i] << endl;
		y_menu++;
	}
}

int MainMenu() {
	int choice[2] = {1, 2};
	
	string menuFrame[] ={
		"x--------------------x",
		"|                    |",
		"|                    |",
		"|                    |",
		"x--------------------x"
	};
	
    TextColor(6);
	gotoxy(35, 2);
    cout << " ______    __   __  ___      ___       ______  __    __   __    __";
    gotoxy(35, 3);
    cout << "|   _  \\  |  | |  |/  /     /   \\     /      ||  |  |  | |  |  |  |";
    gotoxy(35, 4);
    cout << "|  |_)  | |  | |  '  /     /  ^  \\   |  ,----'|  |__|  | |  |  |  |";
    gotoxy(35, 5);
    cout << "|   ___/  |  | |    <     /  /_\\  \\  |  |     |   __   | |  |  |  |";
    gotoxy(35, 6);
    cout << "|  |      |  | |  .  \\   /  _____  \\ |  `----.|  |  |  | |  `--'  |";
    gotoxy(35, 7);
    cout << "| _|      |__| |__|\\__\\ /__/     \\__\\ \\______||__|  |__|  \\______/";
    
    TextColor(3);
    printMenuFrame(menuFrame, 55, 12);
    
    gotoxy(64, 14);
    TextColor(11);
    cout << "EASY";
    
    TextColor(4);
    printMenuFrame(menuFrame, 55, 20);
    
    gotoxy(64, 22);
    TextColor(12);
    cout << "HARD";
    
	TextColor(11);
	gotoxy(90, 12);
	cout << "Press 'E' to choose EASY LEVEL";
	gotoxy(90, 14);
	cout << "Press 'H to choose HARD LEVEL"; 
	
	TextColor(7);
    
    char key_choice = 0;
    
    switch(key_choice = getch()) {
    	case EASY:
    		return choice[0];
    	break;
    	case HARD:
    		return choice[1];
    	break;
	}
}
