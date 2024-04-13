#include "Result.h"

void Result::saveGameResult(string& fileName, string& playerName, int wins, int losses, int draws)
{
    std::ofstream file(fileName); // Mở tệp để ghi
    if (file.is_open()) {
        // Ghi thông tin của người chơi vào tệp
        file << "[" << playerName << "]" << std::endl;
        file << "Wins=" << wins << std::endl;
        file << "Losses=" << losses << std::endl;
        file << "Draws=" << draws << std::endl;

        // Đóng tệp
        file.close();
        cout << "Game result has been saved to " << fileName << std::endl;
    }
    else {
        cerr << "Failed to open file for writing." << std::endl;
    }

    //    saveGameResult(fileName, playerName, wins, losses, draws);
    // lưu kết quả trò chơi vào tệp .ini
}
    