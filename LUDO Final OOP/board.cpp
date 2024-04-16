#include "board.h"
//#include<SFML>
#include <SFML/Graphics.hpp>

#include"utility.h"

board::board() {
	noOfPlayers = 0;
}
board::board(int n) {
	
	noOfPlayers = n;
	
	for (int i = 0; i < n; i++)
	{
		Color color = static_cast<Color>(i);
		player p(color);
		pls.push_back(p);
		
	}

}
void board::drawSquare(sf::RenderWindow& window, sf::Vector2f position, sf::Color color,float t)
{
	sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE3, SQUARE_SIZE3));
	square.setPosition(position);
	square.setFillColor(color);
	square.setOutlineThickness(1.f);
	square.setOutlineColor(sf::Color::Black);
	window.draw(square);
}
void board::printBoard(sf::RenderWindow& window) {
	
	sf::Texture board;
	if (!board.loadFromFile("ludoo.png"))
		return;

	sf::Sprite s(board);
	s.setScale(1, 1);
	window.draw(s);
	for (int i = 0; i < pls.size(); i++)
	{
		for (int j = 0; j < pls[i].ps.size(); j++)
		{
			pls[i].ps[j].drawPiece(window);
		}
	}

	
}