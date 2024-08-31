#include <iostream>

namespace cstd {


    class mydata {

        std::string s1;

        char *ptr1 = s1[0];

    public:

        mydata() {};                   // default constructor

        void change(int T);            // member decleration

        void temp();                   // member decleration


    };


    void mydata::change (int t){

        *ptr1 = t;
    }


    void mydata::temp(){

        std::cout << *ptr1;
    }

    void temp(){

    }




}

