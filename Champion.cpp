#include "Champion.h"
	
	const Coordinate Champion::play(const Board& board) {
		Coordinate c{0, board.size()-1};
		if (board[c]=='.') {
				return c;
		}
		Coordinate c1{ board.size()-1,0};
		if (board[c1]=='.') {
				return c1;
		}
		
		for (uint y=0; y<board.size(); ++y) {
			
			Coordinate c2{board.size()-((int)y)-1, (int)y};
			if (board[c2]=='.') {
				return c2;
			}
			
		}
		
	
		return {0,0}; 
	};