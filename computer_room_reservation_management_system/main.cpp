
/************************************************
#
#      Filename: main.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-27 19:27:59
# Last Modified: 2020-06-27 20:46:25
#***********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

void waitInput();

void loginIn(const string fileName, const int type);

int main(int argc, char *argv[])
{
    int select = 0;

    while(true)
    {
        system("clear");
        cout << "---------computer room reservation management system----------" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "1) 学生" << endl;
        cout << "2) 老师" << endl;
        cout << "3) 管理员" << endl;
        cout << "0) 退出" << endl;
        cout << "请输入您的选择:";
        cin >> select;
    //    cin.get();

        switch(select)
        {
            case 1:
                loginIn(kStudentFile, 1);
                waitInput();
                break;
            case 2:
                loginIn(kTeacherFile, 2);
                waitInput();
                break;
            case 3:
                loginIn(kAdminFile, 3);
                waitInput();
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                waitInput();
                exit(0);
                break;
            default:
                cout << "输入错误, 重新输入!" << endl;
                waitInput();
                break;
        }
    }
    return 0;
}

void waitInput()
{
    cout << "请按回车键继续..........";
    cin.ignore();
    cin.get();
}

void loginIn(const string fileName, const int type)
{
    Identity* person = nullptr;

    ifstream ifs(fileName);

    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if(type == 1)
    {
        cout << "请输入学号:";
        cin >> id;
    }
    else if(type == 2)
    {
        cout << "请输入职工号:";
        cin >> id;
    }

    cout << "请输入用户名:";
    cin >> name;

    cout << "请输入密码:";
    cin >> pwd;

    if(type == 1)
    {
        int fId;
        string fName;
        string fPwd;

        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(id == fId && name == fName && pwd == fPwd)
            {
                cout << "登录成功" << endl;
                person = new Student(id, name, pwd);
                return; 
            }
        }
    }
    else if(type == 2)
    {
        int fId;
        string fName;
        string fPwd;

        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(id == fId && name == fName && pwd == fPwd)
            {
                cout << "登录成功" << endl;
                person = new Teacher(id, name, pwd);
                return; 
            }
        }

    }
    else if(type == 3)
    {
        string fName;
        string fPwd;

        while(ifs >> fName && ifs >> fPwd)
        {
            if(name == fName && pwd == fPwd)
            {
                cout << "登录成功" << endl;
                person = new Manager(name, pwd);
                return; 
            }
        }

    }

    cout << "登录失败!" << endl;
}

