# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 15:29:40 by tle-meur          #+#    #+#              #
#*   Updated: 2016/04/01 14:05:40 by ecousine         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

all		:	asm corewar

asm		:
			@make -C libft/
			@make -C compilo/

corewar	:
			@make -C libft/
			@make -C vm/

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
