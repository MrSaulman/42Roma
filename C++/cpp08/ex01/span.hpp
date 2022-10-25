#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
    public:
        Span(void);
        Span(unsigned int n);
        ~Span(void);
        Span(const Span &obj);
        Span &operator=(const Span &obj);

        void addNumber(int number);
        void addNumber(int begin, int end);
        int shortestSpan(void);
        int longestSpan(void);
    private:
        std::vector<int>_vec;
        unsigned int _max;
};

#endif