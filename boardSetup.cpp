#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "boardSetup.h"
using namespace std;

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
