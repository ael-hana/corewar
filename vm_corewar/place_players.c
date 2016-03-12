/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:33:20 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/12 21:32:20 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	place_player(unsigned char *arena, int start, t_header *player)
{
	int		i;

	i = 0;
	while (i < player->prog_size)
	{
		arena[start + i] = player->inst[i];
		i++;
	}
}

void	place_players(t_env *data)
{
	int			i;
	t_list		*player;

	i = 0;
	player = data->player_list;
	while (player)
	{
		place_player(data->arena, i, (t_header *)player->content);
		i = MEM_SIZE / data->nb_players;
		player = player->next;
	}
}
