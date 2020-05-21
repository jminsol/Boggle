//
//  Boggle Solver.hpp
//  Boggle
//
//  Created by JeongMinsol on 4/2/20.
//  Copyright © 2020 Minsol Jeong. All rights reserved.
//

#ifndef Boggle_Solver_hpp
#define Boggle_Solver_hpp

#include <stdio.h>
#include "Dictionary.h"

//Global constant for board size 4*4
const int COL_SIZE =4;
const int ROW_SIZE =4;

struct answers {
    string word;
    int path[4][4];
};


class BoggleSolver{
public:
    BoggleSolver(Dictionary dict, char userboard[][COL_SIZE]);
    //constructor with dictionary and user made board
    
    void printWords(int path[][COL_SIZE], char board[][COL_SIZE]);
    //Function: Mark down all the element from the key and the path for the key
    //Pre: 1.Created a constructor, 2.Searched the keys
    //Post: print the marked down elements for the word and the path
    
    void SolveBoard(bool print);
    //Function: print the keys depends on user choice
    //Pre: 1. Created a constructor, 2. user input whethere the person wants to see the board or not
    //Post: 1.Find all the keys and paths and save them in a vector 2. Call printwords to print results
    
    void SearchForWord(int r, int c, int step, int stepBoard [][COL_SIZE], string str, char board[ROW_SIZE][COL_SIZE], Dictionary dict, vector<answers> &keys);
    //Function: Serve for SolveBoard, Search all the possible words by calling recursive function
    //Pre: Called by SolveBoard
    //Post: Save a key and a path for the key in a vector
    
    bool isSafe(int r, int c, int stepBoard[][4]);
    //Function: Serve for SearchForWord, Tell if you can call recursive function or not
    //Pre: Called by SearchForWord
    //Post: Return true if row and column are within board and haven't been the path, otherewise, false.
    
private:
    char board[ROW_SIZE][COL_SIZE];
    Dictionary dictionary;
};

#endif /* Boggle_Solver_hpp */
