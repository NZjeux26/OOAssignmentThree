#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "LibraryItem.h"
#include "Movie.h"
#include "Books.h"
#include "Journals.h"
using namespace std;

void displayInfo() {
    cout << "--------------------------------------" << endl;
    cout << "Assignment 3, 159.234 Semester 1 2021" << endl;
    cout << "Submitted by: Brown, Phillip 21011867" << endl;
    cout << "--------------------------------------" << endl;
}//Displays Student information

static vector<Movie> movielist;
static vector<Books> booklist;//global vectors for access in all methods
static vector<Journals> journallist;

//function declartions
void displayRaw(vector<string> holdpen);
void mainMenu();
void otherMainmenu(string input);
void idSearch(string input);
void titleSearch();

int main(int argc, char** argv)
{
    vector<string> holdpen;
    string data;
    
    //File reader.
    ifstream input_file;
    if (!input_file) {
        cout << "Error, File cannot be found" << endl;
    }
    input_file.open("library.txt");
   
    while (!input_file.eof()) {
        getline(input_file, data);
        holdpen.push_back(data);
    }
    displayInfo();
    displayRaw(holdpen);
    mainMenu();
}

void displayRaw(vector<string> holdpen) {
   //Takes the holdpen items, spilts the strings into intervidual aprts and makes them the respective objects  
    int count = holdpen.size();
    for (int i = 0; i < holdpen.size(); i++) {
        vector<string> result;
        stringstream s_stream(holdpen[i]);
        while (s_stream.good()) {//used to spilt the string by commas, pushes to a new holding vector which is used by the if/elseif chain
            string substr;
            getline(s_stream, substr, ',');
            result.push_back(substr);
        }

        if (result[0] == "Movie") {
            Movie movie;
            movie.type = result[0];
            movie.id = stoi(result[1]);
            movie.title = result[2];
            movie.year = stoi(result[3]);
            movie.setDirector(result[4]);
            movielist.push_back(movie);
            movie.print();
        }  

        else if (result[0] == "Book") {
            Books book;
            book.type = result[0];
            book.id = stoi(result[1]);
            book.title = result[2];
            book.year = stoi(result[3]);
            book.setAuthor(result[4]);
            book.setnumPages(stoi(result[5]));
            booklist.push_back(book);
            book.print();
        }

        else if (result[0] == "Journal") {
            Journals journal;
            journal.type = result[0];
            journal.id = stoi(result[1]);
            journal.title = result[2];
            journal.year = stoi(result[3]);
            journal.setVolume(stoi(result[4]));
            journal.setNumber(stoi(result[5]));
            journallist.push_back(journal);
            journal.print();
        }
    } 
}

void mainMenu() {
    string input;
    cout << "" << endl;
    cout << "Enter 'q' to quit, enter 'i' to search by ID, or enter any other key to search by phrase in title" << endl;
    cin >> input;
    otherMainmenu(input);
}

void otherMainmenu(string input)
{//handles the menu options with if/elseif chain and can be called directly to a statement
    if (input == "q") {
        exit;
    }
    else if (input == "i") {
        cout << "" << endl;
        cout << "Enter ID to start search, or enter 'b' to go back to choose search method" << endl;
        cin >> input;
        if (input != "b") {
            idSearch(input);
        }
        else {
            mainMenu();
        }  
    }
    else {
        titleSearch();
    }
}

void idSearch(string input)
{   /* For searching through the respective lists for the item number being searched.
        Goes through each list one at time until it either finds what it is looking for or doesn't.
        */
    int item = 0;
    int count = 0;
    int totalObjects = booklist.size() + movielist.size() + journallist.size();

    try {
        item = stoi(input);
    }
    catch(invalid_argument){
        cout << "" << endl;
        cout << "Please enter a ID to be searched" << endl;
        otherMainmenu("i");
    }

    for (Movie value : movielist) {
        if (item == value.id) {
            value.print();
            otherMainmenu("i");
        }
        else count++;
    }
    for (Books value : booklist) {
        if (item == value.id) {
            value.print();
            otherMainmenu("i");
        }
        else count++;
    }
    for (Journals value : journallist) {
        if (item == value.id) {
            value.print();
            otherMainmenu("i");
        }
        else count++;
    }
    if (count = totalObjects) {
        cout << "" << endl;
        cout << "Cannot find the ID you are looking for, please re-enter again or try a new ID" << endl;
        otherMainmenu("i");
    }

}

void titleSearch()
{
    /*Title string search, uses string.find to find everything that DOES'T match, so you ahve to use a negative statement to get the right results
    unlike Java version, only have to print the results so cut the holding vectors and jsut stright print the item.*/
    string input;
    int count = 1;
    cout << "Enter a phrase in the title to start search, or enter 'b' to go back and choose search method" << endl;
    cin >> input;

    if (input == "b") { mainMenu(); }

    for (Movie value : movielist) {
        if (!value.title.find(input)) {
            value.print();
        }
    }

    for (Books value : booklist) {
        if (!value.title.find(input)) {
            value.print();
        }
    }

    for (Journals value : journallist) {
        if (!value.title.find(input)) {
            value.print();
        }
    }
    otherMainmenu("i");

}

