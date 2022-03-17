NAME		= pipex

SRCS_DIR	= ./srcs
SRCS_NAME	= 	main.c \
				ft_split.c \
				ft_strjoin.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS		= $(SRCS:.c=.o)
HEADER		= include

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf

all :		$(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) -I $(HEADER) $^ -o $@

clean :
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean :	clean
			make clean
			$(RM) $(NAME)

re :		fclean all