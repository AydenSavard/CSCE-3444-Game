#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player{
	public:
		Player();
		Player(string u, string p, int s);
		void setUsername(string n);
		void setPassword(string p);
		void setScore(int s);
		string getUsername();
		string getPassword();
		int getScore();
		void printPlayer();
		
	private:
		string username;
		string password;
		int score;
};

#endif