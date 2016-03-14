# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 15:29:40 by tle-meur          #+#    #+#              #
#    Updated: 2016/03/11 18:53:18 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	./asm

FLAGS	=	-g -Wall -Wextra -Werror

SRCS	=	srcs/op.c srcs/main.c srcs/compute.c srcs/lst_funcs.c \
			srcs/utilities.c \
			srcs/checks/read_file.c srcs/checks/check_instru.c \
			srcs/checks/check_arg.c \
			srcs/fill/compilo.c srcs/fill/write_in_file.c \
			srcs/fill/write_steps.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			@gcc $(FLAGS) -o $@ -c $< -I includes/ -I ../libft/

$(NAME)	:	$(OBJS)
			@make -C ../libft/ simple
			@echo "libft.a created"
			@gcc $(FLAGS) -o $@ $^ -L ../libft/ -lft
			@echo "$(NAME) created"
clean	:
			@rm -f $(OBJS)
			@make -C ../libft/ clean
			@echo "objects deleted"

fclean	:	clean
			@make -C ../libft/ fclean
			@rm -f $(NAME)
			@echo "$(NAME) libft.a deleted"

re		:	fclean $(NAME)

simple	:	re
			@rm -f $(OBJS)
			@make -C ../libft/ clean
			@echo "objects deleted"

.PHONY	:	all clean fclean re simple
