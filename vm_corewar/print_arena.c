/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:16:08 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/17 19:43:25 by ecousine         ###   ########.fr       */
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

void	print_info(t_env *data)
{
	t_list		*player_list;
	t_header	*player;

	ft_printf("========= GAME INFOS =========\n");
	ft_printf("Cycle : %d\n", data->cycle);
	ft_printf("CYCLE_TO_DIE : %d\n", data->cycle_to_die);
	ft_printf("CYCLE_DELTA : %d\n\n", CYCLE_DELTA);
	ft_printf("======= PLAYERS INFOS ========\n");
	player_list = data->player_list;
	while (player_list)
	{
		player = player_list->content;
		ft_printf("Player %d : %s is ", player->n, player->prog_name);
		(player->alive) ? ft_putendl("still alive.") : ft_putendl("is dead");
		ft_printf("Last alive : %d", player->last_alive, player->alive);
		player_list = player_list->next;
	}
}
