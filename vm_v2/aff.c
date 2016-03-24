/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:48:17 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 18:42:04 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		aff(t_env *data, t_process *process)
{
	unsigned char	*arena;
	unsigned char	v;

	arena = data->arena;
	ft_printf("fjeirwofjiowejigojwioegjiowjiogjwiojgw\n\n");
	if (arena[++process->position % MEM_SIZE] != 0b01000000)
		return (0);
	ft_printf("fjeirwofjiowejigojwioegjiowjiogjwiojgw\n\n");
	if ((v = recup_val(1, arena, &process->position)) > 16)
		return (0);
	ft_printf("fjeirwofjiowejigojwioegjiowjiogjwiojgw\n\n");
	process->position = ++process->position % MEM_SIZE;
	v = process->reg[v] % 256;
	write(1, &v, 1);
	return (0);
}
