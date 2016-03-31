/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:48:17 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/31 18:43:57 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

unsigned int		aff(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;
	unsigned char	v;

	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (update_pc_pos_on_failure(arena, process, &tab));
	v = process->reg[tab[0]] % 256;
	write(1, &v, 1);
	update_pc_pos(arena, process);
	ft_memdel((void **)&tab);
	return (0);
}
