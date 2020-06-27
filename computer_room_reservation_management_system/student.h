#pragma once

#include <iostream>
#include <string>
#include "identity.h"

class Student: public Identity
{
    public:
        Student();
        Student(int id, std::string name, std::string pwd);

        virtual void operMenu();

        void applyOrder();

        void showAllOrder();

        void cancelOrder();

    private:
        int mStudentId;
};
