#include "Board.hpp"
#include "Direction.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <array>
using ariel::Direction;

unsigned int const INCREMENTOR = 100;

void ariel::Board::post(unsigned int rowIndex, unsigned int columIndex, Direction dir, string const& input){
    std::vector<char> charInput(input.begin(), input.end());

    if(rowIndex+input.size() > board.size()){
        board.resize(rowIndex+input.length()+INCREMENTOR, std::vector<char>(columIndex, '_'));
    }

    if(columIndex+input.size() > board.at(0).size()){
        for (unsigned int i = 0 ; i < board.size() ; i++){
            board.at(i).resize(columIndex+input.length()+INCREMENTOR, '_');
        }    
    }

    if(dir == Direction::Horizontal){
        for(auto& index : charInput){
            board.at(rowIndex).at(columIndex) = index;
            columIndex++;
            
        }

  
    }

    if(dir == Direction::Vertical){
        for(auto& index : charInput){
            board.at(rowIndex).at(columIndex) = index;
            rowIndex++;
        }
        
    }
}

string ariel::Board::read(unsigned int rowIndex, unsigned int columIndex, Direction dir, unsigned int length){

    string output;

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
    
    unsigned int top = board.size();
    unsigned int bottom = board.size()+1;
    unsigned int left = board.at(0).size();
    unsigned int right = board.at(0).size()+1; 


    
    for (unsigned int i = 0; i < board.at(0).size(); i++){
        bool fromTop = true;
        bool fromBottom = true;
        for (unsigned int j = 0; j < board.size() && (fromTop || fromBottom ); j++){
            
            if(board.at(j).at(i) != '_' && fromTop){
                if(top == board.size() || top > j){
                    top = j;
                    fromTop = false;
                }
            }

            if(board.at(board.size()-j-1).at(i) != '_' && fromBottom){
                if(bottom == board.size()+1 || bottom < board.size()-j-1){
                    bottom = board.size()-j-1;
                    fromBottom = false;
                }    
            }
        }
    }

    for (unsigned int i = 0; i < board.size(); i++){
        bool fromLeft = true;
        bool fromRight = true;
        for (unsigned int j = 0; j < board.at(i).size() && (fromLeft || fromRight); j++){
            
            if(board.at(i).at(j) != '_' && fromLeft ){
                if(left == board.at(0).size() || left > j){
                    left = j;
                    fromLeft = false;
                }
            }

            if(board.at(i).at(board.size()-j-1) != '_' && fromRight){
                if(right == board.at(0).size()+1 || right < board.at(i).size()-j-1){
                    right = board.size()-j-1;
                    fromRight = false;
                }    
            }
        }
    }

    if(top != 0){
        top--;
    }

    if(bottom != board.size()-1){
        bottom++;
    }

    if(left != 0 && left != 1){
        left-=2;
    }

    else if(left == 1){
        left--;
    }    


    if(right != board.size()-1 && right != board.size()-2){
        right+=2;
    }

    else if(right == board.size()-2){
        right++;
    }   
    
    if(right != board.at(0).size()+1 && top != board.size() && bottom != board.size()+1 && left != board.at(0).size()){
        for(unsigned int i = top; i <= bottom; i++){    
            cout << i << ":" <<"\t";

            for(unsigned int j = left; j <= right; j++){
                cout << board.at(i).at(j);
            }

            cout << endl;
        }
    }

    else{
        cout << "there is nothing to print because the board is empty" << endl;
    }    
}