/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 18:55:40 by ecousine          #+#    #+#             */
/*   Updated: 2016/04/01 14:30:31 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void free_player(void *player, size_t size)
{
	(void)size;
	ft_memdel((void**)&(((t_header*)(player))->inst));
	free(player);
}

void	free_process(void *process, size_t size)
{
	(void)size;
	free(process);
}
