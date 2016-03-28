/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:51:24 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/28 00:49:43 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		forkk(t_env *data, t_process *process)
{
	t_process		*new_process;
	short			index;
	unsigned char	*arena;

	if (data->debug)
		ft_printf("Start of FORK\n");
	arena = data->arena;
	index = arena[(process->position + 1) % MEM_SIZE];
	index = index << 8;
	index += arena[(process->position + 2) % MEM_SIZE];
	index = ((index % IDX_MOD)+ process->position);
	new_process = create_process(process, process->player, index);
	ft_lstadd(&data->process_list, ft_lstnew(new_process, sizeof(t_process)));
	process->position = (process->position + 2) % MEM_SIZE;
	if (data->debug)
		ft_printf("Position of new process : %d\n", index);
	if (data->debug)
		ft_printf("End of fork\n");
	return (1);
}
