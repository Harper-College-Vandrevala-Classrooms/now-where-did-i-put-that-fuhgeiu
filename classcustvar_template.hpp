#include <iostream>

// notes, this library will contain class and members and templates that are not used in every project
// this is my library i will use and expand in projects to learn

/*
 * contents
 *
 * class template for array like container, container (0)
 *
 *
 *
 * class for project
 *
 *
 * class template to read stream buffer and store into container (0)
 *
 *
 */

// mem adress 7f = in stack on 64bit system

template<int S,typename T>                  // <size of container, data type>
class mydataT {

    T m_fixedcont[S];                           // stack array, dynamic at compile time
    int* my_heaparray = new T[S];           // heap array, return pointer to mem spot

public:

    mydataT() {};                            // constructor

    int size() const {return S;}             // returns size as an int

    T& operator[](int index) {return m_fixedcont[index];}           // return refernce
    const T& operator[](int index) const {return m_fixedcont[index];}           // for use if array is const

    T* arraypointer () { return m_fixedcont; }                                  // return pointer to array

//    void getsay();
};

//template<int S, typename T> void mydataT<S,T>::getsay(){}




namespace cstd {

class mydata {

    int *ptrcont;                     // pointer to start of container


public:

    mydata() {};                   // default constructor

    void change(int T);            // member decleration

    void temp();                   // member decleration, output pointer

    template<typename T> void locate(T x);      // member decleraiton using template

};


void mydata::change (int t){

    *ptrcont = t;
}


void mydata::temp(){

    std::cout << *ptrcont;
}


template <typename T> void mydata::locate(T x){         // member definition using template

    std::cout << x;

    std::cout << *ptrcont;
}




namespace mystd{


class contblock {

    int* ptrcont;





public:

    contblock() { };

    void storeblock(std::string);

    int find ();

    int locate();

};

int contblock::locate() {



}



void storeblock(std::string tempstring) {                                    // store string into array template class

    tempstring.size();





}

int find () {





}


}



