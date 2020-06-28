#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <vector>
#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

class Manager: public Identity
{
    public:
        Manager() = default;
        Manager(std::string name, std::string pwd);

        virtual void operMenu() override;

        void addPerson();

        void showPerson();

        void showComputerRoom();

        void clearFile();


    private:
        void initVector();

        bool checkRepeat(int id, int type);


        std::vector<Student> mStu;
        std::vector<Teacher> mTea;
        std::vector<ComputerRoom> mCom;
};
