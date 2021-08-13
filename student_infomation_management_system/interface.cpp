
/************************************************
#
#      Filename: /home/wang/cpp/some_project/student_infomation_management_system/interface.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 11:38:46
# Last Modified: 2021-05-24 12:12:33
#***********************************************/
#include <iostream>
#include <string>
#include <limits>
#include "interface.h"
#include "pri_stu_management.h"
#include "mid_stu_management.h"
#include "col_stu_management.h"
#include "student_management.h"
using namespace std;
namespace Sh1Yu6{

    void Interface::mainFace(){
        while(true){
            int select = mainMenu();

            StuManagement* stuManage = nullptr;
            switch(select){
                case 1:
                    stuManage = new PriStuManagement();
                    selectFace(stuManage);
                    break;
                case 2:
                    stuManage = new MidStuManagement();
                    selectFace(stuManage);
                    break;
                case 3:
                    stuManage = new ColStuManagement();
                    selectFace(stuManage);
                    break;
                case 0:
                    if(stuManage != nullptr){
                        delete stuManage;
                    }
                    exit(0);
                default:
                    cout << "Wrong input, please enter a scale of 0-3!" << endl;
                    waitInput();
                    break;
            }
            if(stuManage != nullptr){
                delete stuManage;
            }
        }
    }

    void Interface::selectFace(StuManagement*& stuManage){
        stuManage->read();
        while(true){
            int select = selectMenu();
            switch(select){
                case 1:
                    addMenu();
                    stuManage->add();
                    waitInput();
                    break;
                case 2:
                    select = queryMneu();
                    if(select == 0){
                        stuManage->save();
                        exit(0);
                    }else if(select == 3){
                        break;
                    }else if(select != 1 && select != 2){
                        cout << "Wrong input, please enter a scale of 0-3!" << endl;
                        waitInput();
                        break;
                    }
                    stuManage->query(select);
                    waitInput();
                    break;
                case 3:
                    displayMenu();
                    stuManage->display();
                    waitInput();
                    break;
                case 4:
                    editMenu();
                    stuManage->edit();
                    waitInput();
                    break;
                case 5:
                    deleteMenu();
                    stuManage->del();
                    waitInput();
                    break;
                case 6:
                    select = statisticsMenu();
                    if(select == 0){
                        stuManage->save();
                        exit(0);
                    }else if(select == 4){
                        break;
                    }else if(select != 1 && select != 2 && select != 3){
                        cout << "Wrong input, please enter a scale of 0-4!" << endl;
                        waitInput();
                        break;
                    }
                    stuManage->statistics(select);
                    waitInput();
                    break;
                case 7:
                    stuManage->save();
                    return;
                    break;
                case 0:
                    stuManage->save();
                    exit(0);
                    break;
                default:
                    cout << "Wrong input, please enter a scale of 0-7!" << endl;
                    waitInput();
                    break;
            }

        }
    }

    int Interface::mainMenu(){
        system("clear");
        cout << "--------Student Information Management System--------" << endl;
        cout << "---------------------Grade choice--------------------" << endl;
        cout << "1. Primary students" << endl;
        cout << "2. Middle  students " << endl;
        cout << "3. College students" << endl;
        cout << "0. Log out" << endl;
        cout << "Please enter your choice (0-3):";
        int select = 0;
        cin >> select;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            return 10;
        }
        return select;
    }

    int Interface::selectMenu(){
        system("clear");
        cout << "--------Student Information Management System--------" << endl;
        cout << "------------------Operation choice-------------------" << endl;
        cout << "1. Add student information" << endl;
        cout << "2. Search Student Information" << endl;
        cout << "3. Display student information" << endl;
        cout << "4. Edit student information" << endl;
        cout << "5. Delete student information" << endl;
        cout << "6. Statistics of student information" << endl;
        cout << "7. return to the previous level" << endl;
        cout << "0. Log out" << endl;
        cout << "Please enter your choice (0-7):";
        int select = 0;
        cin >> select;
        return select;
    }

    void Interface::addMenu(){
        system("clear");
        cout << "--------Student Information Management System--------" << endl;
        cout << "---------------Add student information---------------" << endl;
    }

    int Interface::queryMneu(){
        system("clear");
        cout << "--------Student Information Management System--------" << endl;
        cout << "-------------Search Student Information--------------" << endl;
        cout << "1. Query by student number" << endl;
        cout << "2. Query by name" << endl;
        cout << "3. return to the previous level" << endl;
        cout << "0. Log out" << endl;
        cout << "Please enter your choice (0-3):";
        int select = 0;
        cin >> select;
        return select;

    }

    void Interface::displayMenu(){
        system("clear");
        cout << "--------Student Information Management System--------" << endl;
        cout << "------------Display student information--------------" << endl;

    }

    void Interface::editMenu(){
        system("clear");
        cout << "--------Student Information Management System--------" << endl;
        cout << "---------------Edit student information--------------" << endl;
        cout << "Please enter the student number of "
             << "the student whose information you want to modify:";
    }

    void Interface::deleteMenu(){
        system("clear");
        cout << "--------Student Information Management System--------" << endl;
        cout << "-------------Delete student information--------------" << endl;
        cout << "Please enter the student number of "
             << "the student you want to delete:";
    }

    int Interface::statisticsMenu(){
        system("clear");
        cout << "--------Student Information Management System--------" << endl;
        cout << "----------Statistics of student information----------" << endl;
        cout << "1. Count the number of students" << endl;
        cout << "2. Statistics by gender" << endl;
        cout << "3. Statistics by age" << endl;
        cout << "4. return to the previous level" << endl;
        cout << "0. Log out" << endl;
        cout << "Please enter your choice (0-4):";
        int select = 0;
        cin >> select;
        return select;
    }


    void Interface::waitInput()
    {
        cout << "Please press enter to continue.........";
        cin.ignore();
        cin.ignore();
    }


} // Sh1Yu6

