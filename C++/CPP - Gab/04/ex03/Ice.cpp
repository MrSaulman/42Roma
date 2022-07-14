#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(std::string const & type)
{
	this->type = type;
}

Ice::~Ice()
{

}

Ice::Ice(Ice const & obj)
{
	*this = obj;
}

AMateria* Ice::clone() const
{
	AMateria *clone = new Ice(this->type);
	return (clone);
}

Ice& Ice::operator=(const Ice& obj)
{
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << " shoots an ice bolt at " << target.getName() << std::endl;
}