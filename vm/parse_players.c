/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:58:56 by ecousine          #+#    #+#             */
/*   Updated: 2016/04/01 14:33:31 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

int		get_player_number(int ac, char **av, t_env *data)
{
	int		n;

	if (data->i + 1 < ac && str_is_digit(av[data->i + 1]) &&
			(n = ft_atoi(av[data->i + 1])) > 0)
		return (n);
	else
		print_error(ERR_PARAM);
	return (-1);
}

void	init_player(t_env *data, t_header *player, int n)
{
	t_list		*player_list;
	t_header	*cplayer;

	player->numb = data->nb_players + 1;
	player->alive = 1;
	player->last_alive = 0;
	player_list = data->player_list;
	while (player_list)
	{
		cplayer = player_list->content;
		if (cplayer->n == n)
			print_error(ERR_PARAM);
		player_list = player_list->next;
	}
	player->n = n;
}

int		parse_players(int ac, char **av, t_env *data)
{
	int			n;
	t_header	*player;

	n = 0;
	while (data->i < ac)
	{
		n++;
		if (ft_strcmp(av[data->i], "-n") == 0)
		{
			n = get_player_number(ac, av, data);
			data->i += 2;
		}
		player = create_player(av[data->i]);
		init_player(data, player, n);
		ft_lstpush(&data->player_list, ft_lstnew(player, sizeof(t_header)));
		free(player);
		data->nb_players++;
		if (data->nb_players > 4)
			print_error(ERR_PARAM);
		data->i++;
	}
	if (data->nb_players == 0)
		print_error(ERR_PARAM);
	return (1);
}
