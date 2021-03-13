
/************************************************
#
#      Filename: manager.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-27 19:58:20
# Last Modified: 2021-03-13 17:02:52
#***********************************************/
#include "manager.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "student.h"
using namespace std;


void printStudent(const Student& s);
void printTeacher(const Teacher& t);
Manager::Manager(std::string name, std::string pwd)
{
    mName = name;
    mPwd = pwd;

    ifstream ifs(kComputerFile);

    int id;
    int num;
    while(ifs >> id && ifs >> num)
    {
        ComputerRoom c;
        c.setId(id);
        c.setMaxNum(num);
        
        mCom.push_back(c);
    }

    ifs.close();
}

void Manager::operMenu()
{
    cout << "欢迎管理员:" << mName << "登录!" << endl;
    cout << "-------------------------------" << endl;
    cout << "1) 添加账号 " << endl;
    cout << "2) 查看账号 " << endl;
    cout << "3) 查看机房 " << endl;
    cout << "4) 清空预约 " << endl;
    cout << "0) 注销登录 " << endl;
    cout << "请输入您的选择:";
}


void Manager::addPerson()
{
    initVector();
    cout << "添加账号的类型(1.学生 2.教师):";
    
    int select = 0;
    string fileName;

    cin >> select;

    if(select == 1)
    {
        fileName = kStudentFile;
    }
    else if(select == 2)
    {
        fileName = kTeacherFile;
    }
    else
    {
        cout << "输入错误" << endl;
        return;
    }

    ofstream ofs(fileName, ios::app);

    int id;
    string name;
    string pwd;

    do
    {
        cout << "请输入编号:";
        cin >> id;
    }while(checkRepeat(id, select));

    cout << "请输入姓名:";
    cin >> name;

    cout << "请输入密码:";
    cin >> pwd;
    
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;
    ofs.close();
    return;
}

void Manager::showPerson()
{
    initVector();
    cout << "请选择查看的内容(1.学生 2.教师):";

    int select = 0;

    cin >> select;

    if(select == 1)
    {
        cout << "所有学生信息如下:" << endl;
        for_each(mStu.begin(), mStu.end(), printStudent);
    }
    else if(select == 2)
    {
        cout << "所有教师信息如下:" << endl;
        for_each(mTea.begin(), mTea.end(), printTeacher);
    }
    else
    {
        cout << "输入错误" << endl;
        return;
    }
}

void Manager::showComputerRoom()
{
    cout << "机房信息如下:" << endl;
    for(auto& index: mCom)
    {
        cout << "机房编号: " << index.getId() << " 机房最大容量: " 
             << index.getMaxNum() << endl;
    }
}

void Manager::clearFile()
{
    ofstream ofs(kOrderFile, ios::trunc);
    ofs.close();
    
    cout << "清空成功" << endl;
}



void Manager::initVector()
{
    ifstream ifs(kStudentFile);

    if(!ifs.is_open())
    {
        cout << "打开文件" << kStudentFile << "失败!" << endl;
        return;
    }

    mStu.clear();
    int id;
    string name;
    string pwd;

    while(ifs >> id && ifs >> name && ifs >> pwd)
    {
        Student s;

        s.setId(id);

        s.setName(name);

        s.setPwd(pwd);
        
        mStu.push_back(s);
    }
    ifs.close();


    ifs.open(kTeacherFile);

    if(!ifs.is_open())
    {
        cout << "打开文件" << kTeacherFile << "失败!" << endl;
        return;
    }

    mTea.clear();

    while(ifs >> id && ifs >> name && ifs >> pwd)
    {
        Teacher s;

        s.setId(id);

        s.setName(name);

        s.setPwd(pwd);
        
        mTea.push_back(s);
    }

    ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
    if(type == 1)
    {
        for(auto iter = mStu.begin(); iter != mStu.end(); ++iter)
        {
            if(id == iter->getId())
            {
                cout << "已存在相同学生id, 请重新输入!" << endl;
                return true;
            }
        }
    }
    else if(type == 2)
    {
        for(auto& index: mTea)
        {
            if(id == index.getId())
            {
                cout << "已存在相同教师id, 请重新输入!" << endl;
                return true;
            }
        }
    }
    return false;
}


void printStudent(const Student& s)
{
    cout << "学号: " << s.getId() << " 姓名: " << s.getName()
         << " 密码: " << s.getPwd() << endl;
}

void printTeacher(const Teacher& t)
{
    cout << "职工号: " << t.getId() << " 姓名: " << t.getName() 
         << " 密码: " << t.getPwd() << endl;
}
