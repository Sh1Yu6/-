
/************************************************
#
#      Filename: student_management.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-13 11:31:59
# Last Modified: 2021-03-13 19:33:13
#***********************************************/
#include <iostream>
#include "student_management.h"
using namespace std;
namespace Sh1Yu6{

    void StuManagement::query(int select){
        if(select == 1){
            int id;
            cout << "Please enter the student number you want to query:";
            cin >> id;
            queryById(id);
        }else{
            string str;
            cout << "Please enter the name you want to query:";
            cin >> str;
            queryByName(str);
        }

    }

    void StuManagement::statistics(int select){
        switch(select){
            case 1:
                statisticsTotal();
                break;
            case 2:
                statisticsByGender();
                break;
            case 3:
                statisticsByAge();
                break;
            default:
                break;
        }

    }
} // Sh1Yu6

