
/************************************************
#
#      Filename: main.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-25 19:57:06
# Last Modified: 2020-07-18 15:47:18
#***********************************************/
#include <iostream>
#include "speechManager.h"
using namespace std;
int main(int argc, char *argv[])
{
    SpeechManager sm;
    int choice = 0;
    
    while(true)
    {
        system("clear");
        sm.showMenu();

        cout << "请输入你的选择:";
        cin >> choice;
        cin.get();

        switch(choice)
        {
            case 1:
                sm.startSpeech();
                break;
            case 2:
                sm.showRecord();
                break;
            case 3:
                sm.clearRecord();
                break;
            case 0:
                sm.exitSystem();
                break;
            default:
                break;
        }
        cout << endl;

    }
    return 0;
}

