# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 11:01:17 by gcrocett          #+#    #+#              #
#    Updated: 2022/03/12 18:41:51 by asalvemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

SRC = 	./src/check_error0.c \
		./src/check_error1.c \
		./src/ft_atoi.c \
		./src/list_utils0.c \
		./src/list_utils1.c \
		./src/list_utils2.c \
		./src/split.c \
		./src/algorithms.c \
		./src/algorithms_2.c \
		./src/parse_algo.c \
		./src/alg_operations.c \
		./src/alg_operations_2.c \
		./src/inizialize_stack.c \
		./src/do_operations.c \
		./src/get_next_line.c \
		./src/gnl_utils.c \
		./src/gnl_utils1.c \
		./src/ft_calloc.c \
		./src/frees.c \
		./src/utils0.c \


PSRC = src/push_swap.c

INC = inc

GCC = gcc
CFLAGS = -Wall -Wextra -Werror


all: $(PUSH_SWAP)

$(PUSH_SWAP):

	$(GCC) $(CFLAGS) -o $(PUSH_SWAP) $(SRC) $(PSRC) -I $(INC)

fclean:
	$(RM) $(PUSH_SWAP)

re:	fclean all
