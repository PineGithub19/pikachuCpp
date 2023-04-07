#pragma once
#include "mylib.h"
#include "player.h"
#include "typeOfBoard.h"
#include "push.h"
#include "recommended_move.h"
#include "pictures.h"
#include "file.h"
#include "time_left.h"

void EventDispatches_EASY() {
	ShowConsoleCursor(true);

	int coordinatesX = 3, coordinatesY = 1;	// toa do trong console
	int selectedX, selectedY;	// index trong mang cua pokemon thu nhat
	int countRefresh = 5;
	char key;
	bool _CheckFirst = false;	// kiem tra xem co chon pokemon thu nhat hay chua
	bool _checkEmptyBoard = false;	// kiem tra xem mang co bi an het hay chua

	// ----- CAC BIEN TINH THOI GIAN -----
	int time_left = 180;		// THOI GIAN CON LAI DANH CHO NGUOI CHOI
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int prev_time = ltm->tm_sec;	// THOI GIAN KHI BAT DAU GAME
	int minutes = time_left / 60;
    int seconds = time_left % 60;

	// ----- Recommended Moves -----
	int recommended_X1, recommended_X2, recommended_Y1, recommended_Y2;

	// ===== INIT PLAYER INFO =====
	Info Player;
	initPlayer(Player);
	findPlayerName(Player);
	system("cls");
	
	// ========== BACKGROUND ==========
	int n = 12, m = 25;

	char** bg = new char*[n];
	for (int i = 0; i < n; i++) {
		bg[i] = new char[m];
	}

	getBackground_EASY(bg);

	// ===== INIT BOARD =====
	EASY_LEVEL(n_rows, n_cols, n_types, countAlphabets);

	gotoxy(0, 0);
	
	input2DArr(pokemons);
	
   	Board(n_rows, n_cols, n_types, countAlphabets, pokemons);
	
    printGirdOfPokemons(pokemons, n_rows);
    
	if (recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2))
		printRecommendedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);

    // =======================
	
	// ===== ten cua nguoi choi =====
	gotoxy(80, 0);
	cout << "Hello ";
	TextColor(12);
	cout << Player.name;
	TextColor(7);
	cout << " dep zai";
	//===============================

	// ===== THOI GIAN =====
	gotoxy(120, 0);
	cout << setfill('0') << setw(2) << minutes << " : " << setfill('0') << setw(2) << seconds;
	// =====================
	
	printRefresh(countRefresh);

	// ===== diem cua nguoi choi =====
	showScores(Player);
	gotoxy(coordinatesX, coordinatesY);
	// ===============================
	
	// ===== dung de random mau =====
	static int colors[] = {1, 2, 3, 4, 5, 6, 9, 10, 11, 12};
	int indexColor;
	//===============================
	
	while(true && !_checkEmptyBoard && time_left > 0) {

		// ----- THOI GIAN -----
		showTime(time_left);
		calTime(prev_time, time_left);
		gotoxy(coordinatesX, coordinatesY);
		// ---------------------
		
		if(kbhit()) {
			key = getch();
			if(int(key) == KEY_UP) {
				coordinatesY -= 2;
				gotoxy(coordinatesX, coordinatesY);
				x --;
					
				if (coordinatesY < 0) {
					coordinatesY = (2 * n_rows - 1);
					gotoxy(coordinatesX, coordinatesY);
					x = n_rows - 1;
				}
			}
			if(int(key) == KEY_DOWN) {
				coordinatesY += 2;
				gotoxy(coordinatesX, coordinatesY);
				x++;
				
				if (coordinatesY > (2 * n_rows - 1)) {
					coordinatesY = 1;
					gotoxy(coordinatesX, coordinatesY);
					x = 0;
				}
			}
			if (int(key) == KEY_LEFT) {
				coordinatesX -= 4;
				gotoxy(coordinatesX, coordinatesY);
				y--;
				
				if (coordinatesX <= 1) {
					coordinatesX = (4 * n_cols - 1);
					gotoxy(coordinatesX, coordinatesY);
					y = n_cols - 1;
				}
			}
			if (int(key) == KEY_RIGHT) {
				coordinatesX += 4;
				gotoxy(coordinatesX, coordinatesY);
				y++;
				
				if (coordinatesX > (4 * n_cols - 1)) {
					coordinatesX = 3;
					gotoxy(coordinatesX, coordinatesY);
					y = 0;
				}
			}
			if (int(key) == REFRESH) {
				countRefresh --;
				if (countRefresh >= 0) {
					swapAlphabets(n_rows, n_cols, pokemons);
					printRefresh(countRefresh);
					gotoxy(0, 0);
					printGirdOfPokemons(pokemons, n_rows);
				}
				gotoxy(coordinatesX, coordinatesY);
			}
			if (int(key) == SPACE) {
					selectedX = x; 	
					selectedY = y;

					_CheckFirst = true;
					gotoxy(50, 5);
					cout << "First Choice: " << pokemons[selectedX][selectedY];
					gotoxy(coordinatesX, coordinatesY);
			}
			if (int(key) == ENTER) {
				if (_CheckFirst) {
					_CheckFirst = false;
					_x = x;
					_y = y;
					
					gotoxy(80, 5);
					cout << "Second Choice: " << pokemons[_x][_y];
					gotoxy(coordinatesX, coordinatesY);
					
					if (selectPokemon(selectedX, selectedY) && pokemons[selectedX][selectedY] != '0' && pokemons[_x][_y] != '0') {
						PlaySound(TEXT("songs\\correct.wav"), NULL, SND_FILENAME | SND_ASYNC);
						Player.scores += 10;
						removePokemon(selectedX, selectedY, pokemons);
						removePokemon(_x, _y, pokemons);

						if (checkEmptyBoard(pokemons))
							_checkEmptyBoard = true;
						
						if (recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2))
							printRecommendedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
						
						if (!recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2) && _checkEmptyBoard == false) {
							swapAlphabets(n_rows, n_cols, pokemons);
							recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
							printRecommendedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
							gotoxy(coordinatesX, coordinatesY);
						}
						// ===============================	
						gotoxy(0, 0);
						printBackGround(bg, n_rows, n_cols);
						// ============ random mau cho bang ==================   
						indexColor = rand() % (sizeof colors / sizeof *colors);
						TextColor(colors[indexColor]);
						// ====================================================
						printGirdOfPokemons(pokemons, n_rows);

						// ========== hien thi diem so =====
						showScores(Player);
						// =================================
						gotoxy(coordinatesX, coordinatesY);	// dieu chinh toa do chuot lai o moi vua xoa
					}
					else
						PlaySound(TEXT("songs\\wrong.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
		}
	}
	if (_checkEmptyBoard) {
		freedom2DArr(pokemons);
		freedom2DArr(bg);
		Sleep(3000);
		system("cls");
		PlaySound(TEXT("songs\\goodjob.wav"), NULL, SND_FILENAME | SND_ASYNC);
		winerWinerChickenDinner(Player);
		Player.scores;
		getData(Player);
	}
	else if (time_left <= 0) {
		freedom2DArr(pokemons);
		freedom2DArr(bg);
		system("cls");
		PlaySound(TEXT("songs\\defeat_coc.wav"), NULL, SND_FILENAME | SND_ASYNC);
		loserloserChicken(Player);
		getData(Player);
	}
}

void EventDispatches_NORMAL() {
	ShowConsoleCursor(true);

	int coordinatesX = 3, coordinatesY = 1;	// toa do trong console
	int selectedX, selectedY;	// index trong mang cua pokemon thu nhat
	int countRefresh = 5;
	char key;
	bool _CheckFirst = false;	// kiem tra xem co chon pokemon thu nhat hay chua
	bool _checkEmptyBoard = false;	// kiem tra xem mang co bi an het hay chua

	// ----- CAC BIEN TINH THOI GIAN -----
	int time_left = 180;		// THOI GIAN CON LAI DANH CHO NGUOI CHOI
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int prev_time = ltm->tm_sec;	// THOI GIAN KHI BAT DAU GAME
	int minutes = time_left / 60;
    int seconds = time_left % 60;

	// ----- Recommended Moves -----
	int recommended_X1, recommended_X2, recommended_Y1, recommended_Y2;

	// ===== INIT PLAYER INFO =====
	Info Player;
	initPlayer(Player);
	findPlayerName(Player);
	system("cls");
	
	// ========== BACKGROUND ==========
	int n = 20, m = 41;

	char** bg = new char*[n];
	for (int i = 0; i < n; i++) {
		bg[i] = new char[m];
	}

	getBackground_NORMAL(bg);

	// ===== INIT BOARD =====
	gotoxy(0, 0);
	
	input2DArr(pokemons);
	
   	Board(n_rows, n_cols, n_types, countAlphabets, pokemons);
	
    printGirdOfPokemons(pokemons, n_rows);
    
	if (recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2))
		printRecommendedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);

    // =======================
	
	// ===== ten cua nguoi choi =====
	gotoxy(80, 0);
	cout << "Hello ";
	TextColor(12);
	cout << Player.name;
	TextColor(7);
	cout << " dep zai";
	//===============================

	// ===== THOI GIAN =====
	gotoxy(120, 0);
	cout << setfill('0') << setw(2) << minutes << " : " << setfill('0') << setw(2) << seconds;
	// =====================
	
	printRefresh(countRefresh);

	// ===== diem cua nguoi choi =====
	showScores(Player);
	gotoxy(coordinatesX, coordinatesY);
	// ===============================
	
	// ===== dung de random mau =====
	static int colors[] = {1, 2, 3, 4, 5, 6, 9, 10, 11, 12};
	int indexColor;
	//===============================

	while(true && !_checkEmptyBoard && time_left > 0) {

		// ----- THOI GIAN -----
		showTime(time_left);
		calTime(prev_time, time_left);
		gotoxy(coordinatesX, coordinatesY);
		// ---------------------

		if(kbhit()) {
			key = getch();
			if (key == KEY_UP) {
				coordinatesY -= 2;
				gotoxy(coordinatesX, coordinatesY);
				x --;
					
				if (coordinatesY < 0) {
					coordinatesY = (2 * n_rows - 1);
					gotoxy(coordinatesX, coordinatesY);
					x = n_rows - 1;
				}
			}
			if (key == KEY_DOWN) {
				coordinatesY += 2;
				gotoxy(coordinatesX, coordinatesY);
				x++;
				
				if (coordinatesY > (2 * n_rows - 1)) {
					coordinatesY = 1;
					gotoxy(coordinatesX, coordinatesY);
					x = 0;
				}
			}
			if (key == KEY_LEFT) {
				coordinatesX -= 4;
				gotoxy(coordinatesX, coordinatesY);
				y--;
				
				if (coordinatesX <= 1) {
					coordinatesX = (4 * n_cols - 1);
					gotoxy(coordinatesX, coordinatesY);
					y = n_cols - 1;
				}
			}
			if (key == KEY_RIGHT) {
				coordinatesX += 4;
				gotoxy(coordinatesX, coordinatesY);
				y++;
				
				if (coordinatesX > (4 * n_cols - 1)) {
					coordinatesX = 3;
					gotoxy(coordinatesX, coordinatesY);
					y = 0;
				}
			}
			if (key == REFRESH) {
				countRefresh --;
				if (countRefresh >= 0) {
					swapAlphabets(n_rows, n_cols, pokemons);
					printRefresh(countRefresh);
					gotoxy(0, 0);
					printGirdOfPokemons(pokemons, n_rows);
				}
				gotoxy(coordinatesX, coordinatesY);
			}
			if (key == SPACE) {
				selectedX = x; 	
				selectedY = y;

				_CheckFirst = true;
				gotoxy(50, 5);
				cout << "First Choice: " << pokemons[selectedX][selectedY];
				gotoxy(coordinatesX, coordinatesY);
			}
			if (key == ENTER) {
				if (_CheckFirst) {
					_CheckFirst = false;
					_x = x;
					_y = y;
					
					gotoxy(80, 5);
					cout << "Second Choice: " << pokemons[_x][_y];
					gotoxy(coordinatesX, coordinatesY);
					
					if (selectPokemon(selectedX, selectedY) && pokemons[selectedX][selectedY] != '0' && pokemons[_x][_y] != '0') {
						PlaySound(TEXT("songs\\correct.wav"), NULL, SND_FILENAME | SND_ASYNC);
						Player.scores += 10;
						removePokemon(selectedX, selectedY, pokemons);
						removePokemon(_x, _y, pokemons);

						if (checkEmptyBoard(pokemons))
							_checkEmptyBoard = true;
						
						if (recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2))
							printRecommendedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
						
						if (!recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2) && _checkEmptyBoard == false) {
							swapAlphabets(n_rows, n_cols, pokemons);
							recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
							printRecommendedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
							gotoxy(coordinatesX, coordinatesY);
						}
						// ===============================	
						gotoxy(0, 0);
						printBackGround(bg, n_rows, n_cols);
						// ============ random mau cho bang ==================   
						indexColor = rand() % (sizeof colors / sizeof *colors);
						TextColor(colors[indexColor]);
						// ====================================================
						printGirdOfPokemons(pokemons, n_rows);

						// ========== hien thi diem so =====
						showScores(Player);
						// =================================
						gotoxy(coordinatesX, coordinatesY);	// dieu chinh toa do chuot lai o moi vua xoa
					}
					else
						PlaySound(TEXT("songs\\wrong.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
		}
	}
	if (_checkEmptyBoard) {
		freedom2DArr(pokemons);
		freedom2DArr(bg);
		Sleep(3000);
		system("cls");
		PlaySound(TEXT("songs\\goodjob.wav"), NULL, SND_FILENAME | SND_ASYNC);
		winerWinerChickenDinner(Player);
		Player.scores += 50;
		getData(Player);
	
	}
	else if (time_left <= 0) {
		freedom2DArr(pokemons);
		freedom2DArr(bg);
		system("cls");
		PlaySound(TEXT("songs\\defeat.wav"), NULL, SND_FILENAME | SND_ASYNC);
		loserloserChicken(Player);
		getData(Player);
	}
}

void EventDispatches_MEDIUM() {
	ShowConsoleCursor(true);

	int coordinatesX = 3, coordinatesY = 1;	// toa do trong console
	int selectedX, selectedY;	// index trong mang cua pokemon thu nhat
	int countHint = 7;	// đếm số lần sử dụng gợi ý
	int countRefresh = 3;	// đếm số lần refresh bảng
	char key;
	bool _CheckFirst = false;	// kiem tra xem co chon pokemon thu nhat hay chua
	bool _checkEmptyBoard = false;	// kiem tra xem mang co bi an het hay chua

	// ----- CAC BIEN TINH THOI GIAN -----
	int time_left = 210;		// THOI GIAN CON LAI DANH CHO NGUOI CHOI
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int prev_time = ltm->tm_sec;	// THOI GIAN KHI BAT DAU GAME
	int minutes = time_left / 60;
    int seconds = time_left % 60;

	// ----- Recommended Moves -----
	int recommended_X1, recommended_X2, recommended_Y1, recommended_Y2;

	// ===== INIT PLAYER INFO =====
	Info Player;
	initPlayer(Player);
	findPlayerName(Player);
	system("cls");
	
	// ========== BACKGROUND ==========
	int n = 16, m = 32;

	char** bg = new char*[n];
	for (int i = 0; i < n; i++) {
		bg[i] = new char[m];
	}

	getBackground_MEDIUM(bg);

	// ===== INIT BOARD =====

	gotoxy(0, 0);
	
	input2DArr(pokemons);
	
   	Board(n_rows, n_cols, n_types, countAlphabets, pokemons);
	
    printGirdOfPokemons(pokemons, n_rows);

    // =======================
	
	// ===== ten cua nguoi choi =====
	gotoxy(80, 0);
	cout << "Hello ";
	TextColor(12);
	cout << Player.name;
	TextColor(7);
	cout << " dep zai";
	//===============================

	// ===== THOI GIAN =====
	gotoxy(120, 0);
	cout << setfill('0') << setw(2) << minutes << " : " << setfill('0') << setw(2) << seconds;
	// =====================
	
	printHint(countHint);
	printRefresh(countRefresh);

	// ===== diem cua nguoi choi =====
	showScores(Player);
	gotoxy(coordinatesX, coordinatesY);
	// ===============================
	
	// ===== dung de random mau =====
	static int colors[] = {1, 2, 3, 4, 5, 6, 9, 10, 11, 12};
	int indexColor;
	//===============================

	while(true && !_checkEmptyBoard  && time_left > 0) {

		// ----- THOI GIAN -----
		showTime(time_left);
		calTime(prev_time, time_left);
		gotoxy(coordinatesX, coordinatesY);
		// ---------------------
		
		if (kbhit()) {
			key = getch();
			if (key == KEY_UP) {
				coordinatesY -= 2;
				gotoxy(coordinatesX, coordinatesY);
				x --;
					
				if (coordinatesY < 0) {
					coordinatesY = (2 * n_rows - 1);
					gotoxy(coordinatesX, coordinatesY);
					x = n_rows - 1;
				}
			}
			if (key == KEY_DOWN) {
				coordinatesY += 2;
				gotoxy(coordinatesX, coordinatesY);
				x++;
				
				if (coordinatesY > (2 * n_rows - 1)) {
					coordinatesY = 1;
					gotoxy(coordinatesX, coordinatesY);
					x = 0;
				}
			}
			if (key == KEY_LEFT) {
				coordinatesX -= 4;
				gotoxy(coordinatesX, coordinatesY);
				y--;
				
				if (coordinatesX <= 1) {
					coordinatesX = (4 * n_cols - 1);
					gotoxy(coordinatesX, coordinatesY);
					y = n_cols - 1;
				}
			}
			if (key == KEY_RIGHT) {
				coordinatesX += 4;
				gotoxy(coordinatesX, coordinatesY);
				y++;
				
				if (coordinatesX > (4 * n_cols - 1)) {
					coordinatesX = 3;
					gotoxy(coordinatesX, coordinatesY);
					y = 0;
				}
			}
			if (key == HINT) {
				countHint --;
				if (countHint >= 0) {
					recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
					printRecommendedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
					printHint(countHint);
				}
				gotoxy(coordinatesX, coordinatesY);
			}
			if (key == REFRESH) {
				countRefresh --;
				if (countRefresh >= 0) {
					swapAlphabets(n_rows, n_cols, pokemons);
					printRefresh(countRefresh);
					gotoxy(0, 0);
					printGirdOfPokemons(pokemons, n_rows);
				}
				gotoxy(coordinatesX, coordinatesY);
			}
			if (key == SPACE) {
				selectedX = x; 	
				selectedY = y;
				_CheckFirst = true;
				gotoxy(50, 5);
				cout << "First Choice: " << pokemons[selectedX][selectedY];
				gotoxy(coordinatesX, coordinatesY);
			}
			if (key == ENTER) {
				if (_CheckFirst) {
					_CheckFirst = false;
					_x = x;
					_y = y;
					
					gotoxy(80, 5);
					cout << "Second Choice: " << pokemons[_x][_y];
					gotoxy(coordinatesX, coordinatesY);
					
					if (selectPokemon(selectedX, selectedY) && pokemons[selectedX][selectedY] != '0' && pokemons[_x][_y] != '0') {
						PlaySound(TEXT("songs\\correct.wav"), NULL, SND_FILENAME | SND_ASYNC);

						Player.scores += 10;
						removePokemon(selectedX, selectedY, pokemons);
						removePokemon(_x, _y, pokemons);

						if (checkEmptyBoard(pokemons))
							_checkEmptyBoard = true;

						pushToRight(selectedX, selectedY, _x, _y, n_rows, n_cols, pokemons);

						if (!recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2) && _checkEmptyBoard == false) {
							swapAlphabets(n_rows, n_cols, pokemons);
							recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
							printRecommendedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
							gotoxy(coordinatesX, coordinatesY);
						}
						
						// ================================	
						gotoxy(0, 0);
						printBackGround(bg, n_rows, n_cols);

						// ============ random mau cho bang ==================   
						indexColor = rand() % (sizeof colors / sizeof *colors);
						TextColor(colors[indexColor]);
						// ====================================================
						printGirdOfPokemons(pokemons, n_rows);

						// ========== hien thi diem so =====
						showScores(Player);
						// =================================
						gotoxy(coordinatesX, coordinatesY);	// dieu chinh toa do chuot lai o moi vua xoa
					}
					else 
						PlaySound(TEXT("songs\\wrong.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
		}
	}

	if (_checkEmptyBoard) {
		freedom2DArr(pokemons);
		freedom2DArr(bg);
		Sleep(3000);
		system("cls");
		PlaySound(TEXT("songs\\goobjob.wav"), NULL, SND_FILENAME | SND_ASYNC);
		winerWinerChickenDinner(Player);
		Player.scores += (2 * countHint + 1) * (3 * countRefresh);
		getData(Player);
	
	}
	else if (time_left <= 0) {
		freedom2DArr(pokemons);
		freedom2DArr(bg);
		system("cls");
		PlaySound(TEXT("songs\\defeat.wav"), NULL, SND_FILENAME | SND_ASYNC);
		loserloserChicken(Player);
		getData(Player);
	}
}

void EventDispatches_HARD() {
	ShowConsoleCursor(true);

	int coordinatesX = 3, coordinatesY = 1;	// toa do trong console
	int selectedX, selectedY;	// index trong mang cua pokemon thu nhat
	int countHint = 7;	// đếm số lần sử dụng gợi ý
	int countRefresh = 2;	// đếm số lần refresh bảng
	int checkScores = 0;	// KIỂM TRA ĐIỂM ĐỂ SWAP BẢNG TĂNG ĐỘ KHÓ
	char key;
	bool _CheckFirst = false;	// kiem tra xem co chon pokemon thu nhat hay chua
	bool _checkEmptyBoard = false;	// kiem tra xem mang co bi an het hay chua

	// ----- CAC BIEN TINH THOI GIAN -----
	int time_left = 300;		// THOI GIAN CON LAI DANH CHO NGUOI CHOI
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int prev_time = ltm->tm_sec;	// THOI GIAN KHI BAT DAU GAME
	int minutes = time_left / 60;
    int seconds = time_left % 60;

	// ----- Recommended Moves -----
	int recommended_X1, recommended_X2, recommended_Y1, recommended_Y2;

	// ===== INIT PLAYER INFO =====
	Info Player;
	initPlayer(Player);
	findPlayerName(Player);
	system("cls");
	
	// ========== BACKGROUND ==========
	int n = 20, m = 41;

	char** bg = new char*[n];
	for (int i = 0; i < n; i++) {
		bg[i] = new char[m];
	}

	getBackground_HARD(bg);

	// ===== INIT BOARD =====

	HARD_LEVEL(n_rows, n_cols, n_types, countAlphabets);

	gotoxy(0, 0);
	
	input2DArr(pokemons);
	
   	Board(n_rows, n_cols, n_types, countAlphabets, pokemons);
	
    printGirdOfPokemons(pokemons, n_rows);

    // =======================
	
	// ===== ten cua nguoi choi =====
	gotoxy(80, 0);
	cout << "Hello ";
	TextColor(12);
	cout << Player.name;
	TextColor(7);
	cout << " dep zai";
	//===============================

	// ===== THOI GIAN =====
	gotoxy(120, 0);
	cout << setfill('0') << setw(2) << minutes << " : " << setfill('0') << setw(2) << seconds;
	// =====================
	
	printHint(countHint);
	printRefresh(countRefresh);

	// ===== diem cua nguoi choi =====
	showScores(Player);
	gotoxy(coordinatesX, coordinatesY);
	// ===============================
	
	// ===== dung de random mau =====
	static int colors[] = {1, 2, 3, 4, 5, 6, 9, 10, 11, 12};
	int indexColor;
	//===============================

	while(true && !_checkEmptyBoard && time_left > 0) {

		// ----- THOI GIAN -----
		showTime(time_left);
		calTime(prev_time, time_left);
		gotoxy(coordinatesX, coordinatesY);
		// ---------------------

		if(kbhit()) {
			key = getch();
			if (key == KEY_UP) {
				coordinatesY -= 2;
				gotoxy(coordinatesX, coordinatesY);
				x --;
					
				if (coordinatesY < 0) {
					coordinatesY = (2 * n_rows - 1);
					gotoxy(coordinatesX, coordinatesY);
					x = n_rows - 1;
				}
			}
			if (key == KEY_DOWN) {
				coordinatesY += 2;
				gotoxy(coordinatesX, coordinatesY);
				x++;
				
				if (coordinatesY > (2 * n_rows - 1)) {
					coordinatesY = 1;
					gotoxy(coordinatesX, coordinatesY);
					x = 0;
				}
			}
			if (key == KEY_LEFT) {
				coordinatesX -= 4;
				gotoxy(coordinatesX, coordinatesY);
				y--;
				
				if (coordinatesX <= 1) {
					coordinatesX = (4 * n_cols - 1);
					gotoxy(coordinatesX, coordinatesY);
					y = n_cols - 1;
				}
			}
			if (key == KEY_RIGHT) {
				coordinatesX += 4;
				gotoxy(coordinatesX, coordinatesY);
				y++;
				
				if (coordinatesX > (4 * n_cols - 1)) {
					coordinatesX = 3;
					gotoxy(coordinatesX, coordinatesY);
					y = 0;
				}
			}
			if (key == HINT) {
				countHint --;
				if (countHint >= 0) {
					recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
					printRecommendedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
					printHint(countHint);
				}
				gotoxy(coordinatesX, coordinatesY);
			}
			if (key == REFRESH) {
				countRefresh --;
				if (countRefresh >= 0) {
					swapAlphabets(n_rows, n_cols, pokemons);
					printRefresh(countRefresh);
					gotoxy(0, 0);
					printGirdOfPokemons(pokemons, n_rows);
				}
				gotoxy(coordinatesX, coordinatesY);
			}
			if (key == SPACE) {
				selectedX = x; 	
				selectedY = y;
				_CheckFirst = true;
				gotoxy(50, 5);
				cout << "First Choice: " << pokemons[selectedX][selectedY];
				gotoxy(coordinatesX, coordinatesY);
			}
			if (key == ENTER) {
				if (_CheckFirst) {
					_CheckFirst = false;
					_x = x;
					_y = y;
					
					gotoxy(80, 5);
					cout << "Second Choice: " << pokemons[_x][_y];
					gotoxy(coordinatesX, coordinatesY);
					
					if (selectPokemon(selectedX, selectedY) && pokemons[selectedX][selectedY] != '0' && pokemons[_x][_y] != '0') {
						PlaySound(TEXT("songs\\correct.wav"), NULL, SND_FILENAME | SND_ASYNC);

						Player.scores += 10;
						checkScores += 10;
						removePokemon(selectedX, selectedY, pokemons);
						removePokemon(_x, _y, pokemons);

						if (checkEmptyBoard(pokemons))
							_checkEmptyBoard = true;

						pushToLeft(selectedX, selectedY, _x, _y, n_rows, n_cols, pokemons);

						if (checkScores == 50) {
							checkScores = 0;
							swapAlphabets(n_rows, n_cols, pokemons);
						}

						if (!recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2) && _checkEmptyBoard == false) {
							swapAlphabets(n_rows, n_cols, pokemons);
							recommenedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
							printRecommendedMove(pokemons, recommended_X1, recommended_X2, recommended_Y1, recommended_Y2);
							gotoxy(coordinatesX, coordinatesY);
						}
						
						// ================================	
						gotoxy(0, 0);
						printBackGround(bg, n_rows, n_cols);

						// ============ random mau cho bang ==================   
						indexColor = rand() % (sizeof colors / sizeof *colors);
						TextColor(colors[indexColor]);
						// ====================================================
						printGirdOfPokemons(pokemons, n_rows);

						// ========== hien thi diem so =====
						showScores(Player);
						// =================================
						gotoxy(coordinatesX, coordinatesY);	// dieu chinh toa do chuot lai o moi vua xoa
					}
					else
						PlaySound(TEXT("songs\\wrong.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
		}
	}
	if (_checkEmptyBoard) {
		freedom2DArr(pokemons);
		freedom2DArr(bg);
		Sleep(3000);
		system("cls");
		PlaySound(TEXT("songs\\goodjob.wav"), NULL, SND_FILENAME | SND_ASYNC);
		winerWinerChickenDinner(Player);
		Player.scores += (3 * countHint + 1) * (5 * countRefresh);
		getData(Player);
	
	}
	else if (time_left <= 0) {
		freedom2DArr(pokemons);
		freedom2DArr(bg);
		system("cls");
		PlaySound(TEXT("songs\\defeat.wav"), NULL, SND_FILENAME | SND_ASYNC);
		loserloserChicken(Player);
		getData(Player);
	}
}
