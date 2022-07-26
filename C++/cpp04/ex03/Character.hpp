#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* equipment[4];
	public:
		Character();
		Character(std::string const & name);
		Character(const Character& obj);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		Character& operator=(const Character& obj);
};

#endif