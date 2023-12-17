/*
Name: Ali Faiyaz
Class: CSCI 235 - Project 2
Date: 4/3/22
*/

#include "ProjectTwo.h"
#include <sstream>
#include <fstream>
#include <cstring>

void MyManager::ProcessCommand(std::vector<std::string> command)
{
    // takes a vector of strings and processes the command
    if (command[0] == "ADD")
    {
       Add(std::stoi(command[1]), command[2], std::stoi(command[3]));
    }
    else if (command[0] == "FIND")
    {  
        if (isdigit(command[3][0])) 
        {
            
            Find(std::stoi(command[3]),command[2], command[1]);
        }
        Find(command[3], command[2]);
    }
    else if (command[0] == "REMOVE")
    {  
        if (isdigit(command[3][0])) 
        {
            
            Remove(std::stoi(command[3]),command[2], command[1]);
        }
        Remove(command[3], command[2]);
    }
    else
    {
       Stop(); //exit 0
    }
    
}
void MyManager::Add(unsigned int student_ID, const std::string& name, unsigned short age)
{
    // student data parameter
    records.push_back(new StudentData(student_ID, name, age));
    HardDisk files;
    files.save("input.txt", records);
}

void MyManager:: Find(std::string field, std::string op)
{
    if (op == ">")
    {
        for (int i = 0 ; i < records.size(); i++)
        {
            if (records[i]->getName() > field)
            {
                std::cout << records[i]->getStudentID() << " ";
                std::cout << records[i]->getName() << " ";
                std::cout << records[i]->getAge() << std::endl;
            }
        }
    }
    else if (op == "<")
    {
        for (int i = 0 ; i < records.size(); i++)
        {
            if (records[i]->getName() < field)
            {
                std::cout << records[i]->getStudentID() << " ";
                std::cout << records[i]->getName() << " ";
                std::cout << records[i]->getAge() << std::endl;
            }
        }
    }
    else if (op == "=")
    {
        for (int i = 0 ; i < records.size(); i++)
        {
            if (records[i]->getName() == field)
            {
                std::cout << records[i]->getStudentID() << " ";
                std::cout << records[i]->getName() << " ";
                std::cout << records[i]->getAge() << std::endl;
            }
        }
    }
}

void MyManager:: Find(unsigned int field, std::string op, std:: string type)
{
    if (op == ">")
    {
        if (type == "id")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getStudentID() > field)
                {
                    std::cout << records[i]->getStudentID() << " ";
                    std::cout << records[i]->getName() << " ";
                    std::cout << records[i]->getAge() << std::endl;
                }
            }
        }
        if (type == "age")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getAge() > field)
                {
                    std::cout << records[i]->getStudentID() << " ";
                    std::cout << records[i]->getName() << " ";
                    std::cout << records[i]->getAge() << std::endl;
                }
            }
        }
        
    }
    else if (op == "<")
    {
        if (type == "id")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getStudentID() < field)
                {
                    std::cout << records[i]->getStudentID() << " ";
                    std::cout << records[i]->getName() << " ";
                    std::cout << records[i]->getAge() << std::endl;
                }
            }
        }
        if (type == "age")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getAge() < field)
                {
                    std::cout << records[i]->getStudentID() << " ";
                    std::cout << records[i]->getName() << " ";
                    std::cout << records[i]->getAge() << std::endl;
                }
            }
        }
        
    }
    else if (op == "=")
    {
        if (type == "id")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getStudentID() == field)
                {
                    std::cout << records[i]->getStudentID() << " ";
                    std::cout << records[i]->getName() << " ";
                    std::cout << records[i]->getAge() << std::endl;
                }
            }
        }
        if (type == "age")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getAge() == field)
                {
                    std::cout << records[i]->getStudentID() << " ";
                    std::cout << records[i]->getName() << " ";
                    std::cout << records[i]->getAge() << std::endl;
                }
            }
        }
        
    }
}
///////////// Remove
void MyManager:: Remove(std::string field, std::string op)
{
    // for each op string < , > , = , equal to the field, remove everything that matches
    // remove the line thats specified by user
    // remove the line inserted from the file
    if (op == ">")
    {
        return;
    }
    else if (op == "<")
    {
        return;
    }
    else if (op == "=")
    {
        for (int i = 0 ; i < records.size(); i++)
        {
            if (records[i]->getName() == field)
            {
                records.erase(records.begin() + i);
                HardDisk files;
                files.save("input.txt", records);
            }
        }
    }

    // deleting the lines of records from the records file
    //HardDisk names;
    //names.save("input.txt" , records);
}

void MyManager:: Remove(unsigned int field, std::string op, std:: string type)
{
    if (op == ">")
    {
        if (type == "id")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getStudentID() > field)
                {
                    records.erase(records.begin() + i);
                    HardDisk files;
                    files.save("input.txt", records);
                }
            }
        }
        if (type == "age")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getAge() > field)
                {
                    records.erase(records.begin() + i);
                    HardDisk files;
                    files.save("input.txt", records);
                }
            }
        }
        
    }
    else if (op == "<")
    {
        if (type == "id")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getStudentID() < field)
                { 
                    records.erase(records.begin() + i);
                    HardDisk files;
                    files.save("input.txt", records);
                }
            }
        }
        if (type == "age")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getAge() < field)
                {
                    records.erase(records.begin() + i);
                    HardDisk files;
                    files.save("input.txt", records);
                }
            }
        }
        
    }
    else if (op == "=")
    {
        if (type == "id")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getStudentID() == field)
                { 
                    records.erase(records.begin() + i);
                    HardDisk files;
                    files.save("input.txt", records);
                }
            }
        }
        if (type == "age")
        {
            for (int i = 0 ; i < records.size(); i++)
            {
                if (records[i]->getAge() == field)
                {
                    records.erase(records.begin() + i);
                    HardDisk files;
                    files.save("input.txt", records);
                }
            }
        }
        
    }
    //HardDisk names;
    //names.save("input.txt" , records);
}

void MyManager::Stop()
{
    exit(0);
}

MyManager::~MyManager()
{
   for (int i = 0 ; i < records.size(); i++)
   {
        delete records[i];
        records[i] = nullptr;
   }    
}

