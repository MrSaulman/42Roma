NAME = a.out

FLAGS = -Wall -Wextra -Werror

FILES = main.cpp Karen.cpp

INCLUDES = Karen.class.hpp

all:	
	@g++ $(FLAGS) -I$(INCLUDES) $(FILES) -o $(NAME)

clean:	
	@rm $(NAME)

re: clean all