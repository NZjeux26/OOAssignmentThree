#pragma once
#include "LibraryItem.h"
#include <iostream>
using namespace std;

class Movie :public LibraryItem
{
private:
	string director;
public:
	void setDirector(string d) {
		director = d;
	}

	string getDirector() {
		return director;
	}

	void print() {

		cout <<
			"-------------------------- \n" << 
			"Type: " << type << "\n" <<
			"Title: " << title << "\n" <<
			"ID: " << id << "\n" <<
			"Year: " << year << "\n" <<
			"Director: " << director << "\n" << endl;
	}
	Movie();
	~Movie();
};


