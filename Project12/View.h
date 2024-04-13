#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class View {
public:
	static const int boardSize = 10;
	void displayBoard(char board[boardSize][boardSize]);
	void displayMasseage(string message);

};
#endif // !VIEW_H