
/************************************************
#
#      Filename: test.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 19:11:14
# Last Modified: 2021-03-13 17:01:32
#***********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class A{
    public:
    void func(){
       func2();
    }
    virtual void func2() = 0;

};

class B: public A{

    public:
    int a = 10;
    void func2() override{
        cout << "B" << endl;
        cout << a << endl;
    }
};

class C: public A{

    public:
    int a = 100;
    void func2() override{
        cout << "C" << endl;
        cout << a << endl;
    }
};
int main(int argc, char *argv[])
{
    return 0;
}

