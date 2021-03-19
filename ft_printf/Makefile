# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 17:13:56 by asalvemi          #+#    #+#              #
#    Updated: 2021/03/15 17:15:16 by asalvemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS += -Wall -Werror -Wextra

LIBOBJS = libft/*.o

SRC = ft_printf.c ft_printf_utils_1.c ft_printf_utils_2.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

lib:
		@$(MAKE) -C libft all
$(NAME): lib
		@$(CC) $(CFLAGS) -c $(SRC)
		@ar rc $(NAME) $(OBJ) $(LIBOBJS)

all: $(NAME)

clean: 
		@rm -f $(OBJ)
		@$(MAKE) -C libft clean

test:
	$(CC) $(CFLAGS) -g -I./ $(SRC) main.c libft/*.c

fclean: clean
		@rm -f $(NAME)
		@$(MAKE) -C libft fclean

re: fclean all

all: $(NAME)
