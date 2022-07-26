NAME = Polymorphism

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

HEADER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

OBJS = $(SRCS:cpp=o)

%.o:        %.cpp $(HEADER)
			${CLANG} $(CPPFLAGS) -c $< -o ${<:.cpp=.o}

CLANG =     clang++

CPPFLAGS =  -Wall -Wextra -Werror -std=c++98

RM =        rm -f

all :       ${NAME}

$(NAME) :   $(OBJS) 
			$(CLANG) $(CPPFLAGS) -o ${NAME} $(OBJS) -I.

clean :     
			$(RM) $(OBJS)

fclean  :   clean
			$(RM) ${NAME}

re :        fclean all

.PHONY :    all clean fclean re