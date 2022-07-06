NAME = Account

FLAGS = -Wall -Wextra -Werror

INCLUDE = Account.hpp

all:	
	@g++ $(FLAGS) -I$(INCLUDE) tests.cpp account.cpp -o $(NAME)

clean:	
	@rm $(NAME)

re: clean all
