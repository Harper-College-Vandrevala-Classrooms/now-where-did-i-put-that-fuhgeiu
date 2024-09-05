#include "stirnclass.hpp"
#include <iostream>

void getandstore (cstd::string mystring) {


    mystring.setstring();                               // set pass in a const char pointer

}

int main () {

    cstd::string *mystring = new cstd::string;

    void getandstore (mystring);


    for (int i = 0; i < mystring->length(); i++) {

        std::cout << mystring[i];
    }

    mystring->length();
}