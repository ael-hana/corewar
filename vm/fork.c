/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:51:24 by ael-hana          #+#    #+#             */
/*   Updated: 2016/04/01 14:13:46 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

unsigned int		forkk(t_env *data, t_process *process)
{
	t_process		*new_process;
	short			index;
	unsigned char	*arena;

	arena = data->arena;
	index = arena[(process->position + 1) % MEM_SIZE];
	index = index << 8;
	index += arena[(process->position + 2) % MEM_SIZE];
	index = ((index % IDX_MOD) + process->position);
	new_process = create_process(process, process->player, index);
	ft_lstadd(&data->process_list, ft_lstnew(new_process, sizeof(t_process)));
	free(new_process);
	process->position = (process->position + 2) % MEM_SIZE;
	return (1);
}
