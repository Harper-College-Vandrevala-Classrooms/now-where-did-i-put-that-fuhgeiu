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


// fixed container
template<int S,typename T>                  // <size of container, data type>
class mydataT {

    T m_fixedcont[S];                           // stack array
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



// dynamic container
namespace cstd {

template <typename T>
class contdynamic {

    T* cd_data = nullptr;

    size_t  cd_size = 0;                // used amount of container
    size_t cd_capacity = 0;             // capacity of container

private:

    void Calloc (size_t newCapacity){                // allocates memory, called everytime need or want more memory

        T* newBlock = (T*)::operator new (newCapacity* sizeof(T));      // --allocate a array, to store moved data

        if (newCapacity < cd_size) cd_size = newCapacity;       // for reducing container size to a new capacity

        for (size_t i = 0; i < cd_size; i++) {                  // to allocate more memory to increase container size

            newBlock[i] = std::move(cd_data[i]);            // move data
        }

        for (size_t i = 0; i < cd_size; i++) {                  // to allocate more memory to increase container size

            cd_data[i].~T();                                // clear data without changing container size
        }

        ::operator delete(cd_data, cd_capacity * sizeof(T));        // --
        delete[] cd_data;                                 // delete from where we moved data from
        cd_data = newBlock;                               // assign pointer to block of meory where data was moved to
        cd_capacity = newCapacity;                        // assign a capacity based on block of memory we moved data to
    }

public:

    contdynamic() {Calloc(2);}                   // default constructor allocate for 2 slots

    virtual ~contdynamic() {                                        // destructor

        clear();                                                // clear the memory block
        ::operator delete(cd_data, cd_capacity * sizeof(T));    // instead of array delete call oparator to clear
    }

    void append(const T& element) {

        if (cd_size >= cd_capacity){                         // to increase available container space

            Calloc(cd_capacity + cd_size / 2);   // allocate 1.5 times memory size
        }

        cd_data[cd_size] = element;                         // copy data to apped onto container and assign
        cd_size++;                                          // increment size
    }

    void append(const T&& element) {                         // to mvoe data must be rvalue to use move()

        if (cd_size >= cd_capacity){                         // to increase available container space

            Calloc(cd_capacity + cd_size / 2);   // allocate 1.5 times memory size
        }

        cd_data[cd_size] = std::move(element);              // move data to apped onto container and assign
        cd_size++;                                          // increment size
    }

    void popback() {
        if (cd_size > 0) {

            cd_size--;
            cd_data[cd_size].~T();
        }
    }

    void clear() {

        for (size_t i = 0; i < cd_size; i++){
            cd_data[i].~T();
        }

        cd_size = 0;
    }

    size_t Size() const {return cd_size;}

    const T& operator[](size_t index) const { return cd_data; }   // return data at index of container ,const version

    T& operator[](size_t index)  { return cd_data; }   // return data at index of container

};


// inherited class to pass into template arguemnt to define data type and move data from another container
class contblock : public contdynamic<contblock*> {              // inherited class, to pass in as template arguemnt

//    ~ contblock() {};                                         // question


public:

    void storeblock(std::string,contblock);                 // store string into container using class as data type

};


// inherited class for data to pass in to append if user defined data type container
template <typename T>                                       // generic allows, reuse class for multiple data types
class datapass  :   public contblock {                      // if container requires a template as element

public:

    datapass() {}

};


void contblock::storeblock(std::string tempstring,contblock mycont) {        // store string into array template class


    mycont.append();                                 // append with new allocated class

    mycont.append(new datapass<char>());                            // append with new allocated user data type



}





class string {

    char* m_data;
    size_t m_size;

public:

    string () {};

    string (const char* string) {

        m_size = strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size);


    }

    ~ string (){

        delete m_data;
    }








};









//
//}
//
//
//namespace mystd{


//class contblock {
//
//    cstd::contdynamic<contblock*> my_data;                // contianer from our dynamic container class template
//
//public:
//
//    contblock() { };                                                  // constructor
//
//    void storeblock(std::string,contblock);                     // method decleration for storing
//
//    template <typename T,class C> int locate();                 // for locating in container
//
//    virtual ~contblock () {};
//};
//
//template <typename T>
//class custchar : public contblock {                             // for storing char
//
//    T character;
//
//    void custcharmehtod (T) {};
//
//};      // end of class


}   // end of name space




// add asserts for out of range indexing

// variatic templates (emplaceback)
// destructor