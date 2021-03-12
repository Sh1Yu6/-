
/************************************************
#
#      Filename: college_student.h
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 10:52:33
# Last Modified: 2021-03-12 10:52:33
#***********************************************/
#ifndef __COLLEGE_STUDENT_H_
#define __COLLEGE_STUDENT_H_
#include "student.h"
namespace Sh1Yu6{
    
    class CollegeStudent: public Student{
        public:
            CollegeStudent() = default;
            CollegeStudent(std::string name, 
                           std::string school,
                           std::string cls,
                           std::string sex,
                           int id, 
                           int age,
                           std::string profess,
                           std::string addr,
                           std::string phoneNum);
            ~CollegeStudent() = default;

            
            void setProfessional(std::string profess);
            std::string getProfessional() const;

            void setAddress(std::string addr);
            std::string getAddress() const;

            void setPhoneNum(std::string phoneNum);
            std::string getPhoneNum() const;
        protected:
            std::string mProfessional;
            std::string mAddress;
            std::string mPhoneNum;
    };
} // Sh1Yu6
#endif // __COLLEGE_STUDENT_H_
