#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string const & type);
		~Cure();
		Cure(Cure const &);
		AMateria* clone() const;
		Cure& operator=(const Cure& obj);
		void use(ICharacter& target);
};

#endif