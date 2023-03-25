#include "mylib.h"
#include "board.h"
#include "logic.h"
#include "eventDispatch.h"
#include "menu.h"
#include "pictures.h"
#include "player.h"
#include "typeOfBoard.h"

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

int main() {
	play();
	
	return 0;
}
