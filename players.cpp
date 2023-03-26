#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include "player.h"
#include "players.h"
using namespace std;

Players::Players(){
	playercount = 0;
}

Players::Players(int c){
	playercount = c;
}

int Players::getCount(){
	return playercount;
}

void Players::addPlayer(){
	string u;
	string p;
	int s;
	Player *add;
	
	cout << "Enter the player's name: ";
	getline(cin, u);
	cout << "Enter the player's password: ";
	getline(cin, p);
	cout << "Enter the player's score: ";
	cin >> s;
	cin.ignore();
	
	add = new Player(u, p, s);
	playerlist.push_back(add);
	playercount++;
}

Player* Players::searchPlayer(string user){
	Player *find;
	for (unsigned int i = 0; i < playercount; i++){
		if (playerlist.at(i)->getUsername() == user){
			return playerlist.at(i);
		}
		else{
			cout << "Player is not found in the list" << endl;
		}
	}	
}
	
void Players::editPlayer(string user){
	Player *edit;
	string change;
	char choice = 'y';
	
	for (unsigned int i = 0; i < playercount; i++){
		if (playerlist.at(i)->getUsername() == user){
			cout << "What do you want to edit?(username, password, score): ";
			cin >> change;
			cin.ignore();
			while (choice != 'n'){
				if (change == "username"){
					string u;
					cout << "Enter the new player's username: ";
					getline(cin, u);
					playerlist.at(i)->setUsername(u);
				}
				else if (change == "password"){
					string p;
					cout << "Enter the new player's password: ";
					getline(cin, p);
					playerlist.at(i)->setPassword(p);
				}
				else if (change == "score"){
					int s;
					cout << "Enter the new player's score: ";
					cin >> s;
					cin.ignore();
					playerlist.at(i)->addScore(s);
				}
				cout << "Do you want to keep editing?(y/n) "; 
				cin >> choice; cin.ignore();
				if (choice == 'y'){
					cout << "What do you want to edit?(username, password, score): ";
					cin >> change;
				}
			}
		}
		else{
			cout << "Player is not found in the list" << endl;
		}
	}
}
	
void Players::deletePlayer(string user){
	Player *del;
	
	for (unsigned int i = 0; i < playercount; i++){
		if (playerlist.at(i)->getUsername() == user){
			playerlist.erase(playerlist.begin() + i);
			playercount--;
		}
		else{
			cout << "Player is not found in the list" << endl;
		}
	}
}

void Players::printPlayerData(string user){
	
	for (unsigned int i = 0; i < playercount; i++){
		if (playerlist.at(i)->getUsername() == user){
			playerlist.at(i)->printPlayer();
		}
		else{
			cout << "Player is not found in the list" << endl;
		}
	}
}

void Players::printPlayerlist(){
	
	for (unsigned int i = 0; i < playercount; i++){
		playerlist.at(i)->printPlayer();
		cout << endl;
	}
}
	
void Players::storePlayer(){
 
    ofstream fout;
    fout.open("players.dat");
    fout << playercount << endl;
    
    Player *temp;
   for (auto it = playerlist.begin(); it !=playerlist.end(); ++it)
    {
        temp= *it;
        fout << temp->getUsername() << " " << temp->getPassword() << " " << temp->getHighScore() << endl;
    }
    fout.close();
}

void Players::loadPlayer(){
	
	ifstream fin;
    string u;
	string p;
	int s;
    fin.open("players.dat");
    fin >> playercount; fin.ignore();
    
    for ( int i=0; i < playercount; i++)
    {
        
        fin >> u >> p >> s;
        playerlist.push_back( new Player(u, p, s));
    }
    fin.close();
}

void Players::cleanup(){
       for (auto it = playerlist.begin(); it !=playerlist.end(); ++it)
    {
        
        delete *it;
    }
    playerlist.clear();
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	