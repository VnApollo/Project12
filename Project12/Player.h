#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player {

private:
	string name;
	char sym;
	int wins, losses, draws;
public:
    Player();
    Player(string name, char sym); 
    Player(string name, char sym, int wins, int losses, int draws);

    void setName(string name);
    void setSymbol(char symbol);
    void setWins(int wins);
    void setLosses(int losses);
    void setDraws(int draws);


    string getName();
    char symbol();
    int getWins();
    int getLosses();
    int getDraws();
    
    void incrementWins();
    void incrementLosses();
    void incrementDraws();
};

#endif // !PLAYER_H
