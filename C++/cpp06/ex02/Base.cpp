#include "Base.hpp"

Base::Base()
{
    std::cout << "constructor Base" << std::endl;
}

Base::~Base()
{
    std::cout << "distructor Base" << std::endl;
}

Base *generate(void)
{
    srand(time(NULL));
    uint i = rand()%3;
    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else if (i == 2)
        return new C;
    else
        return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C" << std::endl;
}

void identify(Base& p)
{
    try
	{
		A val;
		val = dynamic_cast<A&>(p);
		std::cout << "Class A" << std::endl;
	}
	catch (const std::exception& e) {}
	try
	{
		B val;
		val = dynamic_cast<B&>(p);
		std::cout << "Class B" << std::endl;
	}
	catch (const std::exception& e) {}
	try
	{
		C val;
		val = dynamic_cast<C&>(p);
		std::cout << "Class C" << std::endl;
	}
	catch (const std::exception& e) {}
}

A::A()
{
    //std::cout << "constructor A" << std::endl;
}

A::~A()
{
    //std::cout << "destructor A" << std::endl;
}

B::B()
{
    //std::cout << "constructor B" << std::endl;
}

B::~B()
{
    //std::cout << "destructor B" << std::endl;
}

C::C()
{
    //std::cout << "constructor C" << std::endl;
}

C::~C()
{
    //std::cout << "destructor C" << std::endl;
}
