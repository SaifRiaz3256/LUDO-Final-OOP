#include "ludo.h"
#include<iostream>
#include<windows.h>
using namespace std;

ludo::ludo() {
    cout << "Enter no of players: ";
   cin >> nOP;
    //nOP = 6;
    moves = 0;
    brd = new board(nOP);
    currentPlayer = 0;

}
void ludo::turnChange() {
    currentPlayer = (currentPlayer + 1) % nOP;
  
}
void ludo::selectSc(sf::RenderWindow& window) {

    //sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    //// Convert the position to a position relative to the boar
    //sc = window.mapPixelToCoords(mousePos);
    int c1, c2;

    getRowColbyLeftClick(c2, c1, window);
    sc.x = c1;
    sc.y = c2;

}

void ludo::selectDc(sf::RenderWindow& window) {

   /* sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    // Convert the position to a position relative to the board
    dc = window.mapPixelToCoords(mousePos);*/

    int c1, c2;

    getRowColbyLeftClick(c2, c1, window);
    dc.x = c1;
    dc.y = c2;
}
static int x;
bool ludo::checkWin(int i) {
   
        for (int j = 0; j < brd->pls[i].ps.size(); j++)
        {
            if (brd->pls[i].ps[j].get_position() != 82)
            {
                return false;
                
            }
            
        }
       
        
    
   
    return true;

}
bool ludo::killCheck(sf::Vector2f currentPos) {
    
    bool kill = false;
    for (int i = 0; i < brd->pls.size(); i++)
    {
        for (int j = 0; j < brd->pls[i].ps.size(); j++)
        {
            if (brd->pls[i].ps[j].isClicked(currentPos)&& brd->pls[i].ps[j].get_color() !=currentPlayer) {

                brd->pls[i].ps[j].set_position(-1);
                cout << "\nHAHAHAHA    MAR GYA   \n";
                kill = true;
               
            }

           
           
        }
      
    }
    for (int i = 0; i < brd->pls.size(); i++)
    {
       
        for (int j = 0; j < brd->pls[i].ps.size(); j++)
        {
            if (kill && brd->pls[i].ps[j].get_color() == currentPlayer) {

                brd->pls[i].ps[j].hasKilled = true;
                cout << "\n  KOI NI TUJE M DEKHTA HOU \n";
            }



        }
    }



    return kill;

}

// Dice called

void ludo::roll() {
    cout << "ENTER YOUR SCORE:";
    //cin >> moves;
   // return;

    srand(time(0));
    int roll = rand() % 6 + 1;
    cout << "\nROLL: " << roll << endl;
    moves = roll;

}



bool ludo::isValidSc() 
{
    for (int j = 0; j < brd->pls[currentPlayer].ps.size(); j++)
    {
        if (brd->pls[currentPlayer].ps[j].isClicked(sc))
        {
            return true;
            
        }
    }
    return false;
}

// Main game functionality

void ludo::play()
{
    bool kill;
    currentPlayer = 0;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "LUDO");

    while (window.isOpen() ) 
    {
        sf::Event event;

        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
            {

                kill = false;
                // Get the source position of the mouse click
                do 
                {
                    cout << "\nCurrnt Player:" << currentPlayer << "\n";
                    cout << "\nClick source:\n";
                    selectSc(window);
                    
                } while (!isValidSc());
               
               // selectSc(window);

                int row = ((sc.y) / SQUARE_SIZE3);
                int col = ((sc.x) / SQUARE_SIZE3);
                std::cout << "  ROW: " << row << "  COL: " << col << std::endl;

                //std::cout << "  xpixel " << mousePos.x << "  ypixel " << mousePos.y << std::endl;

                // Dice called

                roll();

                for (int i = 0; i < brd->pls.size(); i++)
                {
                    for (int j = 0; j < brd->pls[i].ps.size(); j++)
                    {
                        if (brd->pls[i].ps[j].isClicked(sc))
                        {
                            sc.x = -1;
                            sc.y = -1;
                            //get destination position of the mouse click 
                            //selectDc(window);
                           // brd->pls[i].ps[j].move(moves);
                             if (brd->pls[i].ps[j].get_position() == -1)
                             {
                                 brd->pls[i].ps[j].move(moves);
                                 break;
                             }
                             for (int k = 0; k < moves; k++) {

                                 brd->pls[i].ps[j].move(moves);
                                
                                 window.clear();
                                 brd->printBoard(window);
                                 window.display();
                                 Sleep(100);

                             }
                             kill=killCheck(brd->pls[i].ps[j].currentPosition);
                            break;

                        }
                        
                       
                    }
                   
                }
                for (int i = 0; i < brd->pls.size(); i++)
                {
                    if (brd->pls[i].hasWon == false) {
                        if (checkWin(i))
                        {
                            brd->pls[i].position = x;
                            brd->pls[i].hasWon = true;
                            x++;
                            system("cls");
                            cout<<(brd->pls[i].clr) << "has won";
                            exit(0);
                        }
                    }
                }



                if (moves != 6 && !kill) 
                {
                    turnChange();
                }
                               
            }
          
        }
        
        window.clear();
        brd->printBoard(window);
        window.display();
    }

}
