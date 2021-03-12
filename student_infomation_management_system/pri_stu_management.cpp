
/************************************************
#
#      Filename: pri_stu_management.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 18:45:48
# Last Modified: 2021-03-12 22:27:03
#***********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "pri_stu_management.h"
#include "primary_student.h"
#include "file_name.h"
#include "student.h"
using namespace std;

namespace Sh1Yu6{

    void PriStuManagement::add(){
        PrimaryStudent stu;
        cin >> stu;
        stus.insert(pair<int, PrimaryStudent>(stu.getStuId(), stu));
        int id;
        int num;

        //cin >> id;
        //string str;
        //ifs >> id;
        //stu.setStuId(id);
        //ifs >> str;
        //stu.setStuName(str);
        //ifs >> str;
        //stu.setStuSchool(str);
        //ifs >> str;
        //stu.setStuClass(str);
        //ifs >> str;
        //stu.setStuSex(str);
        //ifs >> num;
        //stu.setStuAge(num);
    }

    void PriStuManagement::query(){

    }

    void PriStuManagement::display(){
        cout << "学号\t" << "姓名\t" << "学校\t" << "班级\t" 
             << "性别\t" << "年龄\t" << "语文\t" << "英语\t" 
             << "数学\t" << endl;
        for(auto& i: stus){ 
            cout << i.second;
        }
    }

    void PriStuManagement::edit(){

    }

    void PriStuManagement::del(){

    }

    void PriStuManagement::statistics(){

    }

    void PriStuManagement::save(){
        ofstream ofs{ primaryStuFile };
        for(auto& i: stus){
            ofs << i.second;
        }
    }

    void PriStuManagement::read(){
        ifstream ifs{ primaryStuFile };
        while(!ifs.eof()){
            PrimaryStudent stu;
            ifs >> stu;
            if(ifs.fail()){
                break;
            }
            stus.insert(pair<int, PrimaryStudent>(stu.getStuId(), stu));
        }
    }

} // Sh1Yu6

