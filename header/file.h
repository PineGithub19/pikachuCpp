#pragma once
#include "mylib.h"

//  https://sinhvientot.net/lam-viec-voi-tap-tin-nhi-phan-trong-c/
//  https://www.tutorialspoint.com/reading-and-writing-binary-file-in-c-cplusplus#

void getData(Info Player) {

    ofstream file;
    file.open("players.dat", ios::app | ios::binary);

    if (!file.is_open()) {
        cout << "NO";
        return;
    }

    else {
        file.write((char *) &Player, sizeof(Info));
    }
    file.close();
}

void showPlayersLeaderBoard() {
    ifstream ifs;
    ifs.open("players.dat", ios::binary);

    if (!ifs.is_open()) {
        cout << "NO";
        return;
    }

    ifs.seekg(0, ios::end);
    int num = ifs.tellg() / sizeof(Info);
    ifs.seekg(0, ios::beg);

    Info* _Players = new Info[num];

    int x_playerLB = 40, y_playerLB = 15;
    vector<Info> sortPlayers;

    for (int i = 0; i < num; i++) {
        ifs.read((char *) &_Players[i], sizeof(Info));
        sortPlayers.push_back(_Players[i]);
    }
        
    for (int i = 0; i < sortPlayers.size() - 1; i++)
        for (int j = i + 1; j < sortPlayers.size(); j++)
            if (sortPlayers[i].scores < sortPlayers[j].scores)
                swap(sortPlayers[i], sortPlayers[j]);

    for (int i = 0; i < sortPlayers.size() - 1; i++) {
        for (int j = i + 1; j < sortPlayers.size(); j++) {
            if (strcmp(sortPlayers[i].name, sortPlayers[j].name) == 0) {
                if (sortPlayers[i].scores >= sortPlayers[j].scores) {
                    sortPlayers.erase(sortPlayers.begin() + j);
                }
            }
        }
    }

    for (int i = 0; i < sortPlayers.size(); i++) {
        gotoxy(x_playerLB, y_playerLB);
        TextColor(12);
        if (i <= 4)
            TextColor(5);
        cout << setfill(' ') << setw(20) << sortPlayers[i].name << setfill('.') << setw(50) << sortPlayers[i].scores << " Scores";
        y_playerLB += 2;     
    }

    delete[] _Players;
    ifs.close();
}

void findPlayerName(Info &Player) {
    ifstream ifs;
    ifs.open("players.dat", ios::binary);

    if (!ifs.is_open()) {
        cout << "NO";
        return;
    }

    ifs.seekg(0, ios::end);
    int num = ifs.tellg() / sizeof(Info);
    ifs.seekg(0, ios::beg);

    Info* _Players = new Info[num];


    vector<Info> filterPlayers;

    for (int i = 0; i < num; i++) {
        ifs.read((char *) &_Players[i], sizeof(Info));
        filterPlayers.push_back(_Players[i]);
    }
    
    if (filterPlayers.size() <= 1) {
            for (int i = 0; i < num; i++) {
            ifs.read((char *) &_Players[i], sizeof(Info));
            if (strcmp(Player.name,_Players[i].name) == 0) {
                Player.scores = _Players[i].scores;
                break;
            }
        }
    }

    else {
        for (int i = 0; i < filterPlayers.size() - 1; i++)
        for (int j = i + 1; j < filterPlayers.size(); j++)
            if (filterPlayers[i].scores < filterPlayers[j].scores)
                swap(filterPlayers[i], filterPlayers[j]);

        for (int i = 0; i < filterPlayers.size() - 1; i++) {
            for (int j = i + 1; j < filterPlayers.size(); j++) {
                if (strcmp(filterPlayers[i].name, filterPlayers[j].name) == 0) {
                    if (filterPlayers[i].scores >= filterPlayers[j].scores) {
                        filterPlayers.erase(filterPlayers.begin() + j);
                    }
                }
            }
        }

        for (int i = 0; i < num; i++) {
            if (strcmp(Player.name,filterPlayers[i].name) == 0) {
                Player.scores = filterPlayers[i].scores;
                break;
            }
        }
    }

    delete[] _Players;
    ifs.close();
}
