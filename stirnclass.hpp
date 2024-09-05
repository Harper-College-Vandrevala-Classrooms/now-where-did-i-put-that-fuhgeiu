#include <iostream>

namespace cstd{

// very redumentary string class
class string {

    char* m_data = nullptr;                                  // char pointer for object/container
    size_t m_size;                                          // variable for size of container

public:

    string () {};                                           // defualt constructor

    string (char* string) {                           // want a constant pointer

        setstring(string);
    }

    ~ string (){                                            // destructor

        delete [] m_data;                                      // delete array we allocated earlier
    }

    void getline (){}

    const char& operator[] (size_t index) const { return *m_data;}                // index return as const

    int length () { return m_size;}                                             // returns size

    char& operator[] (size_t index) { return *(m_data + index);}                            // index

    void setstring (char* string){

        m_size = strlen(string);                          // get the size of passed string
        m_data = new char[m_size];                          // allocate new memory by passing in size of space needed
        memcpy(m_data, string, m_size);          // copy (destination, source, size (number of bytes))
    }

    template<typename T>int locate (T);                                     // member decleration for locating in string

}; // end of class


template <typename T>
int string::locate(T tolocate) {

    for (int i = 0; i < string::m_size; i++){

        if ()

    }



}

}