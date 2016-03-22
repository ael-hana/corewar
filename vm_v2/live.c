/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:54:45 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/22 15:02:53 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		live(unsigned char *arena, t_process *process)
{
	unsigned int	len;

	process->position = ++process->position % MEM_SIZE;
	len = arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	return (len);
}
