#pragma once

#include <iostream>
#include <string>
#include "identity.h"

class Teacher: public Identity
{
    public:
        Teacher();
        Teacher(int TeacherId, std::string name, std::string pwd);

        virtual void operMenu();

        void showAllOrder();

        void validOrder();
    private:
        int mTeacherId;
};
