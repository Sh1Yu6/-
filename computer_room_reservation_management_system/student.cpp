
/************************************************
#
#      Filename: student.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-27 19:46:17
# Last Modified: 2020-06-29 21:34:39
#***********************************************/
#include "student.h"
using namespace std;
Student::Student()
{

}
Student::Student(int id, std::string name, std::string pwd)
{
    mStudentId = id;
    mName = name;
    mPwd = pwd;

    ifstream ifs(kComputerFile);

    int roomId;
    int roomCount;
    while(ifs >> roomId && ifs >> roomCount)
    {
        ComputerRoom c;
        c.setId(roomId);
        c.setMaxNum(roomCount);
        mCom.push_back(c);
    }
    ifs.close();
    
}

void Student::operMenu()
{
    cout << "欢迎学生:" << mName << "登录!" << endl;
    cout << "-------------------------------" << endl;
    cout << "1) 申请预约 " << endl;
    cout << "2) 查看我的预约 " << endl;
    cout << "3) 查看所有预约 " << endl;
    cout << "4) 取消预约 " << endl;
    cout << "0) 注销登录 " << endl;
    cout << "请输入您的选择:";
}

void Student::applyOrder()
{
    int date = 0;
    int interval = 0;
    int room = 0;

    cout << "请输入预约的时间(1-5)." << endl;
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;
    while(true)
    {
        cout << "请输入你的选择:";
        cin >> date;
        if(date >= 1 && date <= 5)
        {
            break;
        }
        cout << "输入错误, 请重新输入" << endl;
    }


    cout << "请输入预约的时间段(1-2)." << endl;
    cout << "1. 上午" << endl;
    cout << "2. 下午" << endl;
    while(true)
    {
        cout << "请输入你的选择:";
        cin >> interval;
        if(interval >= 1 && interval <= 2)
        {
            break;
        }
        cout << "输入错误, 请重新输入" << endl;
    }


    cout << "请选择机房." << endl;
    for(const auto& index: mCom)
    {
        cout << "机房编号: " << index.getId() 
             << " 机房容量: " << index.getMaxNum() << endl;
    }
    while(true)
    {
        cout << "请输入你的选择:";
        cin >> room;
        if(room >= 1 && room <= mCom.size())
        {
            break;
        }
        cout << "输入错误, 请重新输入" << endl;
    }


    cout << "预约成功, 等待审核!" << endl;

    ofstream ofs(kOrderFile, ios::app);
    ofs << "date:" << date << " interval:" << interval
        << " stuId:" << mStudentId << " stuName:" << mName
        << " roomId:" << room << " status:" << 1 << endl;

    ofs.close();
}

void printOrderStatus(OrderFile& of, int index)
{
        cout << "预约时间: 周" << of.mOrderData[index]["date"];
        cout << " 时段: " << (of.mOrderData[index]["interval"] == "1"? "上午": "下午");
        cout << " 机房: " << of.mOrderData[index]["roomId"];
        if(of.mOrderData[index]["status"] == "1")
        {
            cout << " 状态: 审核中!" << endl; 
        }
        else if(of.mOrderData[index]["status"] == "2")
        {
            cout << " 状态: 预约成功!" << endl; 
        }
        else if(of.mOrderData[index]["status"] == "-1")
        {
            cout << " 状态: 审核未通过, 预约失败!" << endl; 
        }
        else
        {
            cout << " 状态: 预约已取消!" << endl; 
        }

}
void Student::showMyOrder()
{
    OrderFile of;
    if(of.mSize == 0)
    {
        cout << "无预约记录" << endl;
        return ;
    }

    for(int index = 0; index < of.mSize; ++index)
    {
         if(stoi(of.mOrderData[index]["stuId"]) == mStudentId)
         {
             printOrderStatus(of, index);
         }
    }
}

void Student::showAllOrder()
{
    OrderFile of;
    if(of.mSize == 0)
    {
        cout << "无预约记录" << endl;
        return ;
    }

    for(int index = 0; index < of.mSize; ++index)
    {
        printOrderStatus(of, index);
    }
}

void Student::cancelOrder()
{
    OrderFile of;
    if(of.mSize == 0)
    {
        cout << "无预约记录" << endl;
        return ;
    }

    vector<int> v;
    int i = 1;
    for(int index = 0; index < of.mSize; ++index)
    {
         if(stoi(of.mOrderData[index]["stuId"]) == mStudentId)
         {
             if(of.mOrderData[index]["status"] == "1" ||
                of.mOrderData[index]["status"] == "2")
             {
                v.push_back(index);
                cout << i++ << ". ";
                printOrderStatus(of, index);
             }
         }
    }

    cout << "请输入要取消的记录(0取消操作)" << endl;
    while(true)
    {
        int select = 0;
        cin >> select;

        if(select == 0)
        {
            break;
        }
        else if(select > 0 && select <= v.size())
        {
            of.mOrderData[v[select-1]]["status"] = "0";
            of.updateOrder();
            cout << "预约已取消!" << endl;
            break;
        }
        cout << "输入错误, 请重新输入!" << endl;
    }
}


void Student::setId(int id)
{
    mStudentId = id;
}

int Student::getId() const
{
    return mStudentId;
}
