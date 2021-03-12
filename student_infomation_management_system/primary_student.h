
/************************************************
#
#      Filename: primary_student.h
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 10:22:02
# Last Modified: 2021-03-12 10:22:02
#***********************************************/

#ifndef __PRIMARY_STUDENT_H_
#define __PRIMARY_STUDENT_H_
#include "student.h"
namespace Sh1Yu6{
    
    class PrimaryStudent: public Student{
        public:
            PrimaryStudent() = default;
            PrimaryStudent(int chineseScore,
                           int englisgScore,
                           int mathScore);
            ~PrimaryStudent() = default;
            void setChineseScore( int score );
            int getChineseScore() const;

            void setEnglishScore( int score );
            int getEnglishScore() const;

            void setMathScore( int score );
            int getMathScore();

        protected:
            int mChineseScore;
            int mEnglishScore;
            int mMathScore;
    };
} // Sh1Yu6
#endif // __PRIMARY_STUDENT_H_
