#include "str.hpp"

namespace srcstd {


int search(const char* tolocate, strstd::string lookin) {       // (string literal, string object)

    size_t seqlen = strstd::strlength(tolocate);
    size_t index = 0;

    while (index <= (lookin.length() - seqlen)) {

        if (strstd::strcompare(tolocate, lookin , index) == 0) return index;
        index++;
    }
    return -1;
}


int search (char locate, strstd::string lookin) {                  // (char , string object)

    size_t index = 0;

    while (index <= lookin.length()) {

        if (lookin[index] == locate) return index;
        index++;
    }
    return -1;
}



// might need later for testign r value refernces
//int search(const char* tolocate, const char* look) {            // (string literal, string literal
//
//    strstd::string lookin(look);
//
//    return search(tolocate,lookin);
//}


// might need later for testing r value refernces
//int search (char c, const char* look){                             // (char , string literal)
//
//    strstd::string tolocate(look);                            // string literal not mutible, store in object
//
//    return search(c,tolocate);
//}


}   // end of namespace






/*  notes
                   (what to search,what to search from)

    srcstd::search (const char* , const char*)                  for searching a string from another string

    srcstd::search (const char* , cstd::string object)          for searching a string literal from my string object

    srcstd::search (char , cstd::string object)                 for searching a character from string object

    srcstd::search (char , const char* )                        for searching character from string literal


    all return size_t of index where the first occurance was found, index 0
 */