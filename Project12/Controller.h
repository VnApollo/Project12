#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include "Player.h"
#include "View.h"
#include"Result.h"

using namespace std;
static const int boardSize = 10; // Kích thước của bảng cờ


class Controller {
private:
    char board[boardSize][boardSize]; // Bảng cờ
    char currentPlayer; // Người chơi hiện tại ('X' hoặc 'O')
    bool gameOver; // Biến để kiểm tra trò chơi đã kết thúc chưa

public:
    Controller();
    void initializeBoard();
    void displayBoard();
    void endGame(Player& winner, Player& loser, Player& drawer);
    bool placeMove(int row, int col);
    bool checkWin();
    bool checkDraw();
    bool isGameOver();
    char getCurrentPlayer();
    char(*getBoard())[boardSize];

    void playGame(Player& player1, Player& player2, Player& drawPlayer);

#endif // !CONTROLLER_H
};