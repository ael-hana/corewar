/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:02:52 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/28 00:48:03 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		sub(t_env *data, t_process *process)
{
	unsigned char		*arena;
	int					*tab;
	int					reg_dest;

	if (data->debug)
		ft_printf("Start of sub\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (0);
	reg_dest = tab[2];
	if (data->debug)
		ft_printf("Arg 1 : %d, Arg 2 : %d, Arg 3 : %d\n", tab[0], tab[1], tab[2]);
	if (get_dir_value(arena, process, tab) == 0)
		return (0);
	if (data->debug)
		ft_printf("Arg 1 : %d, Arg 2 : %d, Arg 3 : %d\n", tab[0], tab[1], tab[2]);
	if (reg_dest >= 1 && reg_dest <= 16)
	{
		process->reg[reg_dest - 1] = tab[0] - tab[1];
		if (tab[0] - tab[1] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	update_pc_pos(data->arena, process);
	if (data->debug)
		ft_printf("End of SUB\n");
	return (1);
}
/*
   unsigned int		sub(unsigned char *arena, t_process *process)
   {
   const int		i = ++process->position % MEM_SIZE;
   unsigned int	tab[2];
   char			st;

   if (arena[i] != 0b01010100)
   return (process->carry = 0);
   if ((st = recup_val(1, arena, &process->position)) < 17)
   tab[0] = st;
   else
   return (process->carry = 0);
   if ((st = recup_val(1, arena, &process->position)) < 17)
   tab[1] = st;
   else
   return (process->carry = 0);
   if ((st = recup_val(1, arena, &process->position)) < 17)
   process->reg[st] = process->reg[tab[0]] - process->reg[tab[1]];
   else
   return (process->carry = 0);
   process->position = ++process->position % MEM_SIZE;
   return (process->carry = process->reg[st] == 0 ? 1 : 0);
   }*/
