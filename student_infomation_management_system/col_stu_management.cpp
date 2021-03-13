
/************************************************
#
#      Filename: col_stu_management.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 18:50:10
# Last Modified: 2021-03-13 19:36:00
#***********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "col_stu_management.h"
#include "college_student.h"
#include "file_name.h"
using namespace std;

namespace Sh1Yu6{

    void ColStuManagement::add(){
        CollegeStudent stu;
        int id;
        int num;
        string str;

        cout << "Please enter student number:";
        cin >> id;
        if( stus.find(id) != stus.end() ){
            cout << "Student numbers already exist!" << endl;
            return;
        }
        stu.setStuId(id);

        cout << "Please enter name:";
        cin >> str;
        stu.setStuName(str);

        cout << "Please enter school:";
        cin >> str;
        stu.setStuSchool(str);

        cout << "Please enter class:";
        cin >> str;
        stu.setStuClass(str);

        cout << "Please enter address:";
        cin >> str;
        stu.setAddress(str);

        cout << "Please enter professional:";
        cin >> str;
        stu.setProfessional(str);

        cout << "Please enter phone number:";
        cin >> str;
        while(!stu.setPhoneNum(str)){
            cin >> str;
        }

        cout << "Please enter gender:";
        cin >> str;
        while(!stu.setStuSex(str)){
            cin >> str;
        }

        cout << "Please enter age:";
        cin >> num;
        while(!stu.setStuAge(num)){
            cin >> num;
        }


        stus.insert(pair<int, CollegeStudent>(stu.getStuId(), stu));
        cout << "Successfully added!" << endl;

    }

    bool ColStuManagement::queryById(int id){
        if(stus.find(id) == stus.end()){
            cout << "The student number cannot be searched!" << endl;
            return false;
        }
        displayTitle();
        cout << stus.find(id)->second;
        return true;
    }

    bool ColStuManagement::queryByName(std::string str){
        bool flag = false;
        int id = -1;
        for(const auto& i: stus){
            if(i.second.getStuName() == str){
                flag = true;
                id = i.first;
            }
        }
        if(!flag){
            cout << "The student number cannot be searched!" << endl;
            return false;
        }
        displayTitle();
        cout << stus.find(id)->second;
        return true;
    }

    void ColStuManagement::display(){
        displayTitle();
        for(auto& i: stus){ 
            cout << i.second;
        }

    }

    void ColStuManagement::edit(){
        int id;
        cin >> id;
        bool flag = queryById(id);
        if(!flag){
            return;
        }

        string str;
        int newId;

        cout << "Whether to modify the student number(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter student number:";
            cin >> newId;
            if( stus.find(newId) != stus.end() ){
                cout << "Student numbers already exist!" << endl;
                return;
            }
            stus.find(id)->second.setStuId(newId);
        }

        cout << "Whether to modify the name(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter name:";
            cin >> str;
            stus.find(id)->second.setStuName(str);
        }

        cout << "Whether to modify the school(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter school:";
            cin >> str;
            stus.find(id)->second.setStuSchool(str);
        }

        cout << "Whether to modify the class(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter class:";
            cin >> str;
            stus.find(id)->second.setStuClass(str);
        }

        cout << "Whether to modify the address(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter Address:";
            cin >> str;
            stus.find(id)->second.setAddress(str);
        }

        cout << "Whether to modify the professional(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter professional:";
            cin >> str;
            stus.find(id)->second.setProfessional(str);
        }

        cout << "Whether to modify the phone number(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter phone number:";
            cin >> str;
            while(!stus.find(id)->second.setPhoneNum(str)){
                cin >> str;
            }
        }

        cout << "Whether to modify the gender(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter gender:";
            cin >> str;
            while(!stus.find(id)->second.setStuSex(str)){
                cin >> str;
            }
        }

        int num = -1;
        cout << "Whether to modify the age(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter age:";
            cin >> num;
            while(!stus.find(id)->second.setStuAge(num)){
                cin >> num;
            }
        }

        stus.insert(pair<int, CollegeStudent>(newId, stus.find(id)->second));
        stus.erase(id);
        cout << "Modified successfully!" << endl;

    }

    void ColStuManagement::del(){
        int id;
        cin >> id;
        bool flag = queryById(id);
        if(!flag){
            return;
        }
        stus.erase(id);
        cout << "Successfully deleted!" << endl;

    }

    void ColStuManagement::statisticsTotal(){
        cout << "The total number of students is " << stus.size() << endl;
    }

    void ColStuManagement::statisticsByGender(){
        int countM = 0;
        int countW = 0;
        for(const auto& i: stus){
            if(i.second.getStuSex() == "man"){
                ++countM;
            }
            if(i.second.getStuSex() == "woman"){
                ++countW;
            }
        }
        cout << "The number of men is " << countM << endl;
        cout << "The number of women is " << countW << endl;
    }

    void ColStuManagement::statisticsByAge(){
        cout << "Please enter the age to be counted:";
        int age;
        int count = 0;
        cin >> age;
        while(age < 0 || age > 120){
            cout << "Please enter a scale of 0-120!" << endl;
            cin >> age;
        }
        for(const auto& i: stus){
            if(i.second.getStuAge() == age){
                ++count;
            }
        }
        cout << "There are " << count << " " << age << "-year-old students" << endl;
    }

    void ColStuManagement::save(){
        ofstream ofs{ collegeStuFile };
        for(auto& i: stus){
            ofs << i.second;
        }
        ofs.close();
    }

    void ColStuManagement::read(){
        ifstream ifs{ collegeStuFile };
        while(!ifs.eof()){
            CollegeStudent stu;
            ifs >> stu;
            if(ifs.fail()){
                break;
            }
            stus.insert(pair<int, CollegeStudent>(stu.getStuId(), stu));
        }
        ifs.close();
    }

    void ColStuManagement::displayTitle(){
        cout << setw(10) << "ID" 
             << setw(10) << "Name" 
             << setw(10) << "School" 
             << setw(10) << "Class" 
             << setw(10) << "Address"
             << setw(10) << "Profes"
             << setw(13) << "PhoneNum"
             << setw(10) << "Sex" 
             << setw(10) << "Age" 
             << endl;
    }

} // Sh1Yu6

