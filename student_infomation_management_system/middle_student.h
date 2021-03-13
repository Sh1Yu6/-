
/************************************************
#
#      Filename: middle_student.h
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 10:39:42
# Last Modified: 2021-03-12 10:39:42
#***********************************************/

#ifndef __MIDDLE_STUDENT_H_
#define __MIDDLE_STUDENT_H_
#include "primary_student.h"
namespace Sh1Yu6{
    
    class MiddleStudent: public PrimaryStudent{
        friend std::istream& operator>>(std::istream& in, MiddleStudent& stu);
        friend std::ostream& operator<<(std::ostream& out, MiddleStudent& stu);
        public:
            bool setGeographyScore(int score);
            int getGeographyScore() const;

            bool setHistoryScore(int score);
            int getHisrotyScore() const;

            void setAddress(std::string address);
            std::string getAddress() const;

        protected:
            int mGeographyScore;
            int mHistoryScore;
            std::string mAddress;
    };
} // Sh1Yu6
#endif // __MIDDLE_STUDENT_H_
