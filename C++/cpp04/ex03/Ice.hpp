#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string const & type);
		~Ice();
		Ice(Ice const &);
		AMateria* clone() const;
		Ice& operator=(const Ice& obj);
		void use(ICharacter& target);
};

#endif