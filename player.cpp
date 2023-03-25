#include <string>
#include <vector>
#include <iostream>
#include "player.h"
using namespace std;

Player::Player(){
	username = " ";
	password = " ";
	highScore = 0;
	scores.push_back(0);
}

Player::Player(string u, string p, int s){
	username = u;
	password = p;
	scores.push_back(s);
	highScore = s;
}

void Player::setUsername(string u){
	username = u;
}

void Player::setPassword(string p){
	password = p;
}

void Player::addScore(int s){
	scores.push_back(s);
	updateHighScore();
}

void Player::updateHighScore(){
	for(int i = 0; i < scores.size(); i++){
		if (scores[i] > highScore){
			highScore = scores[i];
		}
	}
}

string Player::getUsername(){
	return username;
}

string Player::getPassword(){
	return password;
}

int Player::getHighScore(){
	return highScore;
}

void Player::printPlayer(){
	cout << "Username: " << username << endl;
	cout << "Password: " << password << endl;
	cout << "High Score: " << highScore << endl;
}
