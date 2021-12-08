#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string>


class Libitem
{
protected:
    string type;
    int id = 0;
    string title;
    int year = 0;
   
public:
    Libitem();
    ~Libitem();
};

Libitem::Libitem()
{
    
}

Libitem::~Libitem()
{
}

class Movies : public Libitem
{
private:
    string sdirector;
public:
    Movies();
    ~Movies();
};

Movies::Movies()
{

}

Movies::~Movies() {

}

