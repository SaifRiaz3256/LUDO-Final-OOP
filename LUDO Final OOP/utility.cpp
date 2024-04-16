#include "utility.h"
#include <SFML/Graphics.hpp>
void getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window)
{

	while (true)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i p = sf::Mouse::getPosition(window);
				cpos = p.x;
				rpos = p.y;
				return;
			}
			else if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}
		}
	}

	//This version of the function uses the pollEvent function to check for left - click events, and returns as soon as a left - click event is detected.It also checks for window close events, so that the program can exit cleanly if the user closes the window.

}