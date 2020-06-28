
/************************************************
#
#      Filename: identity.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-28 20:10:17
# Last Modified: 2020-06-28 21:10:44
#***********************************************/
#include "identity.h"
using namespace std;

void Identity::setName(string name)
{
    mName = name;
}

void Identity::setPwd(string pwd)
{
    mPwd = pwd;
}

std::string Identity::getName() const
{
    return mName;
}

std::string Identity::getPwd() const
{
    return mPwd;
}
