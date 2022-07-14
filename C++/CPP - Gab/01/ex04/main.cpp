#include "Replace.class.hpp"
#include <cstring>
#include <stdio.h>
#include <string.h>

std::string replacemy(std::string str, int start, int lenght, std::string copy)
{
    std::string s;

    if (lenght < 0)
        return (NULL);
    s = str.substr(0, start);
    s.append(copy);
    if (str.length() != (lenght + start))
        s.append(str.substr(lenght + start, str.length()));
    return (s);
}

void ReplaceText(std::string filename, std::string s1, std::string s2)
{
    std::string str;
    std::ifstream MyReadFile(filename);
    std::ifstream s1File(s1);
    std::ifstream s2File(s2);
    std::string Str1;
    std::string Str2;
    std::string creaFile;

    if (MyReadFile.fail())
    {
        std::cout << "Error reading file" << std::endl;
        return ;
    }
    creaFile = filename + ".replace";
    std::cout << creaFile << std::endl;
    std::ofstream MyFile(creaFile);
    if (MyFile.fail())
    {
        std::cout << "Error creating file" << std::endl;
        return ;
    }
    std::getline(s1File,Str1);
    std::getline(s2File,Str2);
    while (std::getline(MyReadFile, str)) {
        while (str.find(Str1) != std::string::npos)
        {
            str = replacemy(str, str.find(Str1), Str1.length(), Str2);
        }
        MyFile << str;
        MyFile << std::endl;
    }
    if (str == "")
    {
        MyFile << std::endl;
    }
    MyFile.close();
    MyReadFile.close();
    return ;
}


int main(int argc, char **argv)
{   
    std::string filename;
    std::string s1;
    std::string s2;
    if (argc != 4)
    {
        std::cout << "Errore dati" << std::endl;
        return (1);
    }
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    ReplaceText(filename, s1, s2);
    return (0);
}