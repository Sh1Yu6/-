
/************************************************
#
#      Filename: student.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 09:47:26
# Last Modified: 2021-03-13 09:27:24
#***********************************************/
#include <iostream>
#include "student.h"
using namespace std;

namespace Sh1Yu6{
    void Student::setStuName( std::string name ){
        mStuName = name;
    }
    std::string Student::getStuName() const{
        return mStuName;
    }

    void Student::setStuSchool( std::string school ){
        mStuSchool = school;
    }
    std::string Student::getStuSchool() const{
        return mStuSchool;
    }

    void Student::setStuClass( std::string cls ){
        mStuClass = cls;
    }
    std::string Student::getStuClass() const{
        return mStuClass;
    }

    bool Student::setStuSex( std::string sex ){
        if(sex != "man" && sex != "woman"){
            cout << "Please enter man or woman!" << endl;
            return false;
        }
        mStuSex = sex;
        return true;
    }
    std::string Student::getStuSex() const{
        return mStuSex;
    }

    void Student::setStuId( int id ){
        mStuId = id;
    }
    int Student::getStuId() const{
        return mStuId;
    }

    bool Student::setStuAge( int age ){
        if(age < 0 || age > 120){
            cout << "Please enter a scale of 0-120!" << endl;
            return false;
        }
        mStuAge = age;
        return true;
    }
    int Student::getStuAge() const{
        return mStuAge;
    }


} // Sh1Yu6


