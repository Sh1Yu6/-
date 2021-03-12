
/************************************************
#
#      Filename: primary_student.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 10:33:17
# Last Modified: 2021-03-12 22:24:23
#***********************************************/
#include <iostream>
#include "primary_student.h"
using namespace std;

namespace Sh1Yu6{
    
    PrimaryStudent::PrimaryStudent(std::string name, 
                                   std::string school,
                                   std::string cls,
                                   std::string sex,
                                   int id, 
                                   int age,
                                   int chineseScore,
                                   int englisgScore,
                                   int mathScore)
                    : Student(name, school, cls, sex, id, age),
                      mChineseScore{ chineseScore },
                      mEnglishScore{ englisgScore },
                      mMathScore{ mathScore }{
    }

    

    void PrimaryStudent::setChineseScore( int score ){
        mChineseScore = score;
    }
    int PrimaryStudent::getChineseScore() const{
        return mChineseScore;
    }

    void PrimaryStudent::setEnglishScore( int score ){
        mEnglishScore = score;
    }
    int PrimaryStudent::getEnglishScore() const{
        return mEnglishScore;
    }

    void PrimaryStudent::setMathScore( int score ){
        mMathScore = score;
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
        out << stu.mStuId << "\t"
            << stu.mStuName << "\t"
            << stu.mStuSchool << "\t"
            << stu.mStuClass << "\t"
            << stu.mStuSex << "\t" 
            << stu.mStuAge << "\t"
            << stu.mChineseScore << "\t"
            << stu.mEnglishScore << "\t" 
            << stu.mMathScore << endl;
        return out;
    }

} // Sh1Yu6

