
/************************************************
#
#      Filename: interface.h
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 11:30:29
# Last Modified: 2021-03-12 11:30:29
#***********************************************/
#ifndef __INTERFACE_H_
#define __INTERFACE_H_
#include "student_management.h"
namespace Sh1Yu6{

    class Interface{
        public:

        void mainFace();

        void selectFace(StuManagement*& stuManage);

        private:

        int mainMenu();

        int selectMenu();

        void addMenu();

        int queryMneu();

        void displayMenu();

        void editMenu();

        void deleteMenu();

        int statisticsMenu();

        void waitInput();

    };

} // Sh1Yu6
#endif // __INTERFACE_STUDENT_H_
