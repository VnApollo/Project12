#include "Controller.h"

Controller::Controller() {
    initializeBoard();
    currentPlayer = 'X'; // Người chơi 'X' đi trước
    gameOver = false; // Trò chơi chưa kết thúc
}

void Controller::initializeBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = ' ';
        }
    }
}

void Controller::displayBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Controller::endGame(Player& winner, Player& loser, Player& drawer) {
    // Hiển thị kết quả cuối cùng của trò chơi
    cout << "Game over!" << endl;

    // Cập nhật thông tin cho người chiến thắng
    winner.incrementWins();
    cout << "Winner: " << winner.getName() << endl;

    // Cập nhật thông tin cho người thua cuộc
    loser.incrementLosses();
    cout << "Loser: " << loser.getName() << endl;

    // Cập nhật thông tin cho người chơi hòa
    drawer.incrementDraws();
    cout << "Draw!" << endl;
}

bool Controller::placeMove(int row, int col) {
    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize || board[row][col] != ' ') {
        return false;
    }
    board[row][col] = currentPlayer;

    if (checkWin()) {
        gameOver = true;
        return true;
    }

    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    return true;
}

bool Controller::checkWin() {
    // Kiểm tra hàng ngang
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize - 4; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4]) {
                return true;
            }
        }
    }

    // Kiểm tra cột dọc
    for (int j = 0; j < boardSize; ++j) {
        for (int i = 0; i < boardSize - 4; ++i) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j]) {
                return true;
            }
        }
    }

    // Kiểm tra đường chéo chính
    for (int i = 0; i < boardSize - 4; ++i) {
        for (int j = 0; j < boardSize - 4; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4]) {
                return true;
            }
        }
    }

    // Kiểm tra đường chéo phụ
    for (int i = 0; i < boardSize - 4; ++i) {
        for (int j = 4; j < boardSize; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && board[i][j] == board[i + 4][j - 4]) {
                return true;
            }
        }
    }

    return false; // Không có người chiến thắng
}

bool Controller::isGameOver() {
    // Kiểm tra xem có người chiến thắng hay không
    if (checkWin()) {
        return true;
    }
    // Kiểm tra xem trò chơi kết thúc với kết quả hòa hay không
    if (checkDraw()) {
        return true;
    }
    // Trò chơi chưa kết thúc
    return false;
}

char Controller::getCurrentPlayer() {
    return currentPlayer;
}

char(*Controller::getBoard())[boardSize] {
    return board;
    }

bool Controller::checkDraw() {
    // Duyệt qua tất cả các ô trên bảng cờ
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            // Nếu có bất kỳ ô nào trống, trò chơi chưa kết thúc
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    // Nếu không còn ô trống nào trên bảng cờ, trò chơi kết thúc với kết quả hòa
    return true;
}

void Controller::playGame(Player& player1, Player& player2, Player& drawPlayer) {
    // Hiển thị bảng cờ trước khi bắt đầu trò chơi
    displayBoard();

    // Vòng lặp chính của trò chơi
    while (!isGameOver()) {
        // Lấy nước đi từ người chơi hiện tại
        int row, col;
        cout << "Player " << getCurrentPlayer() << "'s turn. Enter row and column (0-9): ";
        cin >> row >> col;

        // Kiểm tra và đặt nước đi trên bảng cờ
        if (placeMove(row, col)) {
            // Nếu đặt nước đi thành công, chuyển lượt đến người chơi tiếp theo
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else {
            // Nếu nước đi không hợp lệ, hiển thị thông báo và yêu cầu người chơi nhập lại
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Hiển thị bảng cờ sau mỗi nước đi
        displayBoard();
    }

    // Kết thúc trò chơi và hiển thị kết quả cuối cùng
    endGame(player1, player2, drawPlayer);
}
