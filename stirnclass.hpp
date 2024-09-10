#include <iostream>

namespace cstd{

// very redumentary string class
class string {

    char* m_data = nullptr;                                  // char pointer for object/container
    size_t m_size;                                          //  size in terms of unsigned int

public:

    string () {};                                           // defualt constructor

    string (const char* string) {

        setstring(string);
    }

//    ~ string (){                                            // destructor, default destructor is not good enough
//
//        delete [] m_data;                                      // delete array we allocated earlier
//    }

    const char& operator[] (size_t index) const { return *(m_data + index);}                // index return as const

    int length () { return m_size;}                                                 // returns size
    void plength () { std::cout << m_size;}                                         // prit sizd

    char& operator[] (size_t index) { return *(m_data + index);}                            // index

    void setstring (const char* string){

        m_size = strlen(string);                          // get the size of passed string
        m_data = new char[m_size];                          // allocate new memory by passing in size of space needed
        memcpy(m_data, string, m_size);          // copy (destination, source, size (number of bytes))
    }

    int locate (const char*);                                      // member decleration for locating in string

    int locate (string);

    void print () {

        for (size_t i = 0; i < m_size; i++) { std::cout << m_data[i]; }     // does not print null char
    }

}; // end of class


// to locate for passing in string literals, will expand later
int string::locate(const char* tolocate) {

    if (strlen(tolocate) > m_size) return -1;

    string mystring(tolocate);                              // store string literal into object

    if (mystring.length() > m_size)  { return -1; }               // if string to big auto not correct

    for (int i = 0; i < mystring.length(); i++){

        if (mystring[i] == m_data[i]) return 1;
    }
}


// to locate for passing in r value objects
int string::locate(string input) {

    if (input.length() > m_size) return -1;

    for (size_t i = 0; i < m_size; i++) {

        if (input[i] == m_data[i]) return 1;
    }
}



}