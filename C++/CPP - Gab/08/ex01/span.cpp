#include "span.hpp"

Span::Span(void) : _max(0)
{
    //std::cout << "Costructor Span" << std::endl;
}

Span::Span(unsigned int n) : _max(n)
{
    //std::cout << "Costructor Span" << std::endl;
}

Span::~Span(void)
{
    //std::cout << "Destructor Span" << std::endl;
}

Span::Span(const Span &obj)
{
    if (this != &obj)
    {
        this->_max = obj._max;
        this->_vec = obj._vec; 
    }
}

Span &Span::operator=(const Span &obj)
{
    //std::cout << "Costructor Span" << std::endl;
    if (this != &obj)
    {
        this->_max = obj._max;
        this->_vec = obj._vec;
    }
    return (*this);
}

void Span::addNumber(int number)
{
    if (this->_vec.size() >= this->_max)
        throw std::runtime_error("Max numbers error");
    this->_vec.push_back(number);
}

void Span::addNumber(int begin, int end)
{
    if (this->_vec.size() >= this->_max)
        throw std::runtime_error("Max numbers error");
    while (begin <= end)
        this->_vec.push_back(begin++);
    return ;
}

int Span::shortestSpan(void)
{
    if (this->_vec.size() == 0)
        throw std::runtime_error("Error vec is 0 sized");
    if (this->_vec.size() == 1)
        throw std::runtime_error("Error vec is 1 sized");
    std::vector<int> copy = this->_vec;
    std::sort(copy.begin(), copy.end());
    int mini = std::numeric_limits<int>::max();
    for (int i = 0; i < (copy.size() - 1); i++)
    {
        mini = std::min(mini, copy[i+1] - copy[i]);
    }
    return (mini);
}

int Span::longestSpan(void)
{
    if (this->_vec.size() == 0)
        throw std::runtime_error("Error vec is 0 sized");
    if (this->_vec.size() == 1)
        throw std::runtime_error("Error vec is 1 sized");
    std::vector<int> copy = this->_vec;
    std::sort(copy.begin(), copy.end());
    return (copy.back() - copy.front());
}
