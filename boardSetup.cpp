#include <iostream>
#include <string>
#include <vector>
#include "boardSetup.h"
using namespace std;

void boardSetup(string bSize){//creates a board of the given size filled with 'e's
    vector<vector<char>> board;
    int rows = bSize.at(0)-48;
    int coll = bSize.at(2)-48;
    cout << rows << "x" << coll << endl;//outputs board size
    
    for(int i=0; i<rows;i++){//creating the e board
        vector<char> empt;
        for(int j=0; j<coll;j++){
            empt.push_back('e');
        }
        board.push_back(empt);
    }

    for(int i=0; i<board.size();i++){//outputs the board, can be removed if not needed
        for(int j=0; j<board[i].size();j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}