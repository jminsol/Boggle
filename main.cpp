//
//  main.cpp
//  Boggle
//
//  Created by JeongMinsol on 3/15/20.
//  Copyright © 2020 Minsol Jeong. All rights reserved.
//

#include "Boggle_Solver.hpp"
#include <iostream>
#include <sstream> // stringstream
#include <string> // to_string

using namespace std;

int main(){
    
    Dictionary test;
    
    test=Dictionary("Dictionary.txt");
    cout << test.wordCount() << " words loaded" << endl;
    
    
    char boggle[ROW_SIZE][COL_SIZE];
    string row;
    stringstream elements;
    
    cout<< "Enter Board"<<endl;
    cout <<"-----------" << endl;

    //Receive boggle board from a user
    for (int r =0; r < ROW_SIZE; r++){
        cout<< "Row " << r << ": ";
        getline(cin,row);
        stringstream elements;
        elements.str(row);
        for (int c = 0; c < COL_SIZE; c++)
            elements >> boggle[r][c];
    }
    
    //Create a constructor for keys
    BoggleSolver keys = BoggleSolver(test, boggle);
    char input;
    bool print = false;
    
    //Ask a user if the individual wants to see the path for the key or only keys
    cout << "Show board (y/n)?: ";
    cin >> input;
    
    if (input == 'y' || input == 'Y'){
        print = true;
        keys.SolveBoard(print);
    }
    else
        keys.SolveBoard(print);
    

    
    return 0;
}
 

