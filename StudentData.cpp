/*
Name: Ali Faiyaz
Class: CSCI 235 - Project 2
Date: 4/3/22
*/

#include "ProjectTwo.h"
#include <sstream>
#include <fstream>
#include <cstring>

StudentData::StudentData(unsigned int student_ID, const std::string& name, unsigned short age)
{
    studentID_ = student_ID;
    name_= name;
    age_ = age;
}
std::string StudentData:: getName() const
{
    return name_;
}
int StudentData::getStudentID() const
{
    return studentID_;
}
short StudentData::getAge() const
{
    return age_;
}
