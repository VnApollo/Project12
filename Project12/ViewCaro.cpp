#include "View.h"

void View::displayBoard(char board[boardSize][boardSize])
{
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << " | " << board[i][j];
		}
		cout << endl;
		cout << "----------------------------------------" << endl;
	}
}

void View::displayMasseage(string message)
{
	cout << message << endl;
}
