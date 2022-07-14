#include "span.hpp"

int main()
{
    try {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        srand(time(NULL));
        Span test = Span(12000);
        for (int i = 0; i <= 12000; i++) //l'uguale dimostra il max raggiunto(TEST CON E SENZA)
        {
            test.addNumber(rand()%15000);
        }
        std::cout << test.shortestSpan() << std::endl;
        std::cout << test.longestSpan() << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}