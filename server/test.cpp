
/************************************************
#
#      Filename: test.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-07 14:20:14
# Last Modified: 2021-05-03 16:17:20
#***********************************************/
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <string>
//#include "iostream"
using namespace std;
int main(int argc, char *argv[])
{

    string str{"abcdef"};
    string s;
    for(int i = 0; i < (int)str.size(); ++i){
        s.push_back(str[i] ^ 0x10);
    }
    cout << s <<endl;
    for(int i = 0; i < (int)s.size(); ++i){
        cout << (char)( s[i] ^ 0x10 ) ;
    }
    cout <<endl;

    return 0;
}

