#include "Zombie.hpp"

int main(void)
{
	Zombie *ptr;

	ptr = newZombie("Evans");
	ptr->announce();
	randomChump("Criss");
	delete ptr;
}
