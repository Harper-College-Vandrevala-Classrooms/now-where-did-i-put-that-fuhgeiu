#include "stirnclass.hpp"
#include <iostream>
#include <cassert>

void getandstore (cstd::string &mystring) {


    mystring.setstring("foo");                               // set pass in a const char pointer

}

int main () {

    cstd::string *mystring = new cstd::string;

    getandstore(*mystring);

    cstd::string input("foo");

    assert(mystring->locate(input) == 1);                        // found, passing object

    assert(mystring->locate("foo") == 1);               // found, passing string literal
    assert(mystring->locate("foo0") == -1);             // not found, input is greater than the string itself

    mystring->setstring("fo");                                  // change string of input

    assert(mystring->locate(input) == -1);                       // not found, pass object


}