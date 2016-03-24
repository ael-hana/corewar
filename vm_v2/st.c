/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:32:34 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/24 01:44:32 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		st(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;
	short			index;

	ft_printf("Begin of ST\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (0);
	ft_printf("Board : Arg 1 : %#x, Arg 2 : %#x\n", tab[0], tab[1]);
	index = tab[1];
	if (get_dir_value(arena, process, tab) == 0)
		return (0);
	ft_printf("Reg   : %#x, Arg 2 : %#x\n", tab[0], tab[1]);
	if (get_ind_value(arena, process, tab, 1) == 0)
		return (0);
	ft_printf("Ind   : %#x, Arg 2 : %#x\n", tab[0], tab[1]);
	ft_printf("Start writing at : %d\n", index % IDX_MOD);
	write_arena(data, process, index % IDX_MOD, tab[0]);
	update_pc_pos(data->arena, process);
	ft_printf("End of ST\n");
	return (1);
}
