
/************************************************
#
#      Filename: student.h
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 09:32:21
# Last Modified: 2021-03-12 09:32:21
#***********************************************/

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <string>
namespace Sh1Yu6{

    class Student{
        public:
            Student() = default;
            Student(std::string name, 
                    std::string school,
                    std::string cls,
                    std::string sex,
                    int id, 
                    int age);
            ~Student() = default;
            void setStuName( std::string name );
            std::string getStuName() const;

            void setStuSchool( std::string school );
            std::string getStuSchool() const;

            void setStuClass( std::string cls );
            std::string getStuClass() const;

            void setStuSex( std::string sex );
            std::string getStuSex() const;

            void setStuId( int id );
            int getStuId() const;

            void setStuAge( int age );
            int getStuAge() const;



        protected:
            std::string mStuName;
            std::string mStuSchool;
            std::string mStuClass;
            std::string mStuSex;
            int mStuId;
            int mStuAge;
    };
} // Sh1Yu6

#endif // __STUDENT_H_
