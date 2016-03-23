/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:44:54 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 18:37:45 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		zjmp(t_env *data, t_process *process)
{
	int				index;
	unsigned char	*arena;

	arena = data->arena;
	if (process->carry == 0)
		return (0);
	index = arena[(process->position + 1) % MEM_SIZE];
	index = index << 8;
	index += arena[(process->position + 2) % MEM_SIZE];
	process->position += ((index % IDX_MOD) - 1) % MEM_SIZE;
	return (1);
}
