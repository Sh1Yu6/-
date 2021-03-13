
/************************************************
#
#      Filename: student_management.h
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 15:02:53
# Last Modified: 2021-03-12 15:02:53
#***********************************************/

#ifndef __STUDENT_MANAGEMENT_H_
#define __STUDENT_MANAGEMENT_H_

#include <string>
#include <unordered_map>
#include "primary_student.h"
#include "middle_student.h"
#include "college_student.h"
namespace Sh1Yu6{

    class StuManagement{
        public:
            virtual ~StuManagement() = default;

            virtual void add() = 0;

            void query(int select);

            virtual bool queryById(int id) = 0;

            virtual bool queryByName(std::string str) = 0;

            virtual void display() = 0;

            virtual void edit() = 0;

            virtual void del() = 0;

            void statistics(int select);

            virtual void statisticsTotal() = 0;

            virtual void statisticsByGender() = 0;

            virtual void statisticsByAge() = 0;

            virtual void save() = 0;

            virtual void read() = 0;
    };
} // Sh1Yu6

#endif // __STUDENT_H_
