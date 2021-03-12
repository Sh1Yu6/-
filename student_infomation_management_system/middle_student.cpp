
/************************************************
#
#      Filename: middle_student.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 10:46:10
# Last Modified: 2021-03-12 15:25:53
#***********************************************/
#include <iostream>
#include "middle_student.h"
using namespace std;

namespace Sh1Yu6{
    
    MiddleStudent::MiddleStudent(std::string name, 
                                 std::string school,
                                 std::string cls,
                                 std::string sex,
                                 int id, 
                                 int age,
                                 int chineseScore,
                                 int englisgScore,
                                 int mathScore,
                                 int geographyScore,
                                 int historyScore,
                                 std::string addr)
                :PrimaryStudent(name, school, cls, sex, id, age, chineseScore,
                                englisgScore, mathScore),
                 mGeographyScore{ geographyScore },
                 mHistoryScore{ historyScore },
                 mAddress{ addr }{

    }

    void MiddleStudent::setGeographyScore(int score){
        mGeographyScore = score;
    }
    int MiddleStudent::getGeographyScore() const{
        return mGeographyScore;
    }

    void MiddleStudent::setHistoryScore(int score){
        mHistoryScore = score;
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
} // Sh1Yu6

