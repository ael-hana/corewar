/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_arg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:47:40 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/31 19:31:18 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

int				update_pc_pos_on_failure(unsigned char *arena, t_process *pc,
				int **tab)
{
	int		bytecode;
	int		params_nb;
	int		i;

	params_nb = g_op_tab[pc->op - 1].params_nb;
	bytecode = arena[(pc->position + 1) % MEM_SIZE];
	pc->position = (pc->position + 1) % MEM_SIZE;
	i = 0;
	while (i < params_nb)
	{
		if (bytecode >> 6 == 0b01)
			pc->position = (pc->position + 1) % MEM_SIZE;
		else if (bytecode >> 6 == 0b11 || g_op_tab[pc->op - 1].index == 1)
			pc->position = (pc->position + 2) % MEM_SIZE;
		else if (bytecode >> 6 == 0b10)
			pc->position = (pc->position + 4) % MEM_SIZE;
		bytecode = bytecode << 2;
		i++;
	}
	ft_memdel((void **)tab);
	return (0);
}

int				get_arg_value(unsigned char *arena, t_process *process, int *j,
		char bytecode)
{
	int		value;

	value = 0;
	if (bytecode == 0b01)
	{
		value = arena[(process->position + (*j)++) % MEM_SIZE];
	}
	else if (bytecode == 0b11 || g_op_tab[process->op - 1].index == 1)
	{
		value = arena[(process->position + (*j)++) % MEM_SIZE];
		value = value << 8;
		value += arena[(process->position + (*j)++) % MEM_SIZE];
	}
	else if (0b10 == bytecode)
	{
		value = arena[(process->position + (*j)++) % MEM_SIZE];
		value = value << 8;
		value += arena[(process->position + (*j)++) % MEM_SIZE];
		value = value << 8;
		value += arena[(process->position + (*j)++) % MEM_SIZE];
		value = value << 8;
		value += arena[(process->position + (*j)++) % MEM_SIZE];
	}
	return (value);
}

int				bytecode_nb(int bytecode)
{
	if (bytecode == 0b01)
		return (1);
	else if (bytecode == 0b10)
		return (2);
	else if (bytecode == 0b11)
		return (4);
	return (0);
}

int				get_arg_nb(char bytecode)
{
	int		i;

	i = 0;
	while (bytecode != 0)
	{
		bytecode = bytecode << 2;
		i++;
	}
	return (i);
}
