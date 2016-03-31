# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecousine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 14:18:45 by ecousine          #+#    #+#              #
#*   Updated: 2016/03/30 16:24:05 by ecousine         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME=vm_corewar
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
LDFLAGS=-L.
LDLIBS=$(LIBFT_PATH)libft.a
LIBFT_PATH=../libft/
SRC=	add.c \
		aff.c \
		and.c \
		chech_asm.c \
		create_arena.c \
		fork.c \
		ft_parssing.c \
		func_get_val.c \
		game_engine.c \
		instruction.c \
		ld.c \
		ldi.c \
		lfork.c \
		live.c \
		lld.c \
		lldi.c \
		main.c \
		op.c \
		op_arg.c \
		or.c \
		parse_flags.c \
		parse_players.c \
		place_players.c \
		print_arena.c \
		print_error.c \
		process.c \
		st.c \
		sti.c \
		str_is_digit.c \
		sub.c \
		xor.c \
		zjmp.c

OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ)
	cd $(LIBFT_PATH) && $(MAKE)
	$(CC) -o ../$(NAME) $(CFLAGS) $(SRC) $(LDLIBS)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	cd $(LIBFT_PATH) && $(MAKE) $@

fclean: clean
	$(RM) $(NAME)
	cd $(LIBFT_PATH) && $(MAKE) $@

re: fclean all

.PHONY: clean fclean
