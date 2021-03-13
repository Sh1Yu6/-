
/************************************************
#
#      Filename: pri_stu_management.h
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 15:04:01
# Last Modified: 2021-03-12 15:04:01
#***********************************************/

#ifndef __PRI_STU_MANAGEMENT_H_
#define __PRI_STU_MANAGEMENT_H_

#include <unordered_map>
#include "primary_student.h"
#include "student_management.h"
namespace Sh1Yu6{

    class PriStuManagement: public StuManagement{
        public:
            void add() override;
            bool queryById(int id) override;
            bool queryByName(std::string str) override;
            void display() override;
            void edit() override;
            void del() override;
            void statistics(int select) override;
            void save() override;
            void read() override;
        private:
            std::unordered_map<int, PrimaryStudent> stus;
            void displayTitle();
            void statisticsByGender();
            void statisticsByAge();
        };
} // Sh1Yu6

#endif // __PRI_STU_MANAGEMENT_H_
