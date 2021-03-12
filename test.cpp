
/************************************************
#
#      Filename: test.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 19:11:14
# Last Modified: 2021-03-12 20:51:32
#***********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct A{
    int a;
    int b;
    string c;
    string d;
    int e;
};
int main(int argc, char *argv[])
{
    vector<A> record;

    unordered_map<int, string> a;
    a.insert(pair<int, string>(100, "aksdj1"));
    a.insert(pair<int, string>(100, "aksdj2"));
    a.insert(pair<int, string>(101, "aksdj3"));
    a.insert(pair<int, string>(100, "aksdj4"));
    cout << a.count(100) << endl;

    for(auto i: a){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}

