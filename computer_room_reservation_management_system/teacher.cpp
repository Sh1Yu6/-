
/************************************************
#
#      Filename: teacher.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-27 19:53:56
# Last Modified: 2020-06-29 21:42:07
#***********************************************/
#include "teacher.h"
using namespace std;
Teacher::Teacher()
{

}
Teacher::Teacher(int TeacherId, std::string name, std::string pwd)
{
    mTeacherId = TeacherId;
    mName = name;
    mPwd = pwd;

}

void Teacher::operMenu()
{
    cout << "欢迎老师:" << mName << "登录!" << endl;
    cout << "-------------------------------" << endl;
    cout << "1) 查看预约 " << endl;
    cout << "2) 处理预约 " << endl;
    cout << "0) 注销登录 " << endl;
    cout << "请输入您的选择:";

}

void printOrderStatusV(OrderFile& of, int index)
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

void Teacher::showAllOrder()
{
    OrderFile of;
    if(of.mSize == 0)
    {
        cout << "无预约记录" << endl;
        return ;
    }

    for(int index = 0; index < of.mSize; ++index)
    {
        printOrderStatusV(of, index);
    }

}

void Teacher::validOrder()
{
    OrderFile of;
    if(of.mSize == 0)
    {
        cout << "无预约记录" << endl;
        return ;
    }

    cout << "等待审核的预约:" << endl;

    vector<int> v;
    int index = 1;
    for(int i = 0; i < of.mSize; ++i)
    {
        if(of.mOrderData[i]["status"] == "1")
        {
            v.push_back(i);
            cout << index++ << endl;
            printOrderStatusV(of, i);
        }
    }

    cout << "请输入要处理的预约(0取消)" << endl;
    while(true)
    {
        int select = 0;
        int ret = 0;
        cin >> select;
        if(select >= 0 && select <= v.size())
        {
            if(select == 0)
            {
                break;
            }
            else
            {
                cout << "请输入审核结果(1. 通过 2. 不通过)" << endl;
                cin >> ret;
            }

            if(ret == 1)
            {
                of.mOrderData[v[select-1]]["status"] = "2";
            }
            else if(ret == 2)
            {
                of.mOrderData[v[select-1]]["status"] = "-1";
            }
            else
            {
                cout << "输入错误" << endl;
                cout << "输入错误, 请重新输入!" << endl;
                break;
            }

            of.updateOrder();
            cout << "处理结束!" << endl;
            break;
        }
        cout << "输入错误, 请重新输入!" << endl;
    }
}

void Teacher::setId(int id)
{
    mTeacherId = id;
}

int Teacher::getId() const
{
    return mTeacherId;
}
