NAME = a.out

FLAGS = -Wall -Wextra -Werror

FILES = main.cpp Zombie.cpp ZombieHorde.cpp

INCLUDE = Zombie.hpp

all:	
	@g++ $(FLAGS) -I$(INCLUDE) $(FILES) -o $(NAME)

clean:	
	@rm $(NAME)

re: clean all