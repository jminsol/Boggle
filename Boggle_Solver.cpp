//
//  Boggle Solver.cpp
//  Boggle
//
//  Created by JeongMinsol on 4/2/20.
//  Copyright © 2020 Minsol Jeong. All rights reserved.
//

#include "Boggle_Solver.hpp"
#include <vector>
#include <iostream>

using namespace std;

//Constructor
BoggleSolver::BoggleSolver(Dictionary dict, char userboard[][COL_SIZE]){
    dictionary = dict;
    for (int i = 0; i < ROW_SIZE; i ++)
        for (int j = 0; j < COL_SIZE; j++)
            board[i][j] = userboard[i][j];
}

void BoggleSolver:: SolveBoard(bool print){
    
    int i, j; //i for current row number & j for current column number
    int count =0;
    int step =1;
    vector<answers> words;
    int visited[ROW_SIZE][COL_SIZE] = {0};
    string str="";
    
    for (i = 0; i < ROW_SIZE; i++){
        for(j=0; j < COL_SIZE; j++){
            SearchForWord(i, j, step, visited, str, board, dictionary, words);
        }
    }
    //Depending on print type, print the board or not
    if (print){
        for(auto it = words.begin(); it != words.end(); it++){
            cout << "Word: " << it->word << endl;
            cout << "Number of Words: " << ++count << endl;

            printWords(it->path, board);
            }
    }
    else
    {
         for(auto it = words.begin(); it != words.end(); it++)
             cout << ++count << "\t" << it->word <<endl;
    }
    }


void BoggleSolver:: SearchForWord(int r, int c, int step, int stepBoard[][4], string str, char board [][4], Dictionary dict, vector<answers>& words){
    
    stepBoard[r][c] = step;
    step++;
    str = str + board[r][c];
    
    //1st case: it's the unique word 2nd case: A word can be both a word and prefix for another word
    if (dict.isWord(str) || (dict.isWord(str) && dict.isPrefix(str))){
        
        answers key;
        key.word = str;
        for (int rr =0; rr < ROW_SIZE; rr++){
            for (int cc=0; cc<COL_SIZE; cc++)
                key.path[rr][cc]=stepBoard[rr][cc];
        }
        words.push_back(key);
        
        //Case2: explore more words which include this word as a prefix
        if (dict.isWord(str) && dict.isPrefix(str)){
            if(isSafe(r+1, c, stepBoard)&&dict.isPrefix(str))   //up&down both sides
                SearchForWord(r+1, c, step, stepBoard, str, board, dict, words);
            if(isSafe(r, c+1, stepBoard)&&dict.isPrefix(str))
                SearchForWord(r, c+1, step, stepBoard, str, board, dict, words);
            if(isSafe(r-1, c, stepBoard)&&dict.isPrefix(str))
                SearchForWord(r-1, c, step, stepBoard, str, board, dict, words);
            if(isSafe(r, c-1, stepBoard)&&dict.isPrefix(str))
                SearchForWord(r, c-1, step, stepBoard, str, board, dict, words);
            if(isSafe(r-1, c-1, stepBoard)&&dict.isPrefix(str)) //diagnoal
                SearchForWord(r-1, c-1, step, stepBoard, str, board, dict, words);
            if(isSafe(r-1, c+1, stepBoard)&&dict.isPrefix(str))
                SearchForWord(r-1, c+1, step, stepBoard, str, board, dict, words);
            if(isSafe(r+1, c-1, stepBoard)&&dict.isPrefix(str))
                SearchForWord(r+1, c-1, step, stepBoard, str, board, dict, words);
            if(isSafe(r+1, c+1, stepBoard)&&dict.isPrefix(str))
                SearchForWord(r+1, c+1, step, stepBoard, str, board, dict, words);
        }
    
    }
    //Case3: Look for other position. See the 8 directions
    else{
        //UP & Right & Down & Left
        if(isSafe(r+1, c, stepBoard)&&dict.isPrefix(str))
            SearchForWord(r+1, c, step, stepBoard, str, board, dict, words);
        if(isSafe(r, c+1, stepBoard)&&dict.isPrefix(str))
            SearchForWord(r, c+1, step, stepBoard, str, board, dict, words);
        if(isSafe(r-1, c, stepBoard)&&dict.isPrefix(str))
            SearchForWord(r-1, c, step, stepBoard, str, board, dict, words);
        if(isSafe(r, c-1, stepBoard)&&dict.isPrefix(str))
            SearchForWord(r, c-1, step, stepBoard, str, board, dict, words);
        
        //Diagnol directions
        if(isSafe(r-1, c-1, stepBoard)&&dict.isPrefix(str))
            SearchForWord(r-1, c-1, step, stepBoard, str, board, dict, words);
        if(isSafe(r-1, c+1, stepBoard)&&dict.isPrefix(str))
            SearchForWord(r-1, c+1, step, stepBoard, str, board, dict, words);
        if(isSafe(r+1, c-1, stepBoard)&&dict.isPrefix(str))
            SearchForWord(r+1, c-1, step, stepBoard, str, board, dict, words);
        if(isSafe(r+1, c+1, stepBoard)&&dict.isPrefix(str))
            SearchForWord(r+1, c+1, step, stepBoard, str, board, dict, words);
    }
    stepBoard[r][c] = 0;
    step--;
}

bool BoggleSolver::isSafe(int r, int c, int (*stepBoard)[4]){
    
    return ( r < ROW_SIZE && r >= 0 && c < COL_SIZE && c >= 0 && stepBoard[r][c] == 0);
    
}

//Print the marked down board on the left, path on the right
void BoggleSolver::printWords(int path[4][COL_SIZE], char board[][COL_SIZE]){

    for (int r = 0; r < ROW_SIZE; r++)
        for(int c=0; c< COL_SIZE; c++){
            if(path[r][c]!= 0)
                cout<< "'" << board[r][c] << "'";
            else
                cout <<" " << board[r][c] << " ";
            
            if (c == 3)
                cout << "\t" << path[r][0] << " " << path[r][1] << " " << path[r][2] << " " << path[r][3] << endl;
        }
    
}
