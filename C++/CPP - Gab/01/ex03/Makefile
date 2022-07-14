NAME = a.out

FLAGS = -Wall -Wextra -Werror

FILES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp 

INCLUDE = HumanA.hpp HumanB.hpp Weapon.hpp

all:	
	@g++ $(FLAGS) -I$(INCLUDE) $(FILES)

clean:	
	@rm *.gch
	@rm $(NAME)

re: clean all