#pragma once
#include <iostream>
#include <string>

class Identity
{
    public:
        virtual void operMenu() = 0;

        void setName(std::string name);
        std::string getName() const;

        void setPwd(std::string pwd);
        std::string getPwd() const;
    protected:
        std::string mName;
        std::string mPwd;
};
