/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:58:56 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/12 17:31:59 by ecousine         ###   ########.fr       */
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

int		parse_players(int ac, char **av, t_env *data)
{
	int			n;
	t_header	*player;

	while (data->i < ac)
	{
		n = 0;
		if (ft_strcmp(av[data->i], "-n") == 0)
		{
			n = get_player_number(ac, av, data);
			data->i++;
		}
		player = create_player(av[data->i]);
		ft_lstadd(&data->player_list, ft_lstnew(player, sizeof(t_header *)));
		data->nb_players++;
		data->i++;
	}
	return (1);
}
