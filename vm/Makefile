# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 15:29:40 by tle-meur          #+#    #+#              #
#*   Updated: 2016/03/31 19:05:49 by ecousine         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME	=	../corewar

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	add.c aff.c and.c chech_asm.c create_arena.c fork.c ft_parssing.c \
			func_get_val.c game_engine.c instruction.c ld.c ldi.c lfork.c \
			live.c lld.c lldi.c main.c op.c op_arg.c op_arg2.c or.c \
			parse_flags.c parse_players.c place_players.c print_arena.c \
			print_error.c process.c st.c sti.c str_is_digit.c sub.c xor.c \
			zjmp.c lst_del.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			@gcc $(FLAGS) -o $@ -c $< -I includes/ -I ../libft/

$(NAME)	:	$(OBJS)
			@gcc $(FLAGS) -o $@ $^ -L ../libft/ -lft
			@echo "corewar created"

clean	:
			@rm -f $(OBJS)
			@echo "corewar objects deleted"

fclean	:	clean
			@rm -f $(NAME)
			@echo "corewar deleted"

re		:	fclean $(NAME)

.PHONY	:	all clean fclean re
