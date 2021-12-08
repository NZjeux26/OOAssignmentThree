#pragma once
#include <string>
#include <istream>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class LibraryItem
{

public:
	string type;
	string title;
	int id, year = 0;

	LibraryItem();
	~LibraryItem();
};





