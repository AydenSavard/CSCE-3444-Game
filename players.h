#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>
#include <vector>
#include "player.h"
using namespace std;

class Players{
	public:
		Players();
		Players(int c);
		int getCount();
		void addPlayer();
		void deletePlayer(string user);
		void editPlayer(string user);
		Player *searchPlayer(string user);
		void printPlayerlist();
		void printPlayerData(string user);
		void storePlayer();
		void loadPlayer();
		void cleanup();
		
	private:
		int playercount;
		vector<Player*> playerlist;
};

#endif