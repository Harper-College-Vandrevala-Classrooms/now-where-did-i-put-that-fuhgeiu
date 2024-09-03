#include <iostream>
#include "classcustvar_template.hpp"


void getstring(mystd::contblock mycont) {                     // getstring will take stream buffer and assign into a container

    std::string tempstring;                               // temp variable, destroy after function

    std::cout << "enter a sentence\n";                    // prompt

    std::getline(std::cin,tempstring);              // stream into temporary string

    mycont.storeblock(tempstring);                                  // take and store string into container block
}




int main () {

// for object not using template class
using namespace cstd;
{
    mydata *cvar1 = new mydata;       // allocate memory and return adress for object(cvar1)

    cvar1->change(3);                 // (->) will deference cvar1 as it is a pointer.

    (*cvar1).change(3);               // deferecne pointer, we need object name and not its adress
}



// for object using a template class, as example, will be used as a user defined data type

    mydataT<5,int> mycont0;                           // new obkect based on class using template

    mycont0.size();                                   // return size as int

    mycont0[2];                                       // pass by refernce index of array



// start of actual program

    std::cout << "enter a sentence\n";         // prompt user

    void temp ();                              // get string and size

    mystd::contblock *mycont = new mystd::contblock;          // create object for container heap

    getstring(*mycont);                  // get string and store into custom container

    mycont->find ();                                   // to find and return search
}



