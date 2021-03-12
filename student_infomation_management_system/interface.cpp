
/************************************************
#
#      Filename: /home/wang/cpp/some_project/student_infomation_management_system/interface.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 11:38:46
# Last Modified: 2021-03-12 22:29:32
#***********************************************/
#include <iostream>
#include <string>
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
                    cout << "输入错误, 请输入(0-3)中一个数字选择功能!" << endl;
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
                    queryMneu();
                    stuManage->query();
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
                    statisticsMenu();
                    stuManage->statistics();
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
                    cout << "输入错误, 请输入(0-7)中一个数字选择功能!" << endl;
                    waitInput();
                    break;
            }

        }
    }

    int Interface::mainMenu(){
        system("clear");
        cout << "--------学生信息管理系统--------" << endl;
        cout << "------------年级选择------------" << endl;
        cout << "1. 小学生" << endl;
        cout << "2. 中学生" << endl;
        cout << "3. 大学生" << endl;
        cout << "0. 退出系统" << endl;
        cout << "请输入您的选择(0-3):";
        int select = 0;
        cin >> select;
        return select;
    }

    int Interface::selectMenu(){
        system("clear");
        cout << "--------学生信息管理系统--------" << endl;
        cout << "------------操作选择------------" << endl;
        cout << "1. 添加学生信息" << endl;
        cout << "2. 查询学生信息" << endl;
        cout << "3. 显示学生信息" << endl;
        cout << "4. 编辑学生信息" << endl;
        cout << "5. 删除学生信息" << endl;
        cout << "6. 统计学生信息" << endl;
        cout << "7. 返回上一层" << endl;
        cout << "0. 退出系统" << endl;
        cout << "请输入您的选择(0-7):";
        int select = 0;
        cin >> select;
        return select;
    }

    void Interface::addMenu(){
        system("clear");
        cout << "--------学生信息管理系统--------" << endl;
        cout << "------------添加信息------------" << endl;
    }

    int Interface::queryMneu(){
        system("clear");
        cout << "--------学生信息管理系统--------" << endl;
        cout << "------------查询信息------------" << endl;

    }

    void Interface::displayMenu(){
        system("clear");
        cout << "--------学生信息管理系统--------" << endl;
        cout << "------------显示信息------------" << endl;

    }
    int Interface::editMenu(){
        system("clear");
        cout << "--------学生信息管理系统--------" << endl;
        cout << "------------编辑信息------------" << endl;

    }
    int Interface::deleteMenu(){
        system("clear");
        cout << "--------学生信息管理系统--------" << endl;
        cout << "------------删除信息------------" << endl;

    }
    int Interface::statisticsMenu(){
        system("clear");
        cout << "--------学生信息管理系统--------" << endl;
        cout << "------------统计信息------------" << endl;

    }


    void Interface::waitInput()
    {
        cout << "请按回车键继续..........";
        cin.ignore();
        cin.ignore();
    }


} // Sh1Yu6

