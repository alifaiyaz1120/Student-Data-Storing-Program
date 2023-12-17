/*
Name: Ali Faiyaz
Class: CSCI 235 - Project 2
Date: 4/3/22
*/

#include "ProjectTwo.h"
#include <sstream>
#include <fstream>
#include <cstring>

std::vector<std::string> MyParser::operator()(const std::string& user_input)
{
    std::string word;
    std::vector<std::string> words;

    //getline(std::cin, overide); 
    std::stringstream stream(user_input); // storing the string to stringstream

    while (stream >> word)
    {
        words.push_back(word);
    }
    
    if (words[0] == "ADD")
    {
        if (words.size() == 5)
        {   
             // count if there multiple quotes in the string  
               words[2] += ' ';
               words[2] = words[2]+ words[3];
               words[3] = words[4];
               for (int i = 0; i < words.size(); i++)
                    {
                        if (words[i][0] == '\"' && words[i][words[i].size()-1] == '\"')
                        {
                            words[i] = words[i].substr(1, words[i].size()-2);
                        }
                    }
               words.pop_back();
               return words;            
            
        }
    
        if (words.size() == 4)
        {
                int count = 0;
                for (int i = 0; i < words.size(); i++)
                {
                    for (int j = 0; j < words[i].size(); j++)
                    {
                        if (words[i][j] == '\"')
                        {
                            count++;
                        }
                    }
                }
                if (count > 2)
                {
                        std:: cout << "bad command!!!" << std::endl;
                }

            for (int i = 0; i < words.size(); i++)
            {
                for(int j=0; j < words[i].size(); j++)
                {
                    if (words[i][j] == ' ')
                    {
                        words.pop_back();
                        return words;
                    }
                    // if [i][j] has a quote, delete the quote
                    if (words[i][j] == '"')
                    {
                        words[i].erase(j, 1);
                    }       
                }
            }
            
        }  
    }
    if (words[0] == "FIND")
    {
        std:: string finder = "";
        for(int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (words[i][j] == '>' || words[i][j] == '<' || words[i][j] == '=')
                {
                    finder+= words[i][j];
                }

            }
        }
        if (finder.length() == 2)
        {
            std::cout << "Invaild" << std::endl;
            exit(0);
        }        
        if (words.size() == 4)
        {
            return words;
        }  
        else if (words.size() == 3)
        {
            for (int i = 0; i < words.size(); i++)
            {
                for (int j= 0 ; j < words[i].size(); j++)
                {
                    // if words[i][j] is equal to an operator ">", "<", "=", then spit that current word into two pieces
                    if (words[i][j] == '>' || words[i][j] == '<' || words[i][j] == '=')
                    {
                        std::string op = "";    
                        op += words[i][j];
                        words.push_back(op);
                        words[i].erase(j, 1);
                        words[words.size()-1] = words[words.size()-2]; 
                        words[words.size()-2] = op;
                        return words;
                    } 
                }                 
            }
         }
         else if (words.size() == 2)
         {
             for (int i = 0; i < words.size(); i++)
             {
                for (int j = 0 ; j < words[i].size(); j++)
                {
                    if (words[i][j] == '>' || words[i][j] == '<' || words[i][j] == '=')
                    {
                        
                        std::string op = words[i].substr(j);// going j to the end 
                        words.push_back(op);
                        op = words[i].substr(j+1);
                        words.push_back(op);
                        words[1].erase(j);
                        //int index = words[2].find(op);
                        words[2].erase(1);
                        return words;
                    }
                }

             }
         }
    }
    if (words[0] == "REMOVE")
    {
        std:: string finder = "";
        for(int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (words[i][j] == '>' || words[i][j] == '<' || words[i][j] == '=')
                {
                    finder+= words[i][j];
                }

            }
        }
        if (finder.length() == 2)
        {
            std::cout << "Invaild" << std::endl;
            exit(0);
        }        
        if (words.size() == 4)
        {
            return words;
        }  
        else if (words.size() == 3)
        {
            for (int i = 0; i < words.size(); i++)
            {
                for (int j= 0 ; j < words[i].size(); j++)
                {
                    // if words[i][j] is equal to an operator ">", "<", "=", then spit that current word into two pieces
                    if (words[i][j] == '>' || words[i][j] == '<' || words[i][j] == '=')
                    {
                        std::string op = "";    
                        op += words[i][j];
                        words.push_back(op);
                        words[i].erase(j, 1);
                        words[words.size()-1] = words[words.size()-2]; 
                        words[words.size()-2] = op;
                        return words;
                    }      
                }                 
            }
         }
         else if (words.size() == 2)
         {
             for (int i = 0; i < words.size(); i++)
             {
                for (int j = 0 ; j < words[i].size(); j++)
                {
                    if (words[i][j] == '>' || words[i][j] == '<' || words[i][j] == '=')
                    {
                        
                        std::string op = words[i].substr(j);// going j to the end 
                        words.push_back(op);
                        op = words[i].substr(j+1);
                        words.push_back(op);
                        words[1].erase(j);
                        //int index = words[2].find(op);
                        words[2].erase(1);
                        return words;
                    }
                }

             }
         }
    }
    if (words[0] == "STOP")
    {
       exit(0); 
    }
    return words;
    
}