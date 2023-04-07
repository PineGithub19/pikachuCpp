#pragma once
#include "mylib.h"
#include "file.h"

void printMenuFrame(string menuFrame[], int x_menu, int y_menu) {
	for (int i = 0; i < 5; i++) {
		gotoxy(x_menu, y_menu);
		cout << menuFrame[i] << endl;
		y_menu++;
	}
}

void howToPlay() {
	system("cls");
	
	ShowConsoleCursor(false);
	
	TextColor(5);
	gotoxy(30, 0);
	cout << " _   _ _____  _    _   _____ _____  ______ _       _____   __  ___  ";
	gotoxy(30, 1);
	cout << "| | | |  _  || |  | | |_   _|  _  | | ___ \\ |     / _ \\ \\ / / |__ \\ ";
	gotoxy(30, 2);
	cout << "| |_| | | | || |  | |   | | | | | | | |_/ / |    / /_\\ \\ V /     ) |";
	gotoxy(30, 3);
	cout << "|  _  | | | || |/\\| |   | | | | | | |  __/| |    |  _  |\\ /     / / ";
	gotoxy(30, 4);
	cout << "| | | \\ \\_/ /\\  /\\  /   | | \\ \\_/ / | |   | |____| | | || |    |_|  ";
	gotoxy(30, 5);
	cout << "\\_| |_/\\___/  \\/  \\/    \\_/  \\___/  \\_|   \\_____/\\_| |_/\\_/    (_)  ";
	
	TextColor(6);
	gotoxy(20, 9);
	cout << "Press 'SPACE' to choose the FIRST Pokemon.";
	gotoxy(20, 10);
	cout << "Press 'ENTER' to choose the SECOND Pokemon.";
	gotoxy(20, 11);
	cout << "Press '!' TO USE 1 HINT. Press 'R' TO REFRESH THE BOARD.";
	gotoxy(20, 12);
	cout << "If you don't have any valid moves left. The board will be swaped and you will be recomended for your next choice.";
	gotoxy(20, 13);
	cout << "If you clear the board and your time is greater than 0, you will WIN. Otherwise, you will LOSE !";
	gotoxy(20, 14);
	cout << "Good Luck !";
}

void credits() {
	ShowConsoleCursor(false);

	system("cls");
	TextColor(9);
	gotoxy(30, 0);
	cout << "   _,.----.                  ,----.               .=-.-.,--.--------.   ,-,--.  ";
	gotoxy(30, 1);
	cout << " .' .' -   \\  .-.,.---.   ,-.--` , \\  _,..---._  /==/_ /==/,  -   , -\\,-.'-  _\\ ";
	gotoxy(30, 2);
	cout << "/==/  ,  ,-' /==/  `   \\ |==|-  _.-`/==/,   -  \\|==|, |\\==\\.-.  - ,-./==/_ ,_.' ";
	gotoxy(30, 3);
	cout << "|==|-   |  .|==|-, .=., ||==|   `.-.|==|   _   _\\==|  | `--`\\==\\- \\  \\==\\  \\    ";
	gotoxy(30, 4);
	cout << "|==|_   `-' \\==|   '='  /==/_ ,    /|==|  .=.   |==|- |      \\==\\_ \\  \\==\\ -\\   ";
	gotoxy(30, 5);
	cout << "|==|   _  , |==|- ,   .'|==|    .-' |==|,|   | -|==| ,|      |==|- |  _\\==\\ ,\\  ";
	gotoxy(30, 6);
	cout << "\\==\\.       /==|_  . ,'.|==|_  ,`-._|==|  '='   /==|- |      |==|, | /==/\\/ _ | ";
	gotoxy(30, 7);
	cout << " `-.`.___.-'/==/  /\\ ,  )==/ ,     /|==|-,   _`//==/. /      /==/ -/ \\==\\ - , / ";
	gotoxy(30, 8);
	cout << "            `--`-`--`--'`--`-----`` `-.`.____.' `--`-`       `--`--`  `--`---'  ";
	
	TextColor(7);
	gotoxy(60, 10);
	cout << "DEVELOPERS";
	gotoxy(30, 12);
	cout << "22127441";
	cout << setfill('.') << setw(70) << "Thai Huyen Tung_22clc10";
	gotoxy(30, 14);
	cout << "19127424";
	cout << setfill('.') << setw(70) << "Trieu Nguyen Minh Huy_22clc10";
	
	gotoxy(58, 17);
	cout << "OTHER SUPPORTS";

	gotoxy(30, 19);
	cout << "22127388";
	cout << setfill('.') << setw(70) << "To Quoc Thanh_22clc10";

	gotoxy(30, 21);
	cout << "22127322";
	cout << setfill('.') << setw(70) << "Le Phuoc Phat_22clc10";

	gotoxy(30, 23);
	cout << "22127132";
	cout << setfill('.') << setw(70) << "Ly Nghi Hoang_22clc02";

	gotoxy(30, 25);
	cout << "Teacher";
	cout << setfill('.') << setw(70) << "Nguyen Thanh Phuong";

	gotoxy(30, 27);
	cout << "Teacher";
	cout << setfill('.') << setw(70) << "Nguyen Ngoc Thao";

	gotoxy(30, 29);
	cout << "Teacher";
	cout << setfill('.') << setw(70) << "Bui Huy Thong";

	gotoxy(30, 31);
	cout << "BFS Algorithm";
	cout << setfill('.') << setw(70) << "codelearn.io";

	gotoxy(30, 33);
	cout << "Other References";
	cout << setfill('.') << setw(70) << "stackoverflow.com";
	
	gotoxy(64, 35);
	cout << "MUSIC";
	
	gotoxy(30, 37);
	cout << "Link to MP3";
	cout << setfill('.') << setw(70) << "y2mate.com";
	
	gotoxy(30, 39);
	cout << "MP3 to WAV";
	cout << setfill('.') << setw(70) << "convertio.com";
	
	gotoxy(30, 41);
	cout<< "Bacground Music";
	cout << setfill('.') << setw(70) << "Stream den bao gio - Do Mixi";
	
	gotoxy(30, 43);
	cout << "Victory Music";
	cout << setfill('.') << setw(70) << "Good Job sound effect";
	
	gotoxy(30, 45);
	cout<< "Defeat Music";
	cout << setfill('.') << setw(70) << "Defeat - Clash Of Clan";
	
	gotoxy(30, 47);
	cout << "Matching Music";
	cout << setfill('.') << setw(70) << "Correct Answer - Wrong Buzzer";
}

