/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_get_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:25:48 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/17 18:38:41 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

short				recup_indir(unsigned char *arena, int *i)
{
	short			num;

	num = arena[++*i % MEM_SIZE];
	num <<=8;
	num = arena[++*i % MEM_SIZE];
	*i %= MEM_SIZE;
	return (num);
}

unsigned int		recup_dir(unsigned char *arena, int *i)
{
	unsigned int	num;

	num = arena[++*i % MEM_SIZE];
	num <<=8;
	num = arena[++*i % MEM_SIZE];
	num <<=8;
	num = arena[++*i % MEM_SIZE];
	num <<=8;
	num = arena[++*i % MEM_SIZE];
	*i %= MEM_SIZE;
	return (num);
}

unsigned int		recup_reg_n(unsigned char *arena, int *i)
{
	*i = (*i + 1) % MEM_SIZE;
	return (arena[*i]);
}

unsigned int		recup_val(int code, unsigned char *arena, int *i)
{
	unsigned int	reg_n;

	if (code > 3 || code == 0)
		return (code == 1 ? 17 : 0);
	if (3 == code)
		return (recup_indir(arena, i));
	if (2 == code)
		return (recup_dir(arena, i));
	reg_n = recup_reg_n(arena, i);
	return (reg_n == 0 ? 42 : reg_n );
}
