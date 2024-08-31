#include <iostream>
#include "classcustvar_template.hpp"
#include "classcustvar.hpp"




void getinput () {

    std::cout << "enter sequence\n";                // user prompt

    cstd::getandstoreinput();                         // get user input and store in object
}


int main () {

    int* ptr2 = new int;                // allocate memory for int

// for object not using template class
using namespace cstd;
{
    mydata *cvar1 = new mydata;       // allocate memory and return adress for object(cvar1)

    getinput();                       // get user input and store in object



    cvar1->change(3);                 // (->) will deference cvar1 as it is a pointer.

    (*cvar1).change(3);               // deferecne pointer, we need object name and not its adress

    locate(6);


    temp();
}




// for object using a template class

    mydataT<5,int> myarray;                           // new obkect based on class using template

    myarray.size();                                   // return size as int

    myarray[2];                                       // pass by refernce index of array

    myarray.getsay(4);                                     // get strings and store in object

    int *container = new int[10];       // new container of 10 spots sequentially (array)

}

// idea

// use stream buffer and store in a sequential container of my design

// iterate through container and find the first letter of quiry
//      if quiry is more than a char, than iterate from the first location and check
//      if iterator reaches end of container without a match than return -1


// my user defined data type, can input multiple strings into a single object
//    can use member fucntion to specifiy the string name
