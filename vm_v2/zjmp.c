/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:44:54 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 22:04:44 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		zjmp(t_env *data, t_process *process)
{
	short			index;
	unsigned char	*arena;

	ft_printf("begin of ZJMP\n");
	arena = data->arena;
	if (process->carry == 0)
		return (0);
	index = arena[(process->position + 1) % MEM_SIZE];
	index = index << 8;
	index += arena[(process->position + 2) % MEM_SIZE];
	process->position += (index % IDX_MOD) - 1;
	ft_printf("new process position : %d\n", process->position);
	ft_printf("End of ZJMPP\n");
	return (1);
}
