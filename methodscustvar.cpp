#include <iostream>
#include "classcustvar.hpp"

using namespace std;

// method defintions

mydata::mydata (int t) {

    *ptr = t;
}


void mydata::change (int t){

    *ptr = t;
}


void mydata::temp(){

    cout << *ptr;
}