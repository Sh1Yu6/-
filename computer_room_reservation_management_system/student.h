#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include "identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFild.h"


class Student: public Identity
{
    public:
        Student();
        Student(int id, std::string name, std::string pwd);

        virtual void operMenu();

        void applyOrder();

        void showMyOrder();

        void showAllOrder();

        void cancelOrder();

        void setId(int id);

        int getId() const;

    private:
        int mStudentId;

        std::vector<ComputerRoom> mCom;
};
