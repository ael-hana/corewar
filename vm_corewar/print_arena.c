/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:16:08 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/14 17:43:22 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	print_player_introduction(t_list *player_list)
{
	t_list		*current_player;
	t_header	*player;

	current_player = player_list;
	while (current_player)
	{
		player = current_player->content;
		ft_printf("* Player %d, weighing %d bytes, \"%s\"",
			player->n, player->prog_size, player->prog_name);
		ft_printf(" (\"%s\")!\n", player->comment);
		current_player = current_player->next;
	}
}

void	print_arena(unsigned char *arena)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("0x%.4x : ", i);
		ft_printf("%.2x", arena[i++]);
		if (i % 64 != 0)
			ft_putchar(' ');
		if (i % 64 == 0)
			ft_putchar('\n');
	}
}
