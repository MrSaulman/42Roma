#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* source[4];
	public:
		MateriaSource();
    	~MateriaSource();
		MateriaSource(const MateriaSource& obj);
    	void learnMateria(AMateria*);
    	AMateria* createMateria(std::string const & type);
		MateriaSource& operator=(const MateriaSource& obj);
};

#endif