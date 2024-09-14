#include "str.hpp"
#include <iostream>
#include <cassert>

void getandstore (strstd::string &mystring) {

    mystring.setstring("foo bar");                               // set pass in a const char pointer

}


int main () {

    strstd::string *mystring = new strstd::string;

    strstd::string standardstring;

    getandstore(*mystring);

    strstd::string input("foo");

    assert(mystring->locate(input) == 1);             // (cstd::string)     only pass onjects
    assert(mystring->locate('f') == 1);            // (char)             only pass single quote char
    assert(mystring->locate("foo0") == -1);   // (char [])          only pass double quote string literals
    assert(standardstring.locate('g') == -1);
    assert(mystring->locate('o') == 2);
    assert(mystring->locate("o") == 2);       // (char [])         only pass double quotes string literal
    assert(mystring->locate("fo") == 1);
    assert(mystring->locate(' ') == 4);
    assert(mystring->locate("bar") == 5);

    mystring->setstring("fo");                                  // change string of input

    assert(mystring->locate(input) == -1);                       // not found, pass object


}