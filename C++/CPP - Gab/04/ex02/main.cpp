#include "Cat.hpp"
#include "Dog.hpp"

int main() 
{
//	Animal animal;
	


	Animal *array[4];
	for(int i = 0; i < 4; i++)
	{
		std::cout << "-------Create---------" << std::endl;
		if (i % 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	std::cout << "----------------------" << std::endl;
	for(int i = 0; i < 4; i++)
		array[i]->makeSound();
	for(int i = 0; i < 4; i++)
	{
		std::cout << "-------Delete--------" << std::endl;
		delete array[i];
	}
	std::cout << "----------------------" << std::endl;
}