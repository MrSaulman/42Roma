NAME = a.out

FLAGS = -Wall -Wextra -Werror

FILES = main.cpp Fixed.cpp

INCLUDES = Fixed.hpp

all:	
	@g++ $(FLAGS) -I$(INCLUDES) $(FILES) -o $(NAME)

clean:	
	@rm $(NAME)

re: clean all