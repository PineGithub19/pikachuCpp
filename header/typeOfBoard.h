#pragma once
#include "mylib.h"

void EASY_LEVEL(int &n_rows, int &n_cols, int &n_types, vector<int> &countAlphabets) {
    n_rows -= 2;
    n_cols -= 2;
    countAlphabets = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    n_types = countAlphabets.size();
}

void HARD_LEVEL(int &n_rows, int &n_cols, int &n_types, vector<int> &countAlphabets) {
    n_rows += 2;
    n_cols += 2;
    countAlphabets = {4, 4, 4, 4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    n_types = countAlphabets.size();
}