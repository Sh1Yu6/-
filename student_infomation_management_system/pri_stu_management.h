
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
            void query() override;
            void display() override;
            void edit() override;
            void del() override;
            void statistics() override;
            void save() override;
            void read() override;
        private:
            std::unordered_map<int, PrimaryStudent> stus;

    };
} // Sh1Yu6

#endif // __PRI_STU_MANAGEMENT_H_
