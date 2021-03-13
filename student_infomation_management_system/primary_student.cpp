
/************************************************
#
#      Filename: primary_student.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 10:33:17
# Last Modified: 2021-03-13 09:28:01
#***********************************************/
#include <iostream>
#include <iomanip>
#include "primary_student.h"
using namespace std;

namespace Sh1Yu6{
    
    bool PrimaryStudent::setChineseScore( int score ){
        if(score < 0 || score > 100){
            cout << "Please enter a scale of 0-100!" << endl;
            return false;
        }
        mChineseScore = score;
        return true;
    }
    int PrimaryStudent::getChineseScore() const{
        return mChineseScore;
    }

    bool PrimaryStudent::setEnglishScore( int score ){
        if(score < 0 || score > 100){
            cout << "Please enter a scale of 0-100!" << endl;
            return false;
        }
        mEnglishScore = score;
        return true;
    }
    int PrimaryStudent::getEnglishScore() const{
        return mEnglishScore;
    }

    bool PrimaryStudent::setMathScore( int score ){
        if(score < 0 || score > 100){
            cout << "Please enter a scale of 0-100!" << endl;
            return false;
        }
        mMathScore = score;
        return true;
    }
    int PrimaryStudent::getMathScore(){
        return mMathScore;
    }

    std::istream& operator>>(std::istream& in, PrimaryStudent& stu){
        in >> stu.mStuId;
        in >> stu.mStuName;
        in >> stu.mStuSchool;
        in >> stu.mStuClass;
        in >> stu.mStuSex;
        in >> stu.mStuAge;
        in >> stu.mChineseScore;
        in >> stu.mEnglishScore;
        in >> stu.mMathScore;
        return in;
    }

    std::ostream& operator<<(std::ostream& out, PrimaryStudent& stu){
        out << setw(10) << stu.mStuId
            << setw(10) << stu.mStuName
            << setw(10) << stu.mStuSchool
            << setw(10) << stu.mStuClass
            << setw(10) << stu.mStuSex 
            << setw(10) << stu.mStuAge
            << setw(10) << stu.mChineseScore
            << setw(10) << stu.mEnglishScore
            << setw(10) << stu.mMathScore 
            << endl;
        return out;
    }

} // Sh1Yu6

