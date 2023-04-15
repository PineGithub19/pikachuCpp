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
	
	SetConsoleOutputCP(65001);
	
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
	
	TextColor(9);
	gotoxy(15, 8);
	cout << "   _.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._";
	gotoxy(15, 9);
	cout << ".-'---      - ---     --     ---   -----   - --       ----  ----   -     ---`-.";
	gotoxy(15, 10);
	cout << " )                                                                           (";
	gotoxy(15, 11);
	cout << "(                                                                             )";
	gotoxy(15, 12);
	cout << " )                                                                           (";
	gotoxy(15, 13);
	cout << "(                                                                             )";
	gotoxy(15, 14);
	cout << " )                                                                           (";
	gotoxy(15, 15);
	cout << "(                                                                             )";
	gotoxy(15, 16);
	cout << " )                                                                           (";
	gotoxy(15, 17);
	cout << "(                                                                             )";
	gotoxy(15, 18);
	cout << " )                                                                           (";
	gotoxy(15, 19);
	cout << "(                                                                             )";
	gotoxy(15, 20);
	cout << " )                                                                           (";
	gotoxy(15, 21);
	cout << "(                                                                             )";
	gotoxy(15, 22);
	cout << " )                                                                           (";
	gotoxy(15, 23);
	cout << "(___       _       _       _       _       _       _       _       _       ___)";
	gotoxy(15, 24);
	cout << "    `-._.-' (___ _) (__ _ ) (_   _) (__  _) ( __ _) (__  _) (__ _ ) `-._.-'";
	gotoxy(15, 25);
	cout << "            `-._.-' (  ___) ( _  _) ( _ __) (_  __) (__ __) `-._.-'";
	gotoxy(15, 26);
	cout << "                    `-._.-' (__  _) (__  _) (_ _ _) `-._.-'";
	gotoxy(15, 27);
	cout << "                            `-._.-' (_ ___) `-._.-'";
	gotoxy(15, 28);
	cout << "                                    `-._.-'";
	
	TextColor(6);
	gotoxy(20, 10);
	cout << "Press 'SPACE' to choose the FIRST Pokemon.";
	gotoxy(20, 12);
	cout << "Press 'ENTER' to choose the SECOND Pokemon.";
	TextColor(11);
	gotoxy(20, 14);
	cout << "Press '!' TO USE 1 HINT. Press 'R' TO REFRESH THE BOARD.";
	TextColor(10);
	gotoxy(20, 16);
	cout << "If you don't have any remainning valid moves.";
	gotoxy(25, 17);
	cout << "The board will be swapped.";
	gotoxy(25, 18);
	cout << "And you will be recomended for your next choice.";
	gotoxy(20, 20);
	cout << "If you clear the board and your time is greater than 0,";
	gotoxy(25, 21);
	cout << " you will WIN. Otherwise, you will LOSE !";
	TextColor(12);
	gotoxy(70, 23);
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
	ShowConsoleCursor(false);
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
	
	while(true) {
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
}
