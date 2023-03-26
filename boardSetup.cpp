#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "boardSetup.h"
using namespace std;

string boardSize() {
	int selection;
	
	while (true) {
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
				return "5x5";
				break;
			case 2:
				return "7x7";
				break;
			case 3:
				return "9x9";
				break;
			default:
				cout << "\nInvalid selection\n" << endl;
		}
	}
}

void boardSetup(string bSize, vector<vector<int>> &board){//creates a board of the given size filled with '1s and 2s's
    srand(time(nullptr));
	
	int rows;
	int coll;
	int random;
	int random2;
	if (bSize.length() == 3) {
		rows = bSize.at(0)-48;
		coll = bSize.at(2)-48;
	}
	else {
		rows = stoi(bSize.substr(0, 2));
		coll = stoi(bSize.substr(3, 2));
	}
    cout << rows << "x" << coll << endl;//outputs board size
    
    for(int i=0; i<rows;i++){//creating the board of 1s and 2s
        vector<int> empt;
        for(int j=0; j<coll;j++){
            random = rand() % 2 + 1;
			empt.push_back(random);
        }
        board.push_back(empt);
    }
	random = rand() % rows;
	random2 = rand() % coll;
	board[random][random2] = 3;	//adding the "player"
	
	random = rand() % rows;
	random2 = rand() % coll;
	board[random][random2] = 4;	//adding the "exit"

    for(int i=0; i<board.size();i++){//outputs the board, can be removed if not needed
        for(int j=0; j<board[i].size();j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
