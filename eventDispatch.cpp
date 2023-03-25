#include "logic.cpp"
#include "player.cpp"

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
	cout << "(¯`·.·´¯) (¯`·.·´¯)";
	gotoxy(80, 26);
	cout << "`·.¸(¯`·.·´¯)¸ .·";
	gotoxy(80, 27);
	cout << "×°× ` ·.¸.·´ ×°×";
}

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

