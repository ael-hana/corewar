/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:28:28 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/31 15:51:29 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

int		*get_op_args(unsigned char *arena, t_process *process)
{
	int				i;
	int				j;
	int				params_nb;
	unsigned char	bytecode;
	int				*tab;

	bytecode = arena[(process->position + 1) % MEM_SIZE];
	if (get_arg_nb(bytecode) != g_op_tab[process->op - 1].params_nb)
		return (NULL);
	tab = malloc(sizeof(int) * 3);
	ft_bzero(tab, sizeof(int) * 3);
	params_nb = g_op_tab[process->op - 1].params_nb;
	i = 0;
	j = 2;
	while (i < params_nb)
	{
		if (!(g_op_tab[process->op - 1].params_type[i] &
					bytecode_nb(bytecode >> 6)))
			return (NULL);
		tab[i] = get_arg_value(arena, process, &j, bytecode >> 6);
		bytecode = bytecode << 2;
		i++;
	}
	return (tab);
}

int		get_dir_value(unsigned char *are, t_process *process, int *tab)
{
	int				i;
	unsigned char	bytecode;
	int				params_nb;

	i = 0;
	bytecode = are[(process->position + 1) % MEM_SIZE];
	params_nb = g_op_tab[process->op - 1].params_nb;
	while (i < params_nb)
	{
		if (bytecode >> 6 == 0b01)
		{
			if (tab[i] >= 1 && tab[i] <= 16)
				tab[i] = process->reg[tab[i] - 1];
			else
				return (0);
		}
		bytecode = bytecode << 2;
		i++;
	}
	return (1);
}

int		read_arena(unsigned char *arena, int index)
{
	int		value;

	value = arena[index++ % MEM_SIZE];
	value = value << 8;
	value += arena[index++ % MEM_SIZE];
	value = value << 8;
	value += arena[index++ % MEM_SIZE];
	value = value << 8;
	value += arena[index % MEM_SIZE];
	return (value);
}

int		get_ind_value(unsigned char *are, t_process *process, int *tab, int id)
{
	int				i;
	unsigned char	bytecode;
	int				params_nb;
	int				index;

	i = 0;
	bytecode = are[(process->position + 1) % MEM_SIZE];
	params_nb = g_op_tab[process->op - 1].params_nb;
	while (i < params_nb)
	{
		if (bytecode >> 6 == 0b11)
		{
			if (id == 1)
				index = tab[i] % IDX_MOD;
			else
				index = tab[i];
			tab[i] = read_arena(are, index);
		}
		bytecode = bytecode << 2;
		i++;
	}
	return (1);
}

void	update_pc_pos(unsigned char *are, t_process *process)
{
	int				i;
	unsigned char	bytecode;
	int				params_nb;

	i = 0;
	bytecode = are[(process->position + 1) % MEM_SIZE];
	params_nb = g_op_tab[process->op - 1].params_nb;
	process->position = (process->position + 1) % MEM_SIZE;
	while (i < params_nb)
	{
		if (bytecode >> 6 == 0b01)
			process->position = (process->position + 1) % MEM_SIZE;
		else if (bytecode >> 6 == 0b11 || g_op_tab[process->op - 1].index == 1)
			process->position = (process->position + 2) % MEM_SIZE;
		else if (bytecode >> 6 == 0b10)
			process->position = (process->position + 4) % MEM_SIZE;
		bytecode = bytecode << 2;
		i++;
	}
}
