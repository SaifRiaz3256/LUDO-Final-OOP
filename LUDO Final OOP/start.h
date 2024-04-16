#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;


#define MaxMainMenu 4

class MainMenu
{
private:
	int mainMenuSelected;
	// To add True Type Font type
	Font font;
	// Size of main 
	Text mainMenu[MaxMainMenu];



public:

	MainMenu(float width, float hieght);
	void draw(RenderWindow& window);
	void next();
	void back();

	int mainMenuPressed()
	{
		return mainMenuSelected;
	}

	~MainMenu();


};
