
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

namespace Sh1Yu6{

    class StuManagement{
        public:
            //StuManagement() = default;
            virtual ~StuManagement() = default;
            virtual void add() = 0;
            virtual void query() = 0;
            virtual void display() = 0;
            virtual void edit() = 0;
            virtual void del() = 0;
            virtual void statistics() = 0;
            virtual void save() = 0;
            virtual void read() = 0;
    };
} // Sh1Yu6

#endif // __STUDENT_H_
