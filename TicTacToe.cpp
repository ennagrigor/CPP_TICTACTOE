
#include "TicTacToe.h"

TicTacToe::TicTacToe(int s) : theBoard(s){
		size = s;
	}

void TicTacToe::play(Player &p1, Player &p2){
		theBoard = '.';
		
		p1.myChar = 'X';
		p2.myChar = 'O';
		
		int turn = 1;
		
		Coordinate c(0,0);
		while(gameOver() == 0){
			
			
			if(turn == 1){
				try{
					c = p1.play(theBoard);
				}catch(string s){theWinner = &p2; return;}
			} else {
				try{
					c = p2.play(theBoard);
				}catch(string s){theWinner = &p1; return;}
			}
			
			if(theBoard[c] == '.'){
				if(turn == 1)
					theBoard[{c.row, c.col}] = 'X';
				else theBoard[{c.row, c.col}] = 'O';
			}
			else{
				if(turn == 1)
					theWinner = &p2;
				else theWinner = &p1;
				return;
			}
			
			turn = 1- turn;
		}
		
		
		
		if(gameOver() == 1){
			theWinner = &p1;
		}
		if(gameOver() == 2){
			theWinner = &p2;
		}
		if(gameOver() == -1){
			theWinner = &p2;
		}
			
	}

int TicTacToe::gameOver(){
		char arr[size];
		int k;
		char a;
		for(int j =0; j<size; j++){
			for(int i =0; i<=size-1; i++){
				arr[i] =  theBoard[{j,i}];
			}	
			
			for( k=1; k<size; k++){
				 a = arr[0];
				if(arr[k] != a) 
					break;
			}
			if(k==size && a!='.'){
				if(a == 'X')
					return 1;
				else return 2;
			}				
			
		}
		
		for(int j =0; j<size; j++){
			
			for(int i =0; i<=size-1; i++){
				arr[i] =  theBoard[{i,j}];
			}	
			
			for( k=1; k<size; k++){
				 a = arr[0];
				if(arr[k] != a) 
					break;
			}
			if(k==size && a!='.'){
				if(a == 'X')
					return 1;
				else return 2;
			}				
			
		}
		
		for(int i =0; i<=size-1; i++){
			arr[i] =  theBoard[{i,i}];
		}
				
		for( k=1; k<size; k++){
			 a = arr[0];
			if(arr[k] != a) 
				break;
		}
		
		if(k==size && a!='.'){
			if(a == 'X')
				return 1;
			else return 2;
		}				
		
		for(int i =0; i<=size-1; i++){
			arr[i] =  theBoard[{i,size- i - 1}];
		}
				
		for( k=1; k<size; k++){
			 a = arr[0];
			if(arr[k] != a) 
				break;
		}
		
		if(k==size && a!='.'){
			if(a == 'X')
				return 1;
			else return 2;
		}	
		
		for(int i =0; i<=size-1; i++){
			for(int j =0; j<=size-1; j++){
				char c = theBoard[{i,j}];
				if(c == '.')
					return 0;
			}
		}	
		return -1;
	};	