#pragma once
#include "mylib.h"

void getBackground_ASIA(char** bg) {
    ifstream fin("picture_txt\\plane.txt");
    int dem = 0;
    string S;
    while(!fin.eof())
    {
        getline(fin,S);
        for(int i = 0; i < S.size(); i++) 
            bg[dem][i] = S[i];
        dem++;
    }
    fin.close();
}

void getBackground_HARD(char** bg) {
    ifstream fin("picture_txt\\pic1.txt");
    int dem = 0;
    string S;
    while(!fin.eof())
    {
        getline(fin,S);
        for(int i = 0; i < S.size(); i++) 
            bg[dem][i] = S[i];
        dem++;
    }
    fin.close();
}

void getBackground_MEDIUM(char** bg) {
    ifstream fin("picture_txt\\pic3.txt");
    int dem = 0;
    string S;
    while(!fin.eof())
    {
        getline(fin,S);
        for(int i = 0; i < S.size(); i++) 
            bg[dem][i] = S[i];
        dem++;
    }
    fin.close();
}

void getBackground_NORMAL(char** bg) {
    ifstream fin("picture_txt\\pika.txt");
    int dem = 0;
    string S;
    while(!fin.eof())
    {
        getline(fin,S);
        for(int i = 0; i < S.size(); i++) 
            bg[dem][i] = S[i];
        dem++;
    }
    fin.close();
}

void getBackground_EASY(char** bg) {
    ifstream fin("picture_txt\\pic2.txt");
    int dem = 0;
    string S;
    while(!fin.eof())
    {
        getline(fin,S);
        for(int i = 0; i < S.size(); i++) 
            bg[dem][i] = S[i];
        dem++;
    }
    fin.close();
}

void printBackGround(char** bg, int n_rows, int n_cols) {
	static int colors[] = {1, 2, 3, 4, 5, 6, 9, 10, 11, 12};
	int indexColor;
    for (int i = 0; i < n_rows * 2; i++) {
        for (int j = 0; j < n_cols * 4; j++) {
        	indexColor = rand() % (sizeof colors / sizeof *colors);
            TextColor(indexColor);
            cout << bg[i][j];
        }
        cout << endl;
    }
}
