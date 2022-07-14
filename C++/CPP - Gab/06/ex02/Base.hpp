#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base {
    public:
        Base();
        virtual ~Base();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

class A : public Base{
    public:
        A();
        virtual ~A();
};

class B : public Base{
    public:
        B();
        virtual ~B();
};

class C : public Base{
    public:
        C();
        virtual ~C();
};

#endif