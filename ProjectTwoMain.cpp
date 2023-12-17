/*
Name: Ali Faiyaz
Class: CSCI 235 - Project 2
Date: 4/3/22
*/

#include <string>
#include <vector>
#include <iostream>
#include "ProjectTwo.h"
  
int main() 
  {
    MyManager engine;
    MyParser parser;
    std::string line;
    std::vector <std::string> words;
    while(getline(std::cin, line)) 
    {
        words = parser(line);
        if (words[0] == "STOP")
        {
            break;
        }
        engine.ProcessCommand(words);
        words.clear();
        line = "";
    }
    
  return 0;
  }
//Command to run
// g++  -std=c++17  ProjectTwoMain.cpp  -o application
// ./application


    


