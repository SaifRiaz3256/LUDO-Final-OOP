
#include "piece.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include<time.h>
#include<conio.h>
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std;

// Piece ka existence

piece::piece() 
{
	position_ = -1;
	hasKilled = false;//isko false krna hai , ye bas check krne k liye true kia h
}

// Piece ka creation

piece::piece(Color color, pos p, pos sp, pos offSet) {

	color_ = color;
	offSet_ = offSet;
	position_ = -1;
	position = p;
	currentPosition.x = p.col * SQUARE_SIZE3;
	currentPosition.y = p.row * SQUARE_SIZE3;
	printPosition.x =( p.col * SQUARE_SIZE3)+offSet.col;
	printPosition.y =( p.row * SQUARE_SIZE3)+offSet.row;
	hasKilled = false;//isko false krna hai , ye bas check krne k liye true kia h
	startPos.x = sp.col * SQUARE_SIZE3;
	startPos.y = sp.row * SQUARE_SIZE3;


}
void piece::move(int x)
{
	
	if (position_ == -1 && x == 6)
	{
		position_ = 0;
	}
	else if (position_ != -1) {
		position_ += x;
	}
	cout << "\npos: " << position_ << "\n";
	for (int i = 0; i <1; i++){
		int row = ((currentPosition.y) / SQUARE_SIZE3);
		int col = ((currentPosition.x) / SQUARE_SIZE3);
		cout << "\nrow2: " << row << "col2: " << col << endl;

		if (row == 11 && col == 0 && color_ == 0 && hasKilled) {
			col = 1;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 3 && col == 5 && color_ == 1 && hasKilled) {
			col = 5;
			row = 4;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 3 && col == 14 && color_ == 2 && hasKilled) {
			col = 13;
			row = 4;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 11 && col == 18 && color_ == 3 && hasKilled) {
			col = 17;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 18 && col == 14 && color_ == 4 && hasKilled) {
			col = 13;
			row = 17;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 18 && col == 5 && color_ == 5 && hasKilled) {
			col = 5;
			row = 17;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		
	//// start 
		if (row == 9 && col == 0) {
			col = 1;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45 - 10;
			continue;
		}
		if (row == 10 && col == 1) {
			col = 2;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45 - 10;
			continue;
		}
		if (row == 10 && col == 2) {
			col = 3;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45 - 10;
			continue;
		}
		if (row == 10 && col == 3) {
			col = 4;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45 - 10;
			continue;
		}
		if (row == 10 && col == 4) {
			col = 5;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45 - 10;
			continue;
		}
		if (row == 10 && col == 5) {
			col = 6;
			row = 8;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45 + 5;
			printPosition.y = row * 45 - 10;
			continue;
		}
		if (row == 8 && col == 6) {
			col = 6;
			row = 7;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45 - 10;
			printPosition.y = row * 45 - 4;
			continue;
		}
		if (row == 7 && col == 6) {
			col = 5;
			row = 6;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45 ;
			printPosition.y = row * 45 + 2;
			continue;
		}
		if (row == 6 && col == 5) {
			col = 5;
			row = 5;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45 - 12;
			printPosition.y = row * 45 ;
			continue;
		}
		if (row == 5 && col == 5) {
			col = 4;
			row = 4;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45 + 5;
			printPosition.y = row * 45 + 10;
			continue;
		}
		if (row == 4 && col == 4) {
			col = 4;
			row = 3;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45 - 12;
			printPosition.y = row * 45 + 10;
			continue;
		}
		if (row == 3 && col == 4) {
			col = 5;
			row = 3;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-10;
			printPosition.y = row * 45-5;
			continue;
		}
		if (row == 3 && col == 5) {
			col = 6;
			row = 2;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-17;
			printPosition.y = row * 45+10;
			continue;
		}
		if (row == 2 && col == 6) {
			col = 6;
			row = 3;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-2;
			printPosition.y = row * 45+5;
			continue;
		}
		if (row == 3 && col == 6) {
			col = 6;
			row = 4;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+10;
			printPosition.y = row * 45+8;
			continue;
		}
		if (row == 4 && col == 6) {
			col = 7;
			row = 5;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 5 && col == 7) {
			col = 7;
			row = 6;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+12;
			printPosition.y = row * 45+2;
			continue;
		}
		if (row == 6 && col == 7) {
			col = 8;
			row = 7;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-3;
			printPosition.y = row * 45-3;
			continue;
		}
		if (row == 7 && col == 8) {
			col = 10;
			row = 7;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+3;
			printPosition.y = row * 45-3;
			continue;
		}
		if (row == 7 && col == 10) {
			col = 11;
			row = 6;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-8;
			printPosition.y = row * 45-2;
			continue;
		}
		if (row == 6 && col == 11) {
			col = 11;
			row = 5;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+3;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 5 && col == 11) {
			col = 12;
			row = 4;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-9;
			printPosition.y = row * 45+2;
			continue;
		}
		if (row == 4 && col == 12) {
			col = 12;
			row = 3;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+8;
			printPosition.y = row * 45+5;
			continue;
		}
		if (row == 3 && col == 12) {
			col = 13;
			row = 2;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-4;
			printPosition.y = row * 45+11;
			continue;
		}
		if (row == 2 && col == 13) {
			col = 14;
			row = 3;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-10;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 3 && col == 14) {
			col = 15;
			row = 3;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-12;
			printPosition.y = row * 45+12;
			continue;
		}
		if (row == 3 && col == 15) {
			col = 14;
			row = 4;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45+7;
			continue;
		}
		if (row == 4 && col == 14) {
			col = 14;
			row = 5;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-20;
			printPosition.y = row * 45+12;
			continue;
		}
		if (row == 5 && col == 14) {
			col = 13;
			row = 6;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 6 && col == 13) {
			col = 12;
			row = 7;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45+14;
			continue;
		}
		if (row == 7 && col == 12) {
			col = 12;
			row = 8;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-4;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 8 && col == 12) {
			col = 13;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 10 && col == 13) {
			col = 14;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 10 && col == 14) {
			col = 15;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 10 && col == 15) {
			col = 16;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 10 && col == 16) {
			col = 17;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 10 && col == 17) {
			col = 18;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 10 && col == 18) {
			col = 18;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 11 && col == 18) {
			col = 18;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 12 && col == 18) {
			col = 17;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 12 && col == 17) {
			col = 16;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 12 && col == 16) {
			col = 15;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 12 && col == 15) {
			col = 14;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 12 && col == 14) {
			col = 13;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 12 && col == 13) {
			col = 12;
			row = 14;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+2;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 14 && col == 12) {
			col = 13;
			row = 15;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-12;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 15 && col == 13) {
			col = 13;
			row = 16;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45-12;
			continue;
		}
		if (row == 16 && col == 13) {
			col = 14;
			row = 17;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-8;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 17 && col == 14) {
			col = 14;
			row = 18;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45-12;
			continue;
		}
		if (row == 18 && col == 14) {
			col = 15;
			row = 18;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-12;
			printPosition.y = row * 45+4;
			continue;
		}
		if (row == 18 && col == 15) {
			col = 14;
			row = 19;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-10;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 19 && col == 14) {
			col = 13;
			row = 19;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-10;
			printPosition.y = row * 45+10;
			continue;
		}
		if (row == 19 && col == 13) {
			col = 12;
			row = 18;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+8;
			printPosition.y = row * 45+10;
			continue;
		}
		if (row == 18 && col == 12) {
			col = 12;
			row = 17;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-8;
			printPosition.y = row * 45+10;
			continue;
		}
		if (row == 17 && col == 12) {
			col = 11;
			row = 16;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+8;
			printPosition.y = row * 45+10;
			continue;
		}
		if (row == 16 && col == 11) {
			col = 11;
			row = 15;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45-10;
			printPosition.y = row * 45+12;
			continue;
		}
		if (row == 15 && col == 11) {
			col = 10;
			row = 15;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45+10;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 15 && col == 10) {
			col = 8;
			row = 15;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45-10;
			continue;
		}
		if (row == 15 && col == 8) {
			col = 7;
			row = 15;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 15 && col == 7) {
			col = 7;
			row = 16;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 16 && col == 7) {
			col = 6;
			row = 17;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 17 && col == 6) {
			col = 6;
			row = 18;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 18 && col == 6) {
			col = 5;
			row = 19;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
	
		if (row == 19 && col == 5) {
			col = 5;
			row = 18;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 18 && col == 5) {
			col = 4;
			row = 18;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 18 && col == 4) {
			col = 4;
			row = 17;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 17 && col == 4) {
			col = 5;
			row = 16;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 16 && col == 5) {
			col = 5;
			row = 15;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}

		if (row == 15 && col == 5) {
			col = 6;
			row = 15;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 15 && col == 6) {
			col = 6;
			row = 14;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 14 && col == 6) {
			col = 5;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 12 && col == 5) {
			col = 4;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 12 && col == 4) {
			col = 3;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 12 && col == 3) {
			col = 2;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 12 && col == 2) {
			col = 1;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 12 && col == 1) {
			col = 0;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 12 && col == 0) {
			col = 0;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 11 && col == 0) {
			col = 0;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 10 && col == 0) {
			col = 1;
			row = 10;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		//1st
		if (row == 11 && col == 1 && color_ == 0 && hasKilled) {
			col = 2;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 11 && col == 2 && color_ == 0 && hasKilled) {
			col = 3;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 11 && col == 3 && color_ == 0 && hasKilled) {
			col = 4;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 11 && col == 4 && color_ == 0 && hasKilled) {
			col = 5;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 11 && col == 5 && color_ == 0 && hasKilled) {
			col = 6;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		//2nd
		if (row == 4 && col == 5 && color_ == 1 && hasKilled) {
			col = 6;
			row = 5;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 5 && col == 6 && color_ == 1 && hasKilled) {
			col = 6;
			row = 6;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 6 && col == 6 && color_ == 1 && hasKilled) {
			col = 7;
			row = 7;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 7 && col == 7 && color_ == 1 && hasKilled) {
			col = 7;
			row = 8;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 8 && col == 7 && color_ == 1 && hasKilled) {
			col = 8;
			row = 9;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		//3rd
		if (row == 4 && col == 13 && color_ == 2 && hasKilled) {
			col = 13;
			row = 5;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 5 && col == 13 && color_ == 2 && hasKilled) {
			col = 12;
			row = 6;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 6 && col == 12 && color_ == 2 && hasKilled) {
			col = 12;
			row = 7;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 7 && col == 12 && color_ == 2 && hasKilled) {
			col = 11;
			row = 8;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 8 && col == 11 && color_ == 2 && hasKilled) {
			col = 11;
			row = 9;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		//4th
		if (row == 11 && col == 17 && color_ == 3 && hasKilled) {
			col = 16;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 11 && col == 16 && color_ == 3 && hasKilled) {
			col = 15;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 11 && col == 15 && color_ == 3 && hasKilled) {
			col = 14;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 11 && col == 14 && color_ == 3 && hasKilled) {
			col = 13;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 11 && col == 13 && color_ == 3 && hasKilled) {
			col = 12;
			row = 11;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		//5th
		if (row == 17 && col == 13 && color_ == 4 && hasKilled) {
			col = 13;
			row = 16;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 16 && col == 13 && color_ == 4 && hasKilled) {
			col = 12;
			row = 15;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 15 && col == 12 && color_ == 4 && hasKilled) {
			col = 12;
			row = 14;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 14 && col == 12 && color_ == 4 && hasKilled) {
			col = 11;
			row = 13;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 13 && col == 11 && color_ == 4 && hasKilled) {
			col = 11;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		//6th
		if (row == 17 && col == 5 && color_ == 5 && hasKilled) {
			col = 6;
			row = 16;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 16 && col == 6 && color_ == 5 && hasKilled) {
			col = 6;
			row = 15;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}

		if (row == 15 && col == 6 && color_ == 5 && hasKilled) {
			col = 7;
			row = 14;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 14 && col == 7 && color_ == 5 && hasKilled) {
			col = 7;
			row = 13;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}
		if (row == 13 && col == 7 && color_ == 5 && hasKilled) {
			col = 8;
			row = 12;
			currentPosition.x = col * 45;
			currentPosition.y = row * 45;
			printPosition.x = col * 45;
			printPosition.y = row * 45;
			continue;
		}

	}
	/*drawPiece(window);
	window.display();
    Sleep(1000);*/
}


bool piece::isClicked(sf::Vector2f position)
{
	int row = ((position.y) / SQUARE_SIZE3);
	int col = ((position.x) / SQUARE_SIZE3);
	int _row = ((currentPosition.y) / SQUARE_SIZE3);
	int _col = ((currentPosition.x) / SQUARE_SIZE3);

	/*int _row = ((printPosition.y) / SQUARE_SIZE3);
	int _col = ((printPosition.x) / SQUARE_SIZE3);*/

	if (row == _row && col == _col)
	{
		return true;
	}
	return false;
}