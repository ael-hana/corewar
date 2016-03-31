# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 15:29:40 by tle-meur          #+#    #+#              #
#    Updated: 2016/03/31 17:40:31 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all		:	asm corewar

asm		:
			@make -C libft/
			@make -C compilo/
			@mv compilo/asm .

corewar	:
			@make -C libft/
			@make -C vm/
			@mv vm/corewar .

clean	:
			@make -C vm/ clean
			@make -C libft/ clean
			@make -C compilo/ clean

fclean	:	clean
			@make -C vm/ fclean
			@make -C libft/ fclean
			@make -C compilo/ fclean

re		:	fclean all

.PHONY	:	all asm corewar clean fclean re
