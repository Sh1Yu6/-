
/************************************************
#
#      Filename: middle_student.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 10:46:10
# Last Modified: 2021-03-13 10:06:56
#***********************************************/
#include <iostream>
#include <iomanip>
#include "middle_student.h"
using namespace std;

namespace Sh1Yu6{
    

    bool MiddleStudent::setGeographyScore(int score){
        if(score < 0 || score > 100){
            cout << "Please enter a scale of 0-100!" << endl;
            return false;
        }
        mGeographyScore = score;
        return true;
    }
    int MiddleStudent::getGeographyScore() const{
        return mGeographyScore;
    }

    bool MiddleStudent::setHistoryScore(int score){
        if(score < 0 || score > 100){
            cout << "Please enter a scale of 0-100!" << endl;
            return false;
        }
        mHistoryScore = score;
        return true;
    }
    int MiddleStudent::getHisrotyScore() const{
        return mHistoryScore;
    }

    void MiddleStudent::setAddress(std::string address){
        mAddress = address;
    }

    std::string MiddleStudent::getAddress() const{
        return mAddress;
    }

    std::istream& operator>>(std::istream& in, MiddleStudent& stu){
        in >> stu.mStuId;
        in >> stu.mStuName;
        in >> stu.mStuSchool;
        in >> stu.mStuClass;
        in >> stu.mAddress;
        in >> stu.mStuSex;
        in >> stu.mStuAge;
        in >> stu.mChineseScore;
        in >> stu.mEnglishScore;
        in >> stu.mMathScore;
        in >> stu.mGeographyScore;
        in >> stu.mHistoryScore;
        return in;
    }

    std::ostream& operator<<(std::ostream& out, MiddleStudent& stu){
        out << setw(10) << stu.mStuId
            << setw(10) << stu.mStuName
            << setw(10) << stu.mStuSchool
            << setw(10) << stu.mStuClass
            << setw(10) << stu.mAddress
            << setw(10) << stu.mStuSex 
            << setw(10) << stu.mStuAge
            << setw(10) << stu.mChineseScore
            << setw(10) << stu.mEnglishScore
            << setw(10) << stu.mMathScore 
            << setw(10) << stu.mGeographyScore 
            << setw(10) << stu.mHistoryScore 
            << endl;

    }
} // Sh1Yu6

