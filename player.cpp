#include <string>
#include <iostream>
#include "player.h"
using namespace std;

Player::Player(){
	username = " ";
	password = " ";
	score = 0;
}

Player::Player(string u, string p, int s){
	username = u;
	password = p;
	score = s;
}

void Player::setUsername(string u){
	username = u;
}

void Player::setPassword(string p){
	password = p;
}

void Player::setScore(int s){
	score = s;
}

string Player::getUsername(){
	return username;
}

string Player::getPassword(){
	return password;
}

int Player::getScore(){
	return score;
}

void Player::printPlayer(){
	cout << "Username: " << username << endl;
	cout << "Password: " << password << endl;
	cout << "Score: " << score << endl;
}