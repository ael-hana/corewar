/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:54:45 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/22 20:40:32 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		live(t_env *data, t_process *process)
{
	unsigned char	*arena;
	unsigned int	len;

	arena = data->arena;
	process->position = ++process->position % MEM_SIZE;
	len = arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	return (len);
}
