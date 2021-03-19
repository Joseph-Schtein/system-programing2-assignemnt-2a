#include "Board.hpp"
#include "Direction.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <array>
using ariel::Direction;



void ariel::Board::post(unsigned int rowIndex, unsigned int columIndex, Direction dir, string input){
    std::vector<char> charInput(input.c_str(), input.c_str() + input.size());

    if(rowIndex+input.size() > board.size()){
        board.resize(rowIndex+input.length()+100, std::vector<char>(columIndex, '_'));
        boolBoard.resize(rowIndex+input.length()+100, std::vector<bool>(columIndex, false));
    }

    if(columIndex+input.size() > board.at(0).size()){
        for (unsigned int i = 0 ; i < board.size() ; i++){
            board.at(i).resize(columIndex+input.length()+100, '_');
            boolBoard.at(i).resize(columIndex+input.length()+100, false);
        }    
    }

    if(dir == Direction::Horizontal){
        for(auto& index : charInput){
            board.at(rowIndex).at(columIndex) = index;
            boolBoard.at(rowIndex).at(columIndex) = true;
            columIndex++;
            
        }

  
    }

    if(dir == Direction::Vertical){
        for(auto& index : charInput){
            board.at(rowIndex).at(columIndex) = index;
            boolBoard.at(rowIndex).at(columIndex) = true;
            rowIndex++;
        }
        
    }
}

string ariel::Board::read(unsigned int rowIndex, unsigned int columIndex, Direction dir, unsigned int length){

    string output = "";

    if(dir == Direction::Horizontal){
        for(unsigned int i = columIndex; i < columIndex+length; i++){
           output += board.at(rowIndex).at(i);
        }
    }

    if(dir == Direction::Vertical){ 
        for(unsigned int i = rowIndex; i < rowIndex+length; i++){
            output += board.at(i).at(columIndex); 
        }
    }
    return output;
}

void ariel::Board::show(){
    
    unsigned int top = boolBoard.size();
    unsigned int bottom = boolBoard.size()+1;
    unsigned int left = boolBoard.at(0).size();
    unsigned int right = boolBoard.at(0).size()+1; 


    
    for (unsigned int i = 0; i < boolBoard.at(0).size(); i++){
        bool fromTop = true;
        bool fromBottom = true;
        for (unsigned int j = 0; j < boolBoard.size() && (fromTop == true || fromBottom == true); j++){
            
            if(boolBoard.at(j).at(i) == true && fromTop == true){
                if(top == boolBoard.size() || top > j){
                    top = j;
                    fromTop = false;
                }
            }

            if(boolBoard.at(boolBoard.size()-j-1).at(i) == true && fromBottom == true){
                if(bottom == boolBoard.size()+1 || bottom < boolBoard.size()-j-1){
                    bottom = boolBoard.size()-j-1;
                    fromBottom = false;
                }    
            }
        }
    }

    for (unsigned int i = 0; i < boolBoard.size(); i++){
        bool fromLeft = true;
        bool fromRight = true;
        for (unsigned int j = 0; j < boolBoard.at(i).size() && (fromLeft == true || fromRight == true); j++){
            
            if(boolBoard.at(i).at(j) == true && fromLeft == true){
                if(left == boolBoard.at(0).size() || left > j){
                    left = j;
                    fromLeft = false;
                }
            }

            if(boolBoard.at(i).at(boolBoard.size()-j-1) == true && fromRight == true){
                if(right == boolBoard.at(0).size()+1 || right < boolBoard.at(i).size()-j-1){
                    right = boolBoard.size()-j-1;
                    fromRight = false;
                }    
            }
        }
    }

    top--;
    bottom++;
    left-=2;
    right+=2;


    for(unsigned int i = top; i <= bottom; i++){    
        cout << i << ":" <<"\t";

        for(unsigned int j = left; j <= right; j++){
            cout << board.at(i).at(j);
        }

        cout << endl;
    }
}