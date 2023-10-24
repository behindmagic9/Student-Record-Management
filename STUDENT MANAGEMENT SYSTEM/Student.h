#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include <exception>
#include <stdexcept>
#include<limits>
using namespace std;
class student{

    string sname{};
    int long long roll_no{};
    float grade{};
    string fath_name{};

public:
    student() = default;
    student(int long long roll_num, string name ,string fat_nm, float grd);
    vector<student> Students;
    vector<student*> pt;
    ~student();

    const string &getFathName() const {return fath_name;}
    int long long get_roll_no() const { return roll_no; }
    float getGrade() const { return grade; }
    string get_name() const { return sname; }

    void setFathName(const string &fathName) { this->fath_name = fathName; }
    void set_roll_no(int long long roll_num) { this->roll_no = roll_num; }
    void set_name(string name) { this->sname = name; }
    void setGrade(float grades) { this->grade = grades; }


    void display(){
        cout << "the name of student is " << get_name() << " roll number is " << get_roll_no() <<
        " his grade are " << getGrade() << "fathers name is " <<  getFathName() << " \n";
    }

    void add();

	void update();

    static std::vector<student> loadStudentData(const std::string& filename,std::vector<student> &students);
};
void view();
void viewall() ;
void dlt() ;
int long long searchh();
int getCurrentLine(std::istream& is);
int deleteCurrentLine(std::istream& is,int n);

#endif
