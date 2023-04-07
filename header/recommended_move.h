#pragma once
#include "mylib.h"

bool recommenedMove(char** pokemons, int &recommended_X1, int &recommended_X2, int &recommended_Y1, int &recommended_Y2) {
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (pokemons[i][j] != '0') {
                recommended_X1 = i;
                recommended_Y1 = j;
                for (int k = i; k < n_rows; k++) {
                    for (int l = 0; l < n_cols; l++) {
                        if (pokemons[k][l] != '0') {
                            recommended_X2 = k;
                            recommended_Y2 = l;
                        }
                        if (pokemons[recommended_X1][recommended_Y1] == pokemons[recommended_X2][recommended_Y2]) {
                            if (canConnect(recommended_X2, recommended_Y2, recommended_X1, recommended_Y1)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

void printRecommendedMove(char** pokemons, int recommended_X1, int recommended_X2, int recommended_Y1, int recommended_Y2) {
    TextColor(5);
    gotoxy(50, 15);
    cout << "Recommend Next Choices:";
    gotoxy(50, 17);
    cout << "Next First Choice: " << "(" << recommended_X1 + 1 << ", " << recommended_Y1 + 1 << ") " << pokemons[recommended_X1][recommended_Y1];
    gotoxy(50, 19);
    cout << "Next Second Choice: " << "(" << recommended_X2 + 1 << ", " << recommended_Y2 + 1 << ") " << pokemons[recommended_X2][recommended_Y2];
}

void printHint(int countHint) {
    TextColor(11);
	gotoxy(50, 10);
	cout << "YOUR REMAINING HINTS: " << setfill('0') << setw(2) << countHint;	// số lần gợi ý nước đi tiếp theo
}

void printRefresh(int countRefresh) {
    TextColor(11);
    gotoxy(80, 10);
    cout << "REFRESH: " << setfill('0') << setw(2) << countRefresh;
}