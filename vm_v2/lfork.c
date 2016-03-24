/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:34:12 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 19:28:21 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		lforkk(t_env *data, t_process *process)
{
	t_process		*new_process;
	int				index;
	unsigned char	*arena;

	arena = data->arena;
	if (process->carry == 0)
		return (0);
	index = arena[(process->position + 1) % MEM_SIZE];
	index = index << 8;
	index += arena[(process->position + 2) % MEM_SIZE];
	index = index << 8;
	index += arena[(process->position + 2) % MEM_SIZE];
	index = index << 8;
	index += arena[(process->position + 2) % MEM_SIZE];
	index = (process->position + index) % MEM_SIZE;
	new_process = create_process(process, process->player, index);
	ft_lstadd(&data->process_list, ft_lstnew(new_process, sizeof(t_process)));
	process->position = (process->position + 4) % MEM_SIZE;
	return (1);
}
