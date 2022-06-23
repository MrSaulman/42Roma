NAME = Account

FLAGS = -Wall -Wextra -Werror

INCLUDE = Account.hpp

all:	
	@g++ $(FLAGS) -I$(INCLUDE) test.cpp account.cpp -o $(NAME)

clean:	
	@rm $(NAME)

re: clean all
