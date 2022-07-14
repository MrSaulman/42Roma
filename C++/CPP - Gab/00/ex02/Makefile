NAME = a.out

FLAGS = -Wall -Wextra -Werror

FILES = test.cpp Account.cpp

INCLUDE = Account.hpp

all:	
	@g++ $(FLAGS) -I$(INCLUDE) $(FILES) -o $(NAME)

clean:	
	@rm $(NAME)

re: clean all