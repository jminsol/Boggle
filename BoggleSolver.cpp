#include "Dictionary.h"

bool verbose = false;
int numWords = 0;
void SolveBoard(string board[4][4], Dictionary& dict, Dictionary& wordsFound, bool printBoard);

int main()
{
	string board[4][4];

	Dictionary dict("C:\\PathToDictionary\\dictionary.txt");
	cout << dict.wordCount() << " words loaded." << endl << endl;

	// Below is some code to help you test your dictionary...
	/*
	string word;
	while (true) {
		cout << "Enter string: ";
		cin >> word;

		if (dict.isWord(word)) {
			cout << word << " is a valid word" << endl;
		}
		else {
			cout << word << " is NOT a valid word" << endl;
		}

		if (dict.isPrefix(word)) {
			cout << word << " is a valid prefix" << endl;
		}
		else {
			cout << word << " is NOT a valid prefix" << endl;
		}

		cout << endl;
	}
	*/

	Dictionary wordsFound;
	SolveBoard(board, dict, wordsFound, true);

    return 0;
}


void SolveBoard(string board[4][4], Dictionary& dict, Dictionary& wordsFound, bool printBoard) {



	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			//Initial calls to SolveBoardHelper
		}
	}
}

/*
 * You will need methods for SolveBoardHelper, printing the board, etc
 */