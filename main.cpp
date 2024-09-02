#include <iostream>
#include "classcustvar_template.hpp"


void getstring(mystd::custstring mycont) {                     // getstring will take stream buffer and assign into a container

    std::string tempstring;                               // temp variable, destroy after function

    std::cout << "enter a sentence\n";                    // prompt

    std::getline(std::cin,tempstring);              // stream into temporary string



    for (char c : tempstring) {                    // itterate over string and store value to my container

        mycont

    }

}


int find () {




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



// start

    mystd::custstring mycont;                // create obejct similar to string

    std::cout << "enter a sentence\n";         // prompt user

    getstring(mycont);                  // get string and store into custom container

    find ();                                   // to find and return search
}