void leaderboard() {
	ShowConsoleCursor(false);
	system("cls");
	TextColor(12);
	gotoxy(30, 0);
	cout << "             ('-.   ('-.     _ .-') _     ('-.  _  .-') .-. .-')                  ('-.     _  .-')  _ .-') _   ";
	gotoxy(30, 1);
	cout << "           _(  OO) ( OO ).-.( (  OO) )  _(  OO)( \\( -O )\\  ( OO )                ( OO ).-.( \\( -O )( (  OO) )  ";
	gotoxy(30, 2);
	cout << " ,--.     (,------./ . --. / \\     .'_ (,------.,------. ;-----.\\  .-'),-----.   / . --. / ,------. \\     .'_  ";
	gotoxy(30, 3);
	cout << " |  |.-')  |  .---'| \\-.  \\  ,`'--..._) |  .---'|   /`. '| .-.  | ( OO'  .-.  '  | \\-.  \\  |   /`. ',`'--..._) ";
	gotoxy(30, 4);
	cout << " |  | OO ) |  |  .-'-'  |  | |  |  \\  ' |  |    |  /  | || '-' /_)/   |  | |  |.-'-'  |  | |  /  | ||  |  \\  ' ";
	gotoxy(30, 5);
	cout << " |  |`-' |(|  '--.\\| |_.'  | |  |   ' |(|  '--. |  |_.' || .-. `. \\_) |  |\\|  | \\| |_.'  | |  |_.' ||  |   ' | ";
	gotoxy(30, 6);
	cout << "(|  '---.' |  .--' |  .-.  | |  |   / : |  .--' |  .  '.'| |  \\  |  \\ |  | |  |  |  .-.  | |  .  '.'|  |   / : ";
	gotoxy(30, 7);
	cout << " |      |  |  `---.|  | |  | |  '--'  / |  `---.|  |\\  \\ | '--'  /   `'  '-'  '  |  | |  | |  |\\  \\ |  '--'  / ";
	gotoxy(30, 8);
	cout << " `------'  `------'`--' `--' `-------'  `------'`--' '--'`------'      `-----'   `--' `--' `--' '--'`-------'  ";
	
	showPlayersLeaderBoard();
}

int MainMenu() {

	int choice[5] = {1, 2, 3, 4, 5};
	
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
    
    TextColor(11);
    printMenuFrame(menuFrame, 55, 12);
    gotoxy(64, 14);
    cout << "PLAY";
    
    TextColor(5);
    printMenuFrame(menuFrame, 55, 20);
    gotoxy(63, 22);
    cout << "CREDIT";

	TextColor(10);
    printMenuFrame(menuFrame, 55, 28);
    gotoxy(60, 30);
    cout << "LEADER BOARD";

	TextColor(4);
    printMenuFrame(menuFrame, 55, 36);
    gotoxy(64, 38);
    cout << "EXIT";

	TextColor(6);
    printMenuFrame(menuFrame, 90, 24);
    gotoxy(95, 26);
    cout << "HOW TO PLAY ?";
    
	TextColor(2);
	gotoxy(90, 12);
	cout << "Press 'P' to choose PLAY LEVELS";
	gotoxy(90, 14);
	cout << "Press 'C' to choose CREDITS"; 
	gotoxy(90, 16);
	cout << "Press 'L' to choose LEADER BOARD";
	gotoxy(90, 18);
	cout << "Press 'ESC' to EXIT";
	gotoxy(90, 20);
	cout << "Press '?' to choose HOW TO PLAY";

	TextColor(12);
	gotoxy(90, 22);
	cout << "Please, don't press key in the MENU when your CAPSLOCK is on. Thanks !";
	
	TextColor(7);
    
    char key_choice = 0;
	
	switch(key_choice = getch()) {
    	case PLAY:
    		return choice[0];
    	break;
    	case CREDITS:
    		return choice[1];
    	break;
		case LEADERBOARD:
			return choice[2];
		break;
		case HOWTOPLAY:
			return choice[3];
		break;
		case ESC:
			return choice[4];
		break;
	}
}
