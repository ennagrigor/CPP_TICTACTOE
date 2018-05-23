#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "BoardMem.cpp"
#include "IllegalCoordinateException.cpp"
using Coordinate = BoardMem;

using namespace std;

class Board {
    public:
    int sizeB;
    int size () const {
	return sizeB; 
    }	 
    vector <vector <BoardMem> > board;
    Board(int x) ;
    friend ostream& operator << ( ostream& op, const Board& bo);
    BoardMem& operator [] (Coordinate const & lis);
    
    Board& operator = (char c);
    Board& operator = (Board b);
    Board(const Board &b2);

 BoardMem operator [] (Coordinate const & lis) const{
        int i = lis.row;
        int j = lis.col;

        if(i >= sizeB || i < 0 || j >= sizeB || j < 0  ){
            IllegalCoordinateException ex(i,j);
            throw ex;
        }

        return this->board[i][j];
    }





};


