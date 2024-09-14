#include <iostream>

namespace strstd{

size_t strlength (const char*);                            // declare to use in string class

// very redumentary string class
class string {

    char* m_data = nullptr;                                  // char pointer for object/container
    size_t m_size;                                          //  size in terms of unsigned int w/o null char

public:
    string () {};

    string (const char* string) {                           // constructor

        setstring(string);
    }

    const char& operator[] (size_t index) const { return *(m_data + index);}             // index return as const

    size_t length () const { return (m_size);}                          // return number of elments, no null char
    size_t abslength () const { return (m_size+1);}                     // return number of elements, including null

    char& operator[] (size_t index) { return *(m_data + index);}                     // index

    void setstring (const char* string){

        m_size = strlength(string);                        // get the size of passed string w/o null char
        m_data = new char[m_size];                         // allocate new memory by passing in size of space needed

        memcpy(m_data, string, m_size);         // copy (destination, source, size (number of bytes))

        // move semantics



    }

    void print () {

        for (size_t i = 0; i < m_size; i++) { std::cout << m_data[i]; }     // does not print null char
    }

//  in progress
    char* sequence (int i, size_t length) {                      // to get a section of string and return new array

        char* m_store = new char[length];

        memcpy(m_store,m_data,(length * sizeof(char)));

        return m_store;
    }

}; // end of class


// strstd::strlength (string literal)
size_t strlength (const char* string) {                         // get size of a string literal, exclude null char

    size_t m_length = 0;

    while (*string != '\0')  { ++ m_length; ++ string; }
    return m_length;
}


// strstd::strcompare (string literal , pointer to character array (size must be r value))
template <size_t S,typename T>
int strcompare (const char* string, T (&array)[S]) {             // compare string literal to array

    size_t length_literal = strlength(string);
    if (length_literal != (S-1)) return -1;                     // if sizes do not match
    strstd::string literal_cont(string);                        // store in object

    for (size_t i = 0; i < length_literal; i++) {                       // itterate over string literal

        if (literal_cont[i] == array[i]) {} else return -1;
    }
    return 0;
}


// strstd::strcompare (string literal , pointer to string literal or array)
int strcompare (const char* string, const char* array) {             // compare string literal to array

    size_t length_literal = strlength(string);
    strstd::string literal_cont(string);                        // store in object

    for (size_t i = 0; i < length_literal; i++) {                       // itterate over string literal

        if (literal_cont[i] == array[i]) {} else return -1;
    }
    return 0;
}


// strstd::strcompare (string literal , string object, start index)
int strcompare (const char* string, strstd::string look, size_t begin) {

    size_t length_literal = strlength(string);
    strstd::string literal_cont(string);                                // store in object

    for (size_t i = 0; i < length_literal; i++) {                       // itterate over string literal

        if (literal_cont[i] == look[begin+i]) {} else return -1;
    }
    return 0;
}


}   // end of namespace



/*

    strstd::string, non template class to store strings in a character array









        STRING LITERAL LENGTH
    COMPARE STRINGS

    1) strstd::strlength size_t (const char*)

       <size_t S, typename T>
    2) strstd::strcompare int (const char* , T (&array)[S] (size must be r value))

    3) strstd::strcompare int (const char* , char*)

    4) strstd::strcompare int (const char*, strstd::string, int)

    _______________________________________________________________________________________________________________
    1) get size of string literal, does not include null. return type, unsigned int  size_t
    2) compare string literal to array. template pass in unsighned int for size, and array data type. cannot pass in
       cannot pass in a runtime only value for size, must be known at compile time
    3) compare string literal to array. pass in pointer to array
    4) compare string literal with a string object. (compare to, object to compare with, index where begin search)
       return type int, returns 0, if comparision is true. return -1, if comparision false

*/



// list to improve on

// use move sematics when passing in string literal, and for locating member(passing in literal)
// update destructor
// update constructor to a , copy and assignment constructor and move constructor
// add more useful methods