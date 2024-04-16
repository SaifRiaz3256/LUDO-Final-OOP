// Include SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include"ludo.h"
// To throw exception
#include<exception>

#include<fstream>
#include<iostream>
#include "start.h"

// sf for SFML
using namespace sf;
using namespace std;

// Display screen Initialization
MainMenu::MainMenu(float width, float hieght)
{
	if (!font.loadFromFile("ParfaiteValeu.ttf"))
	{
		cout << "No font file is found";
	}


	//play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(200, 200);



	//options
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(200, 300);


	//About
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("About");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(200, 400);

	//Exit
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(200, 500);



	mainMenuSelected = -1;

}


MainMenu::~MainMenu()
{

}

// DIsplay Screen at the start of ludo

void MainMenu::draw(RenderWindow& window)
{
	for (int i = 0; i < MaxMainMenu; ++i)
	{
		//SFML window

		window.draw(mainMenu[i]);

	}
}

// After pressing one option of main menu

void MainMenu::next()
{
	if (mainMenuSelected - 1 >= 0)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		mainMenuSelected--;

		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}

		mainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);

	}


}


void MainMenu::back()
{
	if (mainMenuSelected + 1 <= MaxMainMenu)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		mainMenuSelected++;

		if (mainMenuSelected == 4)
		{
			mainMenuSelected = 0;
		}

		mainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);

	}
}

int main()
{
	// Creation of another window by RENDER Window
	RenderWindow window(VideoMode(1700, 900), "LUDO", Style::Titlebar | Style::Close);
	MainMenu menu(window.getSize().x, window.getSize().y);
	ludo l;
	
	//mian background
	RectangleShape backGround1;
	backGround1.setSize(Vector2f(1700, 900));
	Texture backTexture1;
	backTexture1.loadFromFile("LudoStart.jpg");
	backGround1.setTexture(&backTexture1);

	//background photo of the gameplay

	RectangleShape backGround2;
	backGround2.setSize(Vector2f(1500, 850));
	Texture backTexture2;
	backTexture2.loadFromFile("ludoBoard.png");
	backGround2.setTexture(&backTexture2);

	//background photo of the options


	RectangleShape backGround3;
	backGround3.setSize(Vector2f(1500, 850));
	Texture backTexture3;
	backTexture3.loadFromFile("options.jpg");
	backGround3.setTexture(&backTexture3);

	//background photo for ABOUT section


	RectangleShape backGround4;
	backGround4.setSize(Vector2f(1500, 850));
	Texture backTexture4;
	backTexture4.loadFromFile("options.jpg");
	backGround4.setTexture(&backTexture4);

	while (window.isOpen())
	{
		//Event Processing
		Event evnt;
		while (window.pollEvent(evnt))
		{	
			// Request for closing the window
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}

			if (evnt.type == evnt.KeyReleased)
			{
				// UP Arrow by keyboad
				if (evnt.key.code == Keyboard::Up)
				{
					menu.next();
					break;
				}

				if (evnt.key.code == Keyboard::Down)
				{
					menu.back();
					break;
				}

				if (evnt.key.code == Keyboard::Return)
				{
					RenderWindow PLAY(VideoMode(1500, 850), "PLAY");
					RenderWindow OPTIONS(VideoMode(1500, 850), "OPTIONS");
					RenderWindow ABOUT(VideoMode(1500, 850), "ABOUT");


					int x = menu.mainMenuPressed();
					if (x == 0)
					{

						while (PLAY.isOpen())
						{
							Event aevent;

							while (PLAY.pollEvent(aevent))
							{
								if (aevent.type == aevent.Closed)
								{
									PLAY.close();
								}
								if (aevent.type == aevent.KeyPressed)
								{
									// Press ESC to close the window

									if (aevent.key.code == Keyboard::Escape)
									{
										PLAY.close();

									}
								}
							}

							OPTIONS.close();
							ABOUT.close();
							PLAY.clear();
							l.play();
							PLAY.draw(backGround2);
							PLAY.display();
						}

					}

					if (x == 1)
					{

						while (OPTIONS.isOpen())
						{
							Event aevent;

							while (OPTIONS.pollEvent(aevent))
							{
								if (aevent.type == aevent.Closed)
								{
									OPTIONS.close();
								}
								if (aevent.type == aevent.KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										OPTIONS.close();

									}
								}
							}



							ABOUT.close();
							PLAY.close();
							OPTIONS.clear();
							OPTIONS.draw(backGround3);
							OPTIONS.display();
						}

					}

					if (x == 2)
					{

						while (ABOUT.isOpen())
						{
							Event aevent;

							while (ABOUT.pollEvent(aevent))
							{
								if (aevent.type == aevent.Closed)
								{
									ABOUT.close();
								}
								if (aevent.type == aevent.KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										ABOUT.close();

									}
								}
							}



							OPTIONS.close();
							PLAY.close();
							ABOUT.clear();
							ABOUT.draw(backGround4);
							ABOUT.display();
						}

					}

					if (x == 3)
					{
						window.close();
					}
					break;


				}
			}
		}

		// Clear the whole window before rendering a new frame
		window.clear();
		// Draw some graphical entities
		window.draw(backGround1);
		menu.draw(window);
		window.display();




	}

	return 0;
}
