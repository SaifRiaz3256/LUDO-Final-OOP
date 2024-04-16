#pragma once
#include <SFML/Graphics.hpp>
#include"player.h"
#include"piece.h"
#include<vector>
#include"utility.h"

using namespace std;
class board
{
public:
	board();
	board(int n);
	vector<player> pls;
	int noOfPlayers;
	
	//int boardSize;
	//int playerSize;

	void drawSquare(sf::RenderWindow& window, sf::Vector2f position, sf::Color color,float t= 1.f);
	void printBoard(sf::RenderWindow& window);



};

