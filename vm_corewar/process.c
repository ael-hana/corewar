/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 17:28:24 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/13 17:47:11 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_process		*create_process(t_process *father_process, int n, int position)
{
	t_process	*new_process;

	new_process = malloc(sizeof(t_process));
	if (father_process == NULL)
	{
		new_process->carry = 0;
		ft_bzero(new_process->reg, sizeof(int) * 16);
		new_process->reg[0] = n;
		new_process->alive = 1;
		new_process->last_alive = 0;
	}
	return (new_process);
}
