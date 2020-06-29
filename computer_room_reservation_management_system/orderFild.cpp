
/************************************************
#
#      Filename: orderFild.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-29 19:45:55
# Last Modified: 2020-06-29 21:07:45
#***********************************************/
#include "orderFild.h"
#include <ios>
#include <sys/cdefs.h>
using namespace std;

void createA(const string& data, map<string, string>& m)
{
    string key;
    string value;

    int pos = data.find(":");
    key = data.substr(0, pos);
    value = data.substr(pos + 1, data.size() - pos - 1);
    m.insert(make_pair(key, value));

}
OrderFile::OrderFile()
{
    ifstream ifs(kOrderFile);

    string date;
    string interval;
    string stuId;
    string stuName;
    string roomId;
    string status;
    mSize = 0;
    
    while(ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName &&
          ifs >> roomId && ifs >> status)
    {
        map<string, string> m;
        createA(date, m);
        createA(interval, m);
        createA(stuId, m);
        createA(stuName, m);
        createA(roomId, m);
        createA(status, m);

        mOrderData.insert(make_pair(mSize, m));
        ++mSize;
    }


}

void OrderFile::updateOrder()
{
    if(mSize == 0)
    {
        return;
    }

    ofstream ofs(kOrderFile, ios::trunc);
    for(int index = 0; index < mSize; ++index)
    {
        ofs << "date:" << mOrderData[index]["date"] 
            << " interval:" << mOrderData[index]["interval"]
            << " stuId:" << mOrderData[index]["stuId"] 
            << " stuName:" << mOrderData[index]["stuName"]
            << " roomId:" << mOrderData[index]["roomId"] 
            << " status:" << mOrderData[index]["status"] << endl;
    }
    ofs.close();
}
