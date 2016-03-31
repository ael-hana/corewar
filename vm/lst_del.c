/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 18:55:40 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/31 19:50:03 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void free_player(void *player, size_t size)
{
	(void)size;
	free(((t_header*)(player))->inst);
	free(player);
}

void	free_process(void *process, size_t size)
{
	(void)size;
	free_player(((t_process*)(process))->player, sizeof(t_header*));
	free(process);
}
