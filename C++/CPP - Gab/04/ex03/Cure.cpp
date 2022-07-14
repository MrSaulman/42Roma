#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(std::string const & type)
{
	this->type = type;
}

Cure::~Cure()
{

}

Cure::Cure(Cure const & obj)
{
	*this = obj;
}

AMateria* Cure::clone() const
{
	AMateria *clone = new Cure(this->type);
	return (clone);
}

Cure& Cure::operator=(const Cure& obj)
{
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << " heals " << target.getName() << " wounds" << std::endl;
}