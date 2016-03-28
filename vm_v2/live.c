/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:54:45 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/28 21:37:42 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		live(t_env *data, t_process *process)
{
	unsigned char	*arena;
	unsigned int	live;
	int				index;

	if (data->debug)
		ft_printf("Begin of LIVE\n");
	arena = data->arena;
	index = process->position;
	live = arena[++index % MEM_SIZE];
	live = live << 8;
	live += arena[++index % MEM_SIZE];
	live = live << 8;
	live += arena[++index % MEM_SIZE];
	live = live << 8;
	live += arena[++index % MEM_SIZE];
	process->position = (process->position + 4) % MEM_SIZE;
	if (data->debug)
	{
		ft_printf("Live for %#x\n ", live);
		ft_printf("End of LIVE\n");
	}
	return (live);
}
