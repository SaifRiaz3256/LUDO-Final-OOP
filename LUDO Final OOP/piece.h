#pragma once
#include <SFML/Graphics.hpp>

#include"utility.h"
class piece
{
public:
	piece();
	piece(Color color, pos p, pos sp= { 1,1 },pos offSet={0,0});
	void setClr(Color clrr) { color_ = clrr; }
	Color get_color() const { return color_; }
	int get_position() const { return position_; }
	void set_position(int position) { position_ = position; }
	void set_current_position(sf::Vector2f position) { currentPosition = position; }
	void move(int x=0);
	bool hasKilled;
	sf::Vector2f startPos;
	pos offSet_;
	void setPos(pos p);


	void drawPiece(sf::RenderWindow& window)
	{
		if (position_ == -1)
		{
			currentPosition.x = position.col * SQUARE_SIZE3;
			currentPosition.y = position.row * SQUARE_SIZE3;
			printPosition.x = (position.col * SQUARE_SIZE3) + offSet_.col;
			printPosition.y = (position.row * SQUARE_SIZE3) + offSet_.row;
		}
		if (position_ == 0)
		{
			currentPosition = startPos;
			printPosition = startPos;
		}
		sf::Texture piece;
		if (color_ == RED) {
			if (!piece.loadFromFile("red.png"))
				return;
			//cout << "REDD";
		}
		if (color_ == BLUE) {
			if (!piece.loadFromFile("blue.png"))
				return;
		}
		if (color_ == GREEN) {
			if (!piece.loadFromFile("green.png"))
				return;
		}
		if (color_ == YELLOW) {
			if (!piece.loadFromFile("yellow.png"))
				return;
		}
		if (color_ == PURPLE) {
			if (!piece.loadFromFile("purple.png"))
				return;
		}
		if (color_ == ORANGE) {
			if (!piece.loadFromFile("orange.png"))
				return;
		}
		sf::Sprite s(piece);
		//s.setScale(0.1, 0.1);
		s.setScale(0.05, 0.05);
		sf::Vector2f position = printPosition;
		position.x += 15;
		//position.y += 1;
		s.setPosition(position);
		//cout <<"\n" << "inner x" << currentPosition.x << "inner y " << currentPosition.y;
		window.draw(s);
	}
	bool isClicked(sf::Vector2f position);
	sf::Vector2f currentPosition;
private:
	Color color_;
	int position_;
	pos position;
	
	sf::Vector2f printPosition;

};

