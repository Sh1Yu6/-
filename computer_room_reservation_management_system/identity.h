#pragma once
#include <iostream>
#include <string>

class Identity
{
    public:
        virtual void operMenu() = 0;
    protected:
        std::string mName;
        std::string mPwd;
};
