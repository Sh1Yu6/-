
/************************************************
#
#      Filename: college_student.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 11:02:43
# Last Modified: 2021-03-13 10:34:48
#***********************************************/
#include <iostream>
#include <iomanip>
#include "college_student.h"
using namespace std;

namespace Sh1Yu6{
    
    void CollegeStudent::setProfessional(std::string profess){
        mProfessional = profess;
    }

    std::string CollegeStudent::getProfessional() const{
        return mProfessional;
    }

    void CollegeStudent::setAddress(std::string addr){
        mAddress = addr;
    }

    std::string CollegeStudent::getAddress() const{
        return mAddress;
    }

    bool CollegeStudent::setPhoneNum(std::string phoneNum){
        if(phoneNum.size() != 11){
            cout << "Please enter an 11-digit cell phone number!" << endl;
            return false;
        }
        mPhoneNum = phoneNum;
        return true;
    }

    std::string CollegeStudent::getPhoneNum() const{
        return mPhoneNum;
    }

    std::istream& operator>>(std::istream& in, CollegeStudent& stu){
        in >> stu.mStuId;
        in >> stu.mStuName;
        in >> stu.mStuSchool;
        in >> stu.mStuClass;
        in >> stu.mAddress;
        in >> stu.mProfessional;
        in >> stu.mPhoneNum;
        in >> stu.mStuSex;
        in >> stu.mStuAge;
        return in;
    }

    std::ostream& operator<<(std::ostream& out, CollegeStudent& stu){
        out << setw(10) << stu.mStuId
            << setw(10) << stu.mStuName
            << setw(10) << stu.mStuSchool
            << setw(10) << stu.mStuClass
            << setw(10) << stu.mAddress
            << setw(10) << stu.mProfessional
            << setw(13) << stu.mPhoneNum
            << setw(10) << stu.mStuSex 
            << setw(10) << stu.mStuAge
            << endl;
        return out;
    }
} // Sh1Yu6

