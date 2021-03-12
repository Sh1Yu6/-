
/************************************************
#
#      Filename: college_student.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 11:02:43
# Last Modified: 2021-03-12 11:06:08
#***********************************************/
#include <iostream>
#include "college_student.h"
using namespace std;

namespace Sh1Yu6{
    
    CollegeStudent::CollegeStudent(std::string profess,
                                   std::string addr,
                                   std::string phoneNum)
                    : mProfessional{ profess },
                      mAddress{ addr },
                      mPhoneNum{ phoneNum }{

                      }

            
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

    void CollegeStudent::setPhoneNum(std::string phoneNum){
        mPhoneNum = phoneNum;
    }
    std::string CollegeStudent::getPhoneNum() const{
        return mPhoneNum;
    }
} // Sh1Yu6

