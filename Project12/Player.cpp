#include "Player.h"

Player::Player()
{
	name = "";
	sym = ' ';
	wins = 0;
	losses = 0;
	draws = 0;
}

Player::Player(string name, char symbol)
{
	this->name = name;
	this->sym = symbol;
	wins = 0;
	losses = 0;
	draws = 0;
}

Player::Player(string name, char sym, int wins, int losses, int draws)
{
	this->name = name;
	this->sym = sym;
	this->wins = wins;
	this->losses = losses;
	this->draws = draws;
}

void Player::setName(string name)
{
	this->name = name;
}

void Player::setSymbol(char symbol)
{
	this->sym = symbol;
}

void Player::setWins(int wins)
{
	this->wins = wins;
}

void Player::setLosses(int losses)
{
	this->losses = losses;
}

void Player::setDraws(int draws)
{
	this->draws = draws;
}

string Player::getName()
{
	return string();
}

char Player::symbol()
{
	return sym;
}

int Player::getWins()
{
	return wins;
}

int Player::getLosses()
{
	return losses;
}

int Player::getDraws()
{
	return draws;
}

void Player::incrementWins()
{
	wins++;
}

void Player::incrementLosses()
{
	losses++;
}

void Player::incrementDraws()
{
	draws++;
}
