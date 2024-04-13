#pragma once
#ifndef RESULT_H
#define	RESULT_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Result
{
public:
	void saveGameResult(string& fileName, string& playerName, int wins, int losses, int drawer);
};
#endif // !RESULT_H
