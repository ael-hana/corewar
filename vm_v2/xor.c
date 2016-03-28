/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:17:50 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/28 00:56:25 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		xorr(t_env *data, t_process *process)
{
	unsigned char		*arena;
	int					*tab;
	int					reg_dest;

	if (data->debug)
		ft_printf("Start of XOR\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (update_pc_pos_on_failure(arena, process));
	reg_dest = tab[2];
	if (data->debug)
		ft_printf("Arg 1 : %d, Arg 2 : %d, Arg 3 : %d\n", tab[0], tab[1], tab[2]);
	if (get_dir_value(arena, process, tab) == 0)
		return (update_pc_pos_on_failure(arena, process));
	if (data->debug)
		ft_printf("Arg 1 : %d, Arg 2 : %d, Arg 3 : %d\n", tab[0], tab[1], tab[2]);

	if (get_ind_value(data->arena, process, tab, 1) == 0)
		return (update_pc_pos_on_failure(arena, process));

	if (reg_dest >= 1 && reg_dest <= 16)
	{
		process->reg[reg_dest - 1] = tab[0] ^ tab[1];
		if ((tab[0] ^ tab[1]) == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		return (update_pc_pos_on_failure(arena, process));
	update_pc_pos(data->arena, process);
	if (data->debug)
		ft_printf("End of XOR\n");
	return (1);
}
/*
   unsigned int		xor_bitwise(t_process *process, unsigned int *tab)
   {
   process->position = ++process->position % MEM_SIZE;
   process->reg[tab[2]] = tab[1] ^ tab[0];
   return (process->carry = process->reg[tab[2]] == 0 ? 1 : 0);
   }

   unsigned int		xorr(unsigned char *arena, t_process *process)
   {
   const int		i = ++process->position % MEM_SIZE;
   int				it;
   unsigned int	tab[3];
   int				cmp;

   cmp = 6;
   it = -1;
   if (arena[i] & 0b00000011)
   return (process->carry = 0);
   while (++it < 3 && arena[i] >> cmp)
   {
   if (it != 2 && ((arena[i] >> cmp) & 0b00000011) == 0b11)
   tab[it] = recup_val(3, arena, &process->position);
   else if (it != 2 && ((arena[i] >> cmp) & 0b00000011) == 0b10)
   tab[it] = recup_val(2, arena, &process->position);
   else if (((arena[i] >> cmp) & 0b00000011) == 0b01 &&
   (tab[it] = recup_val(1, arena, &process->position) < 17))
   tab[it] = process->reg[tab[it]];
   else
   return (process->carry = 0);
   cmp -= 2;
   }
   return (xor_bitwise(process, tab));
   }*/
