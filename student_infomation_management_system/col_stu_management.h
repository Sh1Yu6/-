
/************************************************
#
#      Filename: col_stu_management.h
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 15:08:41
# Last Modified: 2021-03-12 15:08:41
#***********************************************/


#ifndef __COL_STU_MANAGEMENT_H_
#define __COL_STU_MANAGEMENT_H_

#include <unordered_map>
#include "student_management.h"
#include "college_student.h"

namespace Sh1Yu6{

    class ColStuManagement: public StuManagement{
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
            std::unordered_map<int, CollegeStudent> stus;
    };
} // Sh1Yu6

#endif // __Col_STU_MANAGEMENT_H_
