# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 15:29:40 by tle-meur          #+#    #+#              #
#    Updated: 2016/03/30 16:36:02 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all		:	asm corewar

asm		:
			@make -C libft/
			@make -C compilo/
			@echo "asm created"
			@mv compilo/asm .

corewar	:
			@make -C libft/
			@make -C vm/
			@echo "corewar created"
			@mv vm/corewar .

clean	:
			@make -C vm/ clean
			@make -C libft/ clean
			@make -C compilo/ clean
			@echo "objects deleted"

fclean	:	clean
			@make -C vm/ fclean
			@make -C libft/ fclean
			@make -C compilo/ fclean
			@echo "libft.a, asm and corewar deleted"

re		:	fclean all

.PHONY	:	all asm corewar clean fclean re
