#ifndef HEADER_HPP
#define HEADER_HPP

#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel{
    
    struct Board{    
        vector<vector<char>> board;
        
    
        Board(){
            board = vector<vector<char>> (300, vector<char>(300, '_'));
        }

        //Board(unsigned int lines, unsigned int rows);         
            
        void post(unsigned int rowIndex, unsigned int columIndex, Direction dir, string const& input);

        string read(unsigned int rowIndex, unsigned int columIndex, Direction dir, unsigned int length);

        void show();
    };
}

#endif