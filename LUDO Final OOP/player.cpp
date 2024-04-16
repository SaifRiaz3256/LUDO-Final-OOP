#include "player.h"


player::player() {
	
	hasWon = false;
}
player::player(Color clrr) {

	hasWon = false;
	clr = clrr;
	sizeOfPiece = 4;
	pos pst;
	
	for (int i = 0; i < 4; i++)
	{
		if (i == 0) {
			if (clr == RED) {
				piece p(clr, pos{ 15,1 }, pos{ 17,4 }, pos{ 20,-9 });
				ps.push_back(p);
			}
			if (clr == BLUE) {
				piece p(clr, pos{ 2,7 }, pos{ 3,6 }, pos{ 30,27 });
				ps.push_back(p);
			}
			if (clr == GREEN) {
				piece p(clr, pos{ 5,15 }, pos{ 4,14 }, pos{ 25,15 });
				ps.push_back(p);
			}
			if (clr == YELLOW) {
				piece p(clr, pos{ 14,15 }, pos{ 12,17 }, pos{ 5,-10 });
				ps.push_back(p);
			}
			if (clr == ORANGE) {
				piece p(clr, pos{ 18,10 }, pos{ 18,12 }, pos{ 34,21 });
				ps.push_back(p);
			}
			
			if (clr == PURPLE)
			{
				piece p(clr, pos{ 6,1 }, pos{ 10,1 }, pos{ 0,-9 });
				ps.push_back(p);

			}
		}
		

		if (i == 1) {
			if (clr == RED) {
				piece p(clr, pos{ 13,1 }, pos{ 17,4 }, pos{ 22,16 });
				ps.push_back(p);
			}
			if (clr == BLUE) {
				piece p(clr, pos{ 1,9 }, pos{ 3,6 }, pos{ 10,0 });
				ps.push_back(p);
			}
			if (clr == GREEN) {
				piece p(clr, pos{ 6,17 }, pos{ 4,14 }, pos{ 0,10 });
				ps.push_back(p);
			}
			if (clr == YELLOW) {
				piece p(clr, pos{ 13,16 }, pos{ 12,17 }, pos{ 27,32 });
				ps.push_back(p);
			}
			if (clr == ORANGE) {
				piece p(clr, pos{ 17,9 }, pos{ 18,12 }, pos{ 18,0 });
				ps.push_back(p);
			}
			if (clr == PURPLE)
			{
				piece p(clr, pos{ 5,3 }, pos{ 10,1 }, pos{ 20,-9 });
				ps.push_back(p);

			}
		}


		if (i == 2) {
			if (clr == RED) {
				piece p(clr, pos{ 14,3 }, pos{ 17,4 }, pos{ 2,12 });
				ps.push_back(p);
			}
			if (clr == BLUE) {
				piece p(clr, pos{ 2,10 }, pos{ 3,6 }, pos{ 28,21 });
				ps.push_back(p);
			}
			if (clr == GREEN) {
				piece p(clr, pos{ 8,16 }, pos{ 4,14 }, pos{ 0,30 });
				ps.push_back(p);
			}
			if (clr == YELLOW) {
				piece p(clr, pos{ 15,17 }, pos{ 12,17 }, pos{ 20,12 });
				ps.push_back(p);
			}
			if (clr == ORANGE) {
				piece p(clr, pos{ 18,7 }, pos{ 18,12 }, pos{ 33,28 });
				ps.push_back(p);
			}
			if (clr == PURPLE)
			{
				piece p(clr, pos{ 8,1 }, pos{ 10,1 }, pos{ 0,15 });
				ps.push_back(p);

			}
		}

		if (i == 3) {
			if (clr == RED) {
				piece p(clr, pos{ 15,3}, pos{ 17,4 }, pos{ 45,-9 });
				ps.push_back(p);
			}
			if (clr == BLUE) {
				piece p(clr, pos{ 4,9 }, pos{ 3,6 }, pos{ 3,0 });
				ps.push_back(p);
			}
			if (clr == GREEN) {
				piece p(clr, pos{ 7,15 }, pos{ 4,14 }, pos{ 17,-9 });
				ps.push_back(p);
			}
			if (clr == YELLOW) {
				piece p(clr, pos{ 16,15 }, pos{ 12,17 }, pos{ 0,12});
				ps.push_back(p);
			}
			if (clr == ORANGE) {
				piece p(clr, pos{ 20,9 }, pos{ 18,12 }, pos{ 12,1 });
				ps.push_back(p);
			}
			if (clr == PURPLE)
			{
				piece p(clr, pos{ 7,3 }, pos{ 10,1 }, pos{ 17,13 });
				ps.push_back(p);

			}
			
		}
		
		
		//ps[i].set_current_position()
	}

	

}