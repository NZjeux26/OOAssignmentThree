#pragma once
#include "LibraryItem.h"
#include <iostream>
using namespace std;
class Journals : public LibraryItem {
private:
	int volume, number;
public:
	void setVolume(int a) {
		volume = a;
	}

	void setNumber(int a) {
		number = a;
	}

	void print() {
		cout <<
			"-------------------------- \n" <<
			"Type: " << type << "\n" <<
			"Title: " << title << "\n" <<
			"ID: " << id << "\n" <<
			"Year: " << year << "\n" <<
			"Volume: " << volume << "\n"
			"Number: " << number << "\n" << endl;
	}

	Journals();
	~Journals();
};



