/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:33:20 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/31 14:59:15 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

void	place_player(t_env *data, int start, t_header *player)
{
	unsigned int		i;

	i = 0;
	while (i < player->prog_size)
	{
		data->arena[start + i] = player->inst[i];
		data->arena_owner[start + i] = player->numb;
		i++;
	}
}

void	place_players(t_env *data)
{
	int			i;
	t_list		*player_list;
	t_header	*player;
	t_process	*process;

	i = 0;
	player_list = data->player_list;
	while (player_list)
	{
		player = player_list->content;
		place_player(data, i, player);
		process = create_process(NULL, player, -1);
		process->position = i;
		ft_lstadd(&data->process_list, ft_lstnew(process, sizeof(t_process)));
		i += MEM_SIZE / data->nb_players;
		player_list = player_list->next;
	}
}
