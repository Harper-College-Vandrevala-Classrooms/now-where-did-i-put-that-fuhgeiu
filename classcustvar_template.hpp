#include <iostream>


template<int S,typename T>
class mydataT {

    T m_array[S];                           // stack array, dynamic at compile time

    int* my_heaparray = new T[S];           // heap array

public:

    mydataT() {};                            // constructor

    int size() const {return S;}             // returns size as an int

    T& operator[](int index) {return m_array[index];}           // return refernce
    const T& operator[](int index) const {return m_array[index];}           // for use if array is const

    T* arraypointer () { return m_array; }                                  // return pointer to array

    void getsay();
};


template<int S, typename T> void mydataT<S,T>::getsay(){


}



namespace cstd {


class mydata {

    int *ptrcont;                     // pointer to start of container

public:

    mydata() {};                   // default constructor

    void change(int T);            // member decleration

    void temp();                   // member decleration

    void getandstoreinput();

    void locate(typename T);

};


void mydata::change (int t){

    *ptrcont = t;
}


void mydata::temp(){

    std::cout << *ptrcont;
}


template <typename T> void mydata::locate(T){

    std::cout << T;
}


void getandstoreinput(){                                      // get an input and stream string into container




}



}