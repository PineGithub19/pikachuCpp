#include "Header_File/eventDispatch.h"

void EventDispatches(int choiceInMenu) {
	// ===== INIT PLAYER INFO =====
	Info Player;
	initPlayer(Player);
	system("cls");
	
	// ===== INIT BOARD =====
		
	if (choiceInMenu == 2) {
		n_rows += 2;
		n_cols += 2;
		countAlphabets = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2};
	}	
	
	input2DArr(pokemons);
	
   	Board(n_rows, n_cols, n_types, countAlphabets, pokemons);
	
    printGirdOfPokemons(pokemons, n_rows);
    
    // =======================
	
	int coordinatesX = 3, coordinatesY = 1;	// toa do trong console
	int selectedX, selectedY;	// index trong mang cua pokemon thu nhat
	int key;
	bool CheckFirst = false;	// kiem tra xem co chon pokemon thu nhat hay chua
	bool _checkEmptyBoard = false;	// kiem tra xem mang co bi an het hay chua
	
	// ===== ten cua nguoi choi =====
	gotoxy(80, 0);
	cout << "Hello ";
	TextColor(12);
	cout << Player.name;
	TextColor(7);
	cout << " dep trai";
	//===============================
	
	// ===== diem cua nguoi choi =====
	showScores(Player);
	gotoxy(coordinatesX, coordinatesY);
	// ===============================
	
	// ===== thoi gian cua nguoi choi =====
	//int hrs = 0, mins = 1, secs = 59;
	//showTime(hrs, mins, secs, _checkEmptyBoard);
	// ====================================
	
	// ===== dung de random mau =====
	static int colors[] = {1, 2, 3, 4, 5, 6, 9, 10, 11, 12};
	int indexColor;
	//===============================

	while(true && !_checkEmptyBoard) {
		key = 0;
		switch((key = getch())) {
			case KEY_UP:
				coordinatesY -= 2;
				gotoxy(coordinatesX, coordinatesY);
				x --;
					
				if (coordinatesY < 0) {
					coordinatesY = (2 * n_rows - 1);
					gotoxy(coordinatesX, coordinatesY);
					x = n_rows - 1;
				}
			break;
			case KEY_DOWN:
				coordinatesY += 2;
				gotoxy(coordinatesX, coordinatesY);
				x++;
				
				if (coordinatesY > (2 * n_rows - 1)) {
					coordinatesY = 1;
					gotoxy(coordinatesX, coordinatesY);
					x = 0;
				}
			break;
			case KEY_LEFT:
				coordinatesX -= 4;
				gotoxy(coordinatesX, coordinatesY);
				y--;
				
				if (coordinatesX <= 1) {
					coordinatesX = (4 * n_cols - 1);
					gotoxy(coordinatesX, coordinatesY);
					y = n_cols - 1;
				}
			break;
			case KEY_RIGHT:
				coordinatesX += 4;
				gotoxy(coordinatesX, coordinatesY);
				y++;
				
				if (coordinatesX > (4 * n_cols - 1)) {
					coordinatesX = 3;
					gotoxy(coordinatesX, coordinatesY);
					y = 0;
				}
			break;
			case SPACE:
					selectedX = x; 	
					selectedY = y;
					CheckFirst = true;
					gotoxy(50, 5);
					cout << "First Choice: " << pokemons[selectedX][selectedY];
					gotoxy(coordinatesX, coordinatesY);
			break;
			case ENTER:
				if (CheckFirst) {
					CheckFirst = false;
					_x = x;
					_y = y;
					
					gotoxy(50, 10);
					cout << "Second Choice: " << pokemons[_x][_y];
					gotoxy(coordinatesX, coordinatesY);
					
					if (selectPokemon(selectedX, selectedY) && pokemons[selectedX][selectedY] != '0' && pokemons[_x][_y] != '0') {
						Player.scores += 10;
						removePokemon(selectedX, selectedY, pokemons);
						removePokemon(_x, _y, pokemons);

						// ============ random mau cho bang ==================   
						indexColor = rand() % (sizeof colors / sizeof *colors);
						TextColor(colors[indexColor]);
						// ====================================================
						gotoxy(0, 0);
						printGirdOfPokemons(pokemons, n_rows);
						if (checkEmptyBoard(pokemons))
							_checkEmptyBoard = true;
						
						// ========== hien thi diem so =====
						showScores(Player);
						// =================================
						gotoxy(coordinatesX, coordinatesY);	// dieu chinh toa do chuot lai o moi vua xoa
					}
				}
			break;
		}
	}
	if (_checkEmptyBoard) {
		freedom2DArr(pokemons);
		system("cls");
		winerWinerChickenDinner(Player);
	}
}

