#pragma once
#include"board.h"
#include<vector>
using namespace std;
using namespace sf;
class ludo
{
	board* brd;
	int reachedHome;
	int nOP;
	sf::Vector2f sc;
	sf::Vector2f dc;
	int moves;
	int currentPlayer;
	
public:
	ludo();
	void play();
	void selectSc(sf::RenderWindow& window);
	void selectDc(sf::RenderWindow& window);
	void roll();
	bool isValidSc();
	bool killCheck(sf::Vector2f cP);
	bool checkWin(int i);
	bool isGameOver();
	void turnChange();


	
};

