#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Node {
    Node* letters[26];
    bool isWord;
};

class Dictionary
{
public:
	Dictionary();
    //Constructor #1 - basic
	Dictionary(string file);
    //Constructor #2 - When they have a dictionary file

    void addWord(string word);
    //Function: Add words into tree by reading a file
    //Pre: Create a constructor#2 && have a dictionary file
    //post: Create a node accordingly
    
	bool isWord(string word);
    //Function: See if the word in the dictionary tree
    //Pre: Completed reading a dictionary file && add all the words from file into the dictionary tree
    //Post: True when it is word otherwise, False
    
	bool isPrefix(string word);
    //Function: See if there is a node for prefix
    //Pre: Completed reading a dictionary file && add all the words from file into the dictionary tree
    //Post: True when there is a node for prefix (doesn't have to be a word), false otherwise
    
	int wordCount();
    //Function: count all the words saved from the dictionary file
    //Pre: Completed reading a dictionary file && add all the words from file into the dictionary tree
    //Post: Return total number of words

private:
	Node* root;
	int numWords;
};

