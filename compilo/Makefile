# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 15:29:40 by tle-meur          #+#    #+#              #
#    Updated: 2016/03/31 17:48:43 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	asm

FLAGS	=	-Wall -Wextra -Werror

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
			@gcc $(FLAGS) -o $@ $^ -L ../libft/ -lft
			@echo "$(NAME) created"

clean	:
			@rm -f $(OBJS)
			@echo "$(NAME) objects deleted"

fclean	:	clean
			@rm -f ../$(NAME)
			@echo "$(NAME) deleted"

re		:	fclean $(NAME)

.PHONY	:	all clean fclean re
