#include "Data.hpp"

int main()
{
    Data g(30);
	Data *aftr;

	std::cout << "Start: " << g.getValue() << std::endl;
	uintptr_t t = serialize(&g);
	std::cout << "Serialize: " << t << std::endl;
	aftr = deserialize(t);
	std::cout << "deserialize: " << aftr->getValue() << std::endl;
    std::cout << "Funziona?" << g.getValue() << "==" << aftr->getValue() << std::endl;
    return (0);
}
