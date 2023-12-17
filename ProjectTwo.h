/*
Name: Ali Faiyaz
Class: CSCI 235 - Project 2
Date: 4/3/22
*/

#ifndef PROJECTTWO
#define PROJECTTWO

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cassert>

class MyParser
{
    public:
        std::vector<std::string> operator()(const std::string& user_input); // const reference
        // takes a string 
        // put every word in the string
};
class StudentData // special manager class 
{
    public: 
        StudentData(unsigned int studentID, const std::string& name, unsigned short age);
        // string can be constant reference
        std::string getName() const;
        int getStudentID() const;
        short getAge() const;
        
    private:
        unsigned int studentID_; 
        std::string name_;
        unsigned short age_;
};
class MyManager
{
    public:
        void ProcessCommand(std::vector<std::string> command);
        
        void Add(unsigned int student_ID, const std::string& name, unsigned short age);
        void Find(std::string field, std::string op);
        void Find(unsigned int field, std::string op , std:: string type);
        void Remove(std::string field, std::string op);
        void Remove(unsigned int field, std::string op , std:: string type);
        void Stop();
        ~MyManager(); // destructor
    private:
        std::vector<StudentData*> records;
};

class HardDisk
{
    public:
        std::vector<StudentData> open(std::string fileName);
        void save(std::string fileName, std::vector<StudentData*> records);
};
#include "StudentData.cpp"
#include "MyManager.cpp"
#include "HardDisk.cpp"
#include "Parser.cpp"
#endif 