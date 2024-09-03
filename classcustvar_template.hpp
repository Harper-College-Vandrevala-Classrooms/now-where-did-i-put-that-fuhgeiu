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

        T* newBlock = new T[newCapacity];                       // allocate a array, to store moved data

        if (newCapacity < cd_size) cd_size = newCapacity;       // for reducing container size to a new capacity


        for (size_t i = 0; i < cd_size; i++) {                  // to allocate more memory to increase container size

            newBlock[i] = std::move(cd_data[i]);            // move data
        }

        delete[] cd_data;                                 // delete from where we moved data from
        cd_data = newBlock;                               // assign pointer to block of meory where data was moved to
        cd_capacity = newCapacity;                        // assign a capacity based on block of memory we moved data to
    }

public:

    contdynamic() {Calloc(2);}                   // default constructor allocate for 2 slots

    ~contdynamic() {delete[] cd_data;}                      // destructor

    void append(const T& element) {

        if (cd_size >= cd_capacity){                         // to increase available container space

            Calloc(cd_capacity + cd_size / 2);   // allocate 1.5 times memory size
        }

        cd_data[cd_size] = element;                         // copy data to apped onto container and assign
        cd_size++;                                          // increment size
    }

    void append(const T&& element) {                         // to mvoe data

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

    int s = tempstring.size();

    mydataT<s,int> cont;



}

int find () {





}


}




// add asserts for out of range indexing

// l and r values
// variatic templates (emplaceback)
// destructor