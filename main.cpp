#include <iostream>
#include "classcustvar_template.hpp"


template <typename T>
void print (const cstd::contdynamic<T>& Contdynamic){

    for (size_t i = 0; i < Contdynamic.Size(); i++){
        std::cout << Contdynamic[i] << std::endl;
    }
}


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
//    contdynamic *cvar1 = new contdynamic;       // allocate memory and return adress for object(cvar1)
//
//    cvar1->change(3);                 // (->) will deference cvar1 as it is a pointer.
//
//    (*cvar1).change(3);               // deferecne pointer, we need object name and not its adress
//



    contdynamic <std::string> Contdynamic;

    Contdynamic.append("myslef");
    Contdynamic.append("tom");
    Contdynamic.append("by");

    print(Contdynamic);

}


// start of actual program

    std::cout << "enter a sentence\n";         // prompt user

    void temp ();                              // get string and size

    mystd::contblock *mycont = new mystd::contblock;          // create object for container heap

    getstring(*mycont);                  // get string and store into custom container


}



