#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
using namespace std;

class Player{
	public:
		Player();
		Player(string u, string p);
		Player(string u, string p, int s);
		void setUsername(string n);
		void setPassword(string p);
		void addScore(int s);
		string getUsername();
		string getPassword();
		int getHighScore();
		void printPlayer();
		
	private:
		string username;
		string password;
		vector<int> scores;
		int highScore;
};

#endif
