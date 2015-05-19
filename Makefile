# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 17:26:08 by cfriot            #+#    #+#              #
#    Updated: 2015/04/02 19:47:59 by cfriot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computorV1

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = computor.c \
	  ft_get_coef.c  \
	  ft_get_pow.c  \
	  ft_tab_tools.c \
	  ft_sqrt.c \
	  ft_resolve.c \
	  ft_display.c \
	  ft_tools_list.c \
	  ft_delete.c \
	  ft_error.c \
	  ft_ini_magic.c

OBJ = $(SRC:.c=.o)

.PHONY: all libft clean fclean re

all : libft $(NAME)

$(NAME):  $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a 
	@echo "!"
	@echo "$(NAME) compiled\033[0m"

libft :
	@make -C libft/

%.o : %.c
	@$(CC) -c $(CFLAGS) -I./includes/ -I./libft/includes $<
	@printf "\033[32m."

clean :
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)
	@echo "\033[31mcomputor objects deleted\033[0m"

fclean : allclean
	@/bin/rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\033[0m"

allclean :
	@make -C libft/ fclean
	@/bin/rm -f $(OBJ)
	@echo "\033[31mcomputor objects deleted\033[0m"

re : fclean all
