#pragma once
#include "LibraryItem.h"
#include <iostream>
using namespace std;

class Books : public LibraryItem
{
private:
	string author;
	int numPages;
public:
	void setAuthor(string a) {
		author = a;
	}

	void setnumPages(int a) {
		numPages = a;
	}

	void print() {
		cout <<
			"-------------------------- \n" <<
			"Type: " << type << "\n" <<
			"Title: " << title << "\n" <<
			"ID: " << id << "\n" <<
			"Year: " << year << "\n" <<
			"Author: " << author << "\n" << 
			"Number of pagesL " << numPages << "\n" << endl;
	}

	Books();
	~Books();
};

