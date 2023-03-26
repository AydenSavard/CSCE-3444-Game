#include <iostream>
#include <string>
#include <vector>
#include "boardSetup.h"
#include "boardSize.h"
#include "player.h"
#include "players.h"
using namespace std;

int main(){

    vector<vector<int>> board;
	string bSize = boardSize();//format for the size of the board
    boardSetup(bSize, board);

    return 1;
}
