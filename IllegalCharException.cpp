#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;


class IllegalCharException {
    
    public:
    char c; 

    IllegalCharException(char c){
        this->c = c;  
    }

    char theChar() const{
        return c ;
    }
};
