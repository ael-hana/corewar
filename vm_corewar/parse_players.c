/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:58:56 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/13 17:56:03 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

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

void	init_player(t_header *player, int n)
{
	t_process		*process;

	player->alive = 1;
	player->last_alive = 0;
	player->n = n;
	process = create_process(NULL, player->n, -1);
	ft_lstadd(&player->process_list, ft_lstnew(process, sizeof(t_process)));
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
			data->i++;
		}
		player = create_player(av[data->i]);
		init_player(player, n);
		ft_lstadd(&data->player_list, ft_lstnew(player, sizeof(t_header)));
		data->nb_players++;
		data->i++;
		if (data->nb_players > 4)
			print_error(ERR_PARAM);
	}
	if (data->nb_players == 0)
		print_error(ERR_PARAM);
	return (1);
}
