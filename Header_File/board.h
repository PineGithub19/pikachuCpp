#pragma once
#include "mylib.h"

// thêm pokemon thuộc loại type vào ô ở hàng x cột y
void addPokemon(int x, int y, char type, char** pokemons);

// trả về loại pokemon ở ô hàng x cột y
char getPokemon(int x, int y, char** pokemons);

// xóa pokemon ở ô hàng x cột y (gán loại pokemon ở ô này = x). 
void removePokemon(int x, int y, char** pokemons);

void Board(int n_rows, int n_cols, int n_types, vector<int> countAlphabets, char** pokemons);

void input2DArr(char** pokemons);

void freedom2DArr(char** pokemons);

void printGirdOfPokemons(char**c, int n);

bool checkEmptyBoard(char** pokemons);

