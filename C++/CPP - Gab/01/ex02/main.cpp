#include <iostream>

int main()
{
    std::string stringa;
    std::string *stringPTR;
    std::string stringREF;

    stringa = "ciao";
    stringPTR =  &stringa;
    stringREF = stringa;

    std::cout << "address in memory of the string" <<  "==" << "PTR" << std::endl;
    std::cout << &stringa << "==" << stringPTR << std::endl;
    std::cout << "string using the pointer" <<  "==" << "REF" << std::endl;
    std::cout << *stringPTR << "==" << stringREF << std::endl;
    return (0);
}