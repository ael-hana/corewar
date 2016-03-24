/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:16:08 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/24 07:15:51 by ecousine         ###   ########.fr       */
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

void	print_arena(t_env *data)
{
	int		i;
	char	color_tab[5][10];

	ft_strcpy(color_tab[0], ANSI_COLOR_RESET);
	ft_strcpy(color_tab[1], ANSI_COLOR_RED);
	ft_strcpy(color_tab[2], ANSI_COLOR_GREEN);
	ft_strcpy(color_tab[3], ANSI_COLOR_BLUE);
	ft_strcpy(color_tab[4], ANSI_COLOR_YELLOW);
	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf(ANSI_COLOR_RESET);
		if (i % 64 == 0)
			ft_printf("0x%.4x : ", i);
		ft_printf(color_tab[data->arena_owner[i]]);
		ft_printf("%.2x", data->arena[i++]);
		if (i % 64 != 0)
			ft_putchar(' ');
		if (i % 64 == 0)
			ft_putchar('\n');
	}
	ft_printf(ANSI_COLOR_RESET);
}

void	print_info(t_env *data)
{
	t_list		*player_list;
	t_header	*player;

	ft_printf("========= GAME INFOS =========\n");
	ft_printf("Cycle : %d       ", data->cycle);
	ft_printf("CYCLE_TO_DIE : %d      ", data->cycle_to_die);
	ft_printf("CYCLE_DELTA : %d\n\n", CYCLE_DELTA);
	ft_printf("======= PLAYERS INFOS ========\n");
	player_list = data->player_list;
	while (player_list)
	{
		player = player_list->content;
		ft_printf("Player %d : %s    ", player->n, player->prog_name);
		ft_printf("Last alive : %d\n", player->last_alive, player->alive);
		player_list = player_list->next;
	}
}
