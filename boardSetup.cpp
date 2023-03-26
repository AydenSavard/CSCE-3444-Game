#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "boardSetup.h"
using namespace std;

string boardSize() {
	string size;
	int selection;
	bool valid = false;
	
	while (!valid) {
		cout << "Board Size:\nSmall(1)\tMedium(2)\tLarge(3)\nSelection: ";
		while(!(cin >> selection))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nInvalid selection\n" << endl;
		cout << "Board Size:\nSmall(1)\tMedium(2)\tLarge(3)\nSelection: ";
	}
	
		switch(selection)
		{
			case 1:
				size = "5x5";
				valid = true;
				break;
			case 2:
				size = "7x7";
				valid = true;
				break;
			case 3:
				size = "9x9";
				valid = true;
				break;
			default:
				cout << "\nInvalid selection\n" << endl;
		}
	}
	
	return size;
}

void boardSetup(string bSize, vector<vector<int>> &board){//creates a board of the given size filled with '1s and 2s's
    srand(time(nullptr));
	
	int rows = bSize.at(0)-48;
    int coll = bSize.at(2)-48;
    cout << rows << "x" << coll << endl;//outputs board size
    
    for(int i=0; i<rows;i++){//creating the board of 1s and 2s
        vector<int> empt;
        for(int j=0; j<coll;j++){
            empt.push_back(rand() % 2 + 1);
        }
        board.push_back(empt);
    }
	board[rand() % rows][rand() % coll] = 3;	//adding the "player"
	board[rand() % rows][rand() % coll] = 4;	//adding the "exit"

    for(int i=0; i<board.size();i++){//outputs the board, can be removed if not needed
        for(int j=0; j<board[i].size();j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
