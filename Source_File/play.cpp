#include "Header_File/play.h"

void play() {
	// ===== INIT MAIN MENU =====
	int choiceInMenu = MainMenu();
	
	if (choiceInMenu == 1) {
		system("cls");
		EventDispatches(choiceInMenu);
	}
	
	if (choiceInMenu == 2) {
		system("cls");
		EventDispatches(choiceInMenu);
	}
}