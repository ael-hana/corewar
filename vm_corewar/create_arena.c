/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:10:11 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/12 19:03:58 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	create_arena(t_env *data)
{
	data->arena = malloc(sizeof(unsigned char) * MEM_SIZE);
}
