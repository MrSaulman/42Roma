#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		this->source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for(int i = 0; i < 4; i++)
		this->source[i] = NULL;
	*this = obj;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->source[i])
			delete this->source[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->source[i])
		{
			this->source[i] = m->clone();
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->source[i])
			break;
		if (this->source[i]->getType() == type)
			return this->source[i]->clone();
	}
	return (NULL);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->source[i])
			delete this->source[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (obj.source[i])
			this->source[i] = obj.source[i]->clone();
	}
	return (*this);
}