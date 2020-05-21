//
//  Dictionary.cpp
//  Boggle
//
//  Created by JeongMinsol on 3/15/20.
//  Copyright © 2020 Minsol Jeong. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <iostream>
#include "Dictionary.h"

using namespace std;

Dictionary:: Dictionary(){
    root = new Node;
    numWords=0;
}

Dictionary:: Dictionary(string fname){
    ifstream dict;
    string vocab;
    dict.open(fname);
    
    root = new Node();
    numWords = 0;
    
    //As soon as open the file, add all the words into the dictionary tree
    while(dict>>vocab){
        addWord(vocab);
        numWords++;
    }
}

void Dictionary:: addWord(string word){
    
    Node* currNode;
    currNode = root;
        
    for (int i =0; i < word.length(); i++){
       char ch = word[i];
        //Index represents of alphabet in order
        int index = ((int) ch - (int)'a');
        
        //When there has no path for a specific location of alphabet in a word, create a new node
        if (currNode != nullptr && currNode -> letters[index] == NULL){
            currNode -> letters[index] = new Node();
            if (currNode->isWord == true)
                continue;
            else
                currNode -> isWord = false;
        }
        //When there has a path, move to the next alphabet
        currNode = currNode -> letters[index];
    }
    //Once add a word, it reachs the end of alphabet in the word. Turn the isWord flag into True
    currNode->isWord = true;
}

bool Dictionary:: isWord(string word){
    
    Node* curr = root;
    
    //Check if it is prefix
    for (int a = 0; a < word.length(); a++){
        char ch = word[a];
        int index = (int)ch - (int)'a';
        if (curr -> letters[index] == NULL) //means there is no path for the current letter
            return false;                   //return false instantly.
        else
            curr = curr -> letters[index];
    }
        //If it is prefix, check if it is a word in the dictionary.
        if (curr->isWord)
            return true;
        else
            return false;

    
}

bool Dictionary:: isPrefix(string word){
    
    Node* curr = root;
    
    //Check the path if every single alphabet in the word exist accordingly.
    for (int a = 0; a < word.length(); a++){
        char ch = word[a];
        int index = (int)ch - (int)'a';
        if (curr -> letters[index] == NULL) //means there is no path for the current letter
            return false;                   //return false instantly.
        else
            curr = curr -> letters[index];
    }
    return true;
    
}

int Dictionary:: wordCount(){return numWords;}  // return the number of words



