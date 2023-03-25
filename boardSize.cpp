#include <iostream>
#include <string>
#include "boardSize.h"
using namespace std;

string boardSize() {
	string size;
	int selection;
	bool valid = false;
	
	while (!valid) {
		cout << "Board Size:\nSmall(1)\tMedium(2)\tLarge(3)\nSelection: ";
		cin >> selection;
	
		switch(selection)
		{
			case 1:
				size = "5x5";
				valid = true;
				break;
			case 2:
				size = "7x7";
				valid = true;
				break;
			case 3:
				size = "9x9";
				valid = true;
				break;
			default:
				cout << "Invalid selection\n";
		}
	}
	
	return size;
}
