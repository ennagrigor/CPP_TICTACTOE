#pragma once
#include "Player.h"
class Champion: public Player {

    public:
	const string name() const override { 
        return "EnnaGrigor&&DanaBaraban";
     }
     
	const Coordinate play(const Board& board) override;
};
