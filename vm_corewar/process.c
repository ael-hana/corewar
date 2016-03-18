/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 17:28:24 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/18 03:39:57 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_process	*create_process(t_process *father_process, int n, int position)
{
	t_process	*new_process;

	if (!(new_process = malloc(sizeof(t_process))))
		error_msg("CAN'T MALLOC\n");
	if (father_process == NULL)
	{
		new_process->cycle = -1;
		new_process->op = 0;
		new_process->carry = 0;
		ft_bzero(new_process->reg, sizeof(int) * 16);
		new_process->reg[0] = n;
		new_process->alive = 1;
		new_process->last_alive = 0;
	}
	else
	{
		new_process = father_process;
		new_process->position = (n + position) % IDX_MOD;
	}
	return (new_process);
}

void		get_inst(t_process *process, unsigned char *arena)
{
	int		i;
	i = -1;
	while (op_tab[++i].opcode)
	{
		if (op_tab[i].opcode == arena[process->position])
		{
			process->cycle = op_tab[i].cycles_nb;
			process->op = op_tab[i].opcode;
			return ;
		}
	}
	process->position++;
}
