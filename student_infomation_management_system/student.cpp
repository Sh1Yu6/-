
/************************************************
#
#      Filename: student.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 09:47:26
# Last Modified: 2021-03-12 15:29:50
#***********************************************/
#include <iostream>
#include "student.h"
using namespace std;

namespace Sh1Yu6{
    Student::Student(std::string name, 
                     std::string school,
                     std::string cls,
                     std::string sex,
                     int id, 
                     int age)
            : mStuName{ name }, 
              mStuSchool{ school },
              mStuClass{ cls },
              mStuSex{ sex },
              mStuId{ id },
              mStuAge{ age }{

    }

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

    void Student::setStuSex( std::string sex ){
        mStuSex = sex;
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

    void Student::setStuAge( int age ){
        mStuAge = age;
    }
    int Student::getStuAge() const{
        return mStuAge;
    }


} // Sh1Yu6


