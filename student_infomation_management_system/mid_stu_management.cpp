
/************************************************
#
#      Filename: mid_stu_management.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-12 18:48:11
# Last Modified: 2021-03-13 19:35:00
#***********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "middle_student.h"
#include "mid_stu_management.h"
#include "file_name.h"
using namespace std;

namespace Sh1Yu6{


    void MidStuManagement::add(){
        MiddleStudent stu;
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


        cout << "Please enter Address:";
        cin >> str;
        stu.setAddress(str);

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

        cout << "Please enter Geography score:";
        cin >> num;
        while(!stu.setGeographyScore(num)){
            cin >> num;
        }

        cout << "Please enter Hisroty score:";
        cin >> num;
        while(!stu.setHistoryScore(num)){
            cin >> num;
        }

        stus.insert(pair<int, MiddleStudent>(stu.getStuId(), stu));
        cout << "Successfully added!" << endl;

    }
    
    bool MidStuManagement::queryById(int id){
        if(stus.find(id) == stus.end()){
            cout << "The student number cannot be searched!" << endl;
            return false;
        }
        displayTitle();
        cout << stus.find(id)->second;
        return true;
    }

    bool MidStuManagement::queryByName(std::string str){
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

    void MidStuManagement::display(){
        displayTitle();
        for(auto& i: stus){ 
            cout << i.second;
        }

    }

    void MidStuManagement::edit(){

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

        cout << "Whether to modify Geography score(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter Geography score:";
            cin >> num;
            while(!stus.find(id)->second.setGeographyScore(num)){
                cin >> num;
            }
        }

        cout << "Whether to modify Hisroty score(y/n)?";
        cin >> str;
        if(str == "y"){
            cout << "Please enter Hisroty score:";
            cin >> num;
            while(!stus.find(id)->second.setHistoryScore(num)){
                cin >> num;
            }
        }

        stus.insert(pair<int, MiddleStudent>(newId, stus.find(id)->second));
        stus.erase(id);
        cout << "Modified successfully!" << endl;

    }

    void MidStuManagement::del(){
        int id;
        cin >> id;
        bool flag = queryById(id);
        if(!flag){
            return;
        }
        stus.erase(id);
        cout << "Successfully deleted!" << endl;

    }

    void MidStuManagement::statisticsTotal(){
        cout << "The total number of students is " << stus.size() << endl;
    }

    void MidStuManagement::statisticsByGender(){
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

    void MidStuManagement::statisticsByAge(){
        cout << "Please enter the age to be counted:" << endl;
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

    void MidStuManagement::save(){
        ofstream ofs{ middleStuFile };
        for(auto& i: stus){
            ofs << i.second;
        }
        ofs.close();
    }

    void MidStuManagement::read(){
        ifstream ifs{ middleStuFile };
        while(!ifs.eof()){
            MiddleStudent stu;
            ifs >> stu;
            if(ifs.fail()){
                break;
            }
            stus.insert(pair<int, MiddleStudent>(stu.getStuId(), stu));
        }
        ifs.close();
    }

    void MidStuManagement::displayTitle(){
        cout << setw(10) << "ID" 
             << setw(10) << "Name" 
             << setw(10) << "School" 
             << setw(10) << "Class" 
             << setw(10) << "Address"
             << setw(10) << "Sex" 
             << setw(10) << "Age" 
             << setw(10) << "Chinese" 
             << setw(10) << "English" 
             << setw(10) << "Math" 
             << setw(10) << "Geography" 
             << setw(10) << "History" 
             << endl;

    }

} // Sh1Yu6

