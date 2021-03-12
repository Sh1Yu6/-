
/************************************************
#
#      Filename: primary_student.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 10:33:17
# Last Modified: 2021-03-12 10:38:59
#***********************************************/
#include <iostream>
#include "primary_student.h"
using namespace std;

namespace Sh1Yu6{
    
    PrimaryStudent::PrimaryStudent(int chineseScore,
                                   int englisgScore,
                                   int mathScore)
                   : mChineseScore{ chineseScore },
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

} // Sh1Yu6

