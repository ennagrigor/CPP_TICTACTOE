#include "Board.hpp"
using namespace std;

    Board::Board(int x) {
        sizeB = x; 
        for (int i = 0; i<this->sizeB; i++){
            vector<BoardMem> row; 
            for(int j = 0 ; j<this->sizeB; j++){
                BoardMem bm (i, j, '.');
                row.push_back(bm); 
            }
            board.push_back(row); 
        }
    } 

     ostream& operator << ( ostream& op, const Board& bo){
        for (int i = 0; i<bo.sizeB; i++){
            for(int j = 0 ; j<bo.sizeB; j++){
                op<< bo.board[i][j];
            }
            op<<endl;
        }
        return op;
    }

       BoardMem& Board::operator [] (Coordinate const & lis){
        int i = lis.row;
        int j = lis.col;

        if(i >= sizeB || i < 0 || j >= sizeB || j < 0  ){
            IllegalCoordinateException ex(i,j);
            throw ex;
        }

        return this->board[i][j];
    }


   

    Board& Board::operator = (char c){
        
        if (c != 'O' && c != '.' && c!= 'X'){
            IllegalCharException ex(c);
            throw ex;
        }

        for (int i = 0; i < sizeB; i++){
            for(int j = 0 ; j < sizeB; j++){
                board[i][j] = '.';
            }
        }

            return (*this);
        }

   Board& Board::operator= (Board b2){
			this->sizeB = b2.sizeB;
			vector<vector<BoardMem> > newBoard;
			for (int i = 0; i < sizeB; ++i) {
				vector<BoardMem> tmp;
				for (int j = 0; j < sizeB; ++j) {
					BoardMem c(i, j, b2.board[i][j].val);
					tmp.push_back(c);
				}
				newBoard.push_back(tmp);
			}
			
			board = newBoard;
			return *this;
		}

        Board::Board(const Board &b2) {
			this->sizeB = b2.sizeB;
			
			for (int i = 0; i < sizeB; ++i) {
				vector<BoardMem> tmp;
				for (int j = 0; j < sizeB; ++j) {
					BoardMem c(i, j, b2.board[i][j].val);
					tmp.push_back(c);
				}
				board.push_back(tmp);
			}
		}

