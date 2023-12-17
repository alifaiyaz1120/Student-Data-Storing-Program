/*
Name: Ali Faiyaz
Class: CSCI 235 - Project 2
Date: 4/3/22
*/

#include "ProjectTwo.h"
#include <sstream>
#include <fstream>
#include <cstring>


std::vector<StudentData> HardDisk::open(std::string fileName)
{
    // reads filename and return the data in a vector of StudentData
        std::ifstream file;
        file.open(fileName);
        unsigned int id;
        std:: string name;
        unsigned short age;

        std::vector<StudentData> data;
        while (file >> id >> name >> age)
        {
           StudentData student(id, name ,age);
           data.push_back(student);
        }
        file.close();
        return data;
}
void HardDisk::save(std::string fileName, std::vector<StudentData*> records)
{
    // takes the students records and saves them to a file, one student per line
        std::ofstream file;
        file.open(fileName);
        for (int i = 0; i < records.size(); i++)
        {
            file << records[i]-> getStudentID() << " " << records[i]-> getName() << " " << records[i]->getAge() << std::endl;
        }
        file.close();
}
