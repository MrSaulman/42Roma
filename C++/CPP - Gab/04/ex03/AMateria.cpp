#include "AMateria.hpp"

AMateria::AMateria()
{
	
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::~AMateria()
{

}

std::string const & AMateria::getType() const
{
	return (this->type);
}

AMateria::AMateria(const AMateria& obj)
{
	*this = obj;
}

void AMateria::use(ICharacter&)
{

}

AMateria& AMateria::operator=(const AMateria& obj)
{
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	return (*this);
}