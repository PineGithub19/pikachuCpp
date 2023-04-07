#pragma once 
#include "mylib.h"

void pushToLeft(int selectedX, int selectedY, int _x, int _y, int n_rows, int n_cols, char** pokemons) {
    for (selectedY; selectedY < n_cols - 1; selectedY++) {
        pokemons[selectedX][selectedY] = pokemons[selectedX][selectedY + 1];
    }
    pokemons[selectedX][n_cols - 1] = '0';
    
    if (selectedX != _x) {
        for (_y; _y < n_cols - 1; _y++) {
            pokemons[_x][_y] = pokemons[_x][_y + 1];
        }
        pokemons[_x][n_cols - 1] = '0';
    }
    else {
        n_cols --;
        bool _check = true;
        for (int i = 0; i < n_cols && _check; i++) {
            if (pokemons[_x][i] == '0') {
                _check = false;
                for (int j = i; j < n_rows - 1; j++) {
                    pokemons[_x][j] = pokemons[_x][j + 1];
                }
            }
        }
        pokemons[_x][n_cols - 1] = '0'; 
    }
}

void pushToRight(int selectedX, int selectedY, int _x, int _y, int n_rows, int n_cols, char** pokemons) {
    for (_y; _y >= 1; _y--) {
        pokemons[_x][_y] = pokemons[_x][_y - 1];
    }
    pokemons[_x][0] = '0';
    
    if (_x != selectedX) {
        for (selectedY; selectedY >= 1; selectedY--) {
            pokemons[selectedX][selectedY] = pokemons[selectedX][selectedY - 1];
        }
        pokemons[selectedX][0] = '0';
    }
    else {
        bool _check = true;
        for (int i = n_cols - 1; i >= 0 && _check; i--) {
            if (pokemons[selectedX][i] == '0') {
                _check = false;
                for (int j = i; j >= 1; j--) {
                    pokemons[selectedX][j] = pokemons[selectedX][j - 1];
                }
            }
        }
        pokemons[selectedX][0] = '0'; 
    }
}