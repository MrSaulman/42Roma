#include "Bureaucrat.hpp"

int main()
{
    for (int i = -3; i < 153; ++i)
    {
        try
        {
            Bureaucrat prova("prova", i);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << ": " << i << std::endl;
        }
        
    }
    std::cout << "TEST2---------------------------" << std::endl;
    for (int i = 1; i < 10; ++i) {
        Bureaucrat test("test2", i);
        std::cout << test << std::endl;
    }
}