#include "Base.hpp"

int main()
{
    Base *test;
    test = generate();
    identify(*test);
    identify(test);
}