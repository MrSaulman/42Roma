#ifndef STRING_UTILS_H
# define STRING_UTILS_H

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream> 

class StringManip
{
    public:
        void searchStr();
        void CfileAndW();
        void setSub(std::string sub);
        void setToSub(std::string to_sub);
        void getStrIn(const std::string& path);
        void printInStr();

    private:
        std::string file_name;
        std::string string_in;
        std::string sub;
        std::string to_sub;

};

#endif