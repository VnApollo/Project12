#include "Controller.h"
#include "Player.h"

int main() {
    std::string name1, name2;
    char symbol1, symbol2;

    // Nhập thông tin cho người chơi 1
    std::cout << "Enter name for player 1: ";
    std::cin >> name1;

    // Nhập thông tin cho người chơi 2
    std::cout << "Enter name for player 2: ";
    std::cin >> name2;

    // Tạo đối tượng người chơi từ thông tin vừa nhập
    Player player1(name1, 'X');
    Player player2(name2, 'O');

    // Tạo đối tượng Controller
    Controller Controller;

    // Bắt đầu trò chơi
    void playGame(Player& player1, Player & player2, Player & drawPlayer);

    // Hiển thị thông tin về số trận thắng, thua và hòa của mỗi người chơi
    std::cout <<name1 <<" :" << player1.getWins() << " wins, " << player1.getLosses() << " losses, " << player1.getDraws() << " draws" << std::endl;
    std::cout << name2 << " :" << player2.getWins() << " wins, " << player2.getLosses() << " losses, " << player2.getDraws() << " draws" << std::endl;

    return 0;
}