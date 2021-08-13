
/************************************************
#
#      Filename: pri_stu_management.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 18:45:48
# Last Modified: 2021-04-25 15:56:32
#***********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "pri_stu_management.h"
#include "primary_student.h"
#include "file_name.h"
using namespace std;

namespace Sh1Yu6{
    void PriStuManagement::add(){
        PrimaryStudent stu;
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

        cout << "Please enter Chinese score:";
        cin >> num;
        while(!stu.setChineseScore(num)){
            cin >> num;
        }

        cout << "Please enter English score:";
        cin >> num;
        while(!stu.setEnglishScore(num)){
            cin >> num;
        }

        cout << "Please enter Math score:";
        cin >> num;
        while(!stu.setMathScore(num)){
            cin >> num;
        }

        stus.insert(pair<int, PrimaryStudent>(stu.getStuId(), stu));
        cout << "Successfully added!" << endl;
    }

    bool PriStuManagement::queryById(int id){
        if(stus.find(id) == stus.end()){
            cout << "The student number cannot be searched!" << endl;
            return false;
        }
        displayTitle();
        cout << stus.find(id)->second;
        return true;
    }

    bool PriStuManagement::queryByName(std::string str){
        bool flag = false;
        int id = -1;
        for(const auto& i: stus){
            if(i.second.getStuName() == str){
                flag = true;
                id = i.first;
            }
        }
        if(!flag){
            cout << "The name cannot be searched!" << endl;
            return false;
        }
        displayTitle();
        cout << stus.find(id)->second;
        return true;
    }

    void PriStuManagement::display(){
        displayTitle();
        for(auto& i: stus){ 
            cout << i.second;
        }
    }

    void PriStuManagement::edit(){

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
        cout << "Whether to modify Chinese score(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter Chinese score:";
            cin >> num;
            while(!stus.find(id)->second.setChineseScore(num)){
                cin >> num;
            }
        }

        cout << "Whether to modify English score(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter English score:";
            cin >> num;
            while(!stus.find(id)->second.setEnglishScore(num)){
                cin >> num;
            }
        }

        cout << "Whether to modify Math score(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter Math score:";
            cin >> num;
            while(!stus.find(id)->second.setMathScore(num)){
                cin >> num;
            }
        }
        stus.insert(pair<int, PrimaryStudent>(newId, stus.find(id)->second));
        stus.erase(id);
        cout << "Modified successfully!" << endl;
    }

    void PriStuManagement::del(){
        int id;
        cin >> id;
        bool flag = queryById(id);
        if(!flag){
            return;
        }
        stus.erase(id);
        cout << "Successfully deleted!" << endl;
    }

    void PriStuManagement::statisticsTotal(){
        cout << "The total number of students is " << stus.size() << endl;
    }

    void PriStuManagement::statisticsByGender(){
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

    void PriStuManagement::statisticsByAge(){
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


    void PriStuManagement::save(){
        ofstream ofs{ primaryStuFile };
        for(auto& i: stus){
            ofs << i.second;
        }
        ofs.close();
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
        ifs.close();
    }

    void PriStuManagement::displayTitle(){
        cout << setw(10) << "ID" 
             << setw(10) << "Name" 
             << setw(10) << "School" 
             << setw(10) << "Class" 
             << setw(10) << "Sex" 
             << setw(10) << "Age" 
             << setw(10) << "Chinese" 
             << setw(10) << "English" 
             << setw(10) << "Math" 
             << endl;
    }

} // Sh1Yu6

