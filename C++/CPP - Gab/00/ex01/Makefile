NAME = phonebook

FLAGS = -Wall -Wextra -Werror

FILES = phonebook.cpp showPhoneBook.cpp addContract.cpp contactClass.cpp

INCLUDE = contactClass.hpp

all:	
	@g++ $(FLAGS) -I$(INCLUDE) $(FILES) -o $(NAME)

clean:	
	@rm $(NAME)

re: clean all