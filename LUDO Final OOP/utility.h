#pragma once
#include <SFML/Graphics.hpp>
enum Color{ PURPLE, BLUE, GREEN,YELLOW, ORANGE, RED};
void getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window);
struct pos {
	float row, col;
};
const int SCREEN_WIDTH = 1900;
const int SCREEN_HEIGHT = 1000;
const int SQUARE_SIZE = 400;
const int SQUARE_SIZE2 = 300;
const float SQUARE_SIZE3 = 45;// (200 / 3);

