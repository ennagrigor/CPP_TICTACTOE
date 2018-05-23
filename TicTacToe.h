#include "Board.hpp"
#include "DummyPlayers.h"

using namespace std;


class TicTacToe{
	public:
	int size;
	Board theBoard;
	Player * theWinner;
	
    TicTacToe(int s);
	
	 Board const &board() const{
		return theBoard;
	}
	
	Player &winner()const{
		return (*theWinner);
    }
    void play(Player &p1, Player &p2);
    int gameOver();
};