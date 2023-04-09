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
//
//void ASIA_LEVEL(int &n_rows, int &n_cols, int &n_types, vector<int> &countAlphabets) {
//    do {
//    	cout << "Enter the number of rows: "; 
//		cin >> n_rows;
//		cout << "Enter the number of cols: ";
//		cin >> n_cols;
//	} while (n_rows % 2 != 0 && n_cols % 2 != 0);
//	
//	int nums = n_rows * n_cols;
//	int _nums = 0;
//	
//	while (_nums < nums) {
//		int s;
//		s = (rand() % 2) * 2;
//		s += 2;
//    	countAlphabets.push_back(s);
//    	_nums += s;
//	}
//    
//    n_types = countAlphabets.size();
//}
