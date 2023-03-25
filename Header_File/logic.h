#pragma once
#include "mylib.h"

vector<pair<int, int>> findPath(int _x, int _y, int x, int y);

//	Kiem tra xem co duong noi giua 2 cap pokemon hay khong (khong qua 3 doan)
bool canConnect(int _x, int _y, int x, int y);

// Kiem tra xem cap pokemon x, y co hop le voi cap pokemon _x, _y hay khong
bool selectPokemon(int x, int y);


