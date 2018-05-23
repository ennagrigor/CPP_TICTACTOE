#include "Board.h"
#pragma once
using Coordinate = BoardMem;

class Player{
public:
    char myChar;
    char getChar() const {return myChar;}
    virtual const string name() const = 0;
    virtual const Coordinate play(const Board& board) =0;
};