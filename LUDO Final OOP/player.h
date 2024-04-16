#pragma once
#include<vector>
#include"piece.h"
#include"utility.h"
using namespace std;


class player
{
public:
	player();
	player(Color clr);
	vector<piece> ps;
	Color clr;
	int sizeOfPiece;
	//vector <int>possibleMovesToBeMoved;
	bool hasWon;
	int position;

	

//public:
//	player(Color color) : color_(color) {}
//	Color get_color() const { return color_; }
//	void add_piece(piece piece) { pieces_.push_back(piece); }
//	std::vector<piece>& get_pieces()  { return pieces_; }
//private:
//	Color color_;
//	std::vector<piece> pieces_;

};

