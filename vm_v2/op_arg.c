/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:28:28 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/24 04:06:22 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int				update_pc_pos_on_failure(unsigned char *arena, t_process *pc)
{
	int		bytecode;
	int		params_nb;
	int		i;

	params_nb = op_tab[pc->op - 1].params_nb;
	bytecode = arena[(pc->position + 1) % MEM_SIZE];
	pc->position = (pc->position + 1) % MEM_SIZE;
	i = 0;
	while (i < params_nb)
	{
		if (bytecode >> 6 == 0b01)
			pc->position = (pc->position + 1) % MEM_SIZE;
		else if (bytecode >> 6 == 0b11 || op_tab[pc->op - 1].index == 1)
			pc->position = (pc->position + 2) % MEM_SIZE;
		else if (bytecode >> 6 == 0b10)
			pc->position = (pc->position + 4) % MEM_SIZE;
		bytecode = bytecode << 2;
		i++;
	}
	return (0);
}

int				get_arg_value(unsigned char *arena, t_process *process, int *j, char bytecode)
{
	int		value;

	value = 0;
	if (bytecode == 0b01)
	{
		value = arena[(process->position + (*j)++) % MEM_SIZE];
	}
	else if (bytecode == 0b11 || op_tab[process->op - 1].index == 1)
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

int				*get_op_args(unsigned char *arena, t_process *process)
{
	int				i;
	int				j;
	int				params_nb;
	unsigned char	bytecode;
	int				*tab;

	bytecode = arena[(process->position + 1) % MEM_SIZE];
	if (get_arg_nb(bytecode) != op_tab[process->op - 1].params_nb)
	{
		ft_printf("nb param erreur\n");
		return (NULL);
	}
	tab = malloc(sizeof(int) * 3);
	params_nb = op_tab[process->op -1].params_nb;
	i = 0;
	j = 2;
	while (i < params_nb)
	{
		if (!(op_tab[process->op - 1].params_type[i] & bytecode_nb(bytecode >> 6)))
		{
			ft_printf("wrong type param error\n");
			return (NULL);
		}
		tab[i] = get_arg_value(arena, process, &j, bytecode >> 6);
		bytecode = bytecode << 2;
		i++;
	}
	return (tab);
}

int			get_dir_value(unsigned char *are, t_process *process, int *tab)
{
	int		i;
	unsigned char	bytecode;
	int		params_nb;


	i = 0;
	bytecode = are[(process->position + 1) % MEM_SIZE];
	params_nb = op_tab[process->op - 1].params_nb;
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
	params_nb = op_tab[process->op - 1].params_nb;
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

void		update_pc_pos(unsigned char *are, t_process *process)
{
	int		i;
	unsigned char	bytecode;
	int		params_nb;

	i = 0;
	bytecode = are[(process->position + 1) % MEM_SIZE];
	params_nb = op_tab[process->op - 1].params_nb;
	process->position = (process->position + 1) % MEM_SIZE;
	while (i < params_nb)
	{
		if (bytecode >> 6 == 0b01)
			process->position = (process->position + 1) % MEM_SIZE;
		else if (bytecode >> 6 == 0b11 || op_tab[process->op - 1].index == 1)
			process->position = (process->position + 2) % MEM_SIZE;
		else if (bytecode >> 6 == 0b10)
			process->position = (process->position + 4) % MEM_SIZE;
		bytecode = bytecode << 2;
		i++;
	}
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
