/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:54:45 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/28 00:46:45 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		live(t_env *data, t_process *process)
{
	unsigned char	*arena;
	unsigned int	len;

	if (data->debug)
		ft_printf("Begin of LIVE\n");
	arena = data->arena;
	len = arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	if (data->debug)
	{
		ft_printf("Live for %#x\n ", len);
		ft_printf("End of LIVE\n");
	}
	return (len);
}
