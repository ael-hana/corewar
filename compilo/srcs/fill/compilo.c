/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compilo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:09:23 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/11 18:10:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "compilo.h"

static int	check_good_labels(t_env *e)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	(void)tmp3;
	tmp1 = e->instrs;
	while (tmp1)
	{
		tmp2 = ((t_instr *)tmp1->content)->args;
		while (tmp2)
		{
			if (((t_arg *)tmp2->content)->arg_type & T_LAB)
			{
				if (!(tmp3 = ft_lstfind(e->labels,
					((t_arg *)tmp2->content)->arg_value, sizeof(t_label),
					&my_lstcmp)))
					return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

int			use_env_to_compile(t_env *e, char *file_name, int opt)
{
	int	fd;

	if (!file_name || !check_good_labels(e))
	{
		ft_memdel((void **)&file_name);
		return (0);
	}
	if (!opt)
	{
		if ((fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR + S_IWUSR
			+ S_IRGRP + S_IWGRP + S_IROTH)) == -1)
		{
			ft_memdel((void **)&file_name);
			return (0);
		}
		write_file(e, fd);
		if ((fd = close(fd)) == -1)
			ft_printf("Can't close source file %s\nBe carreful !!!\n", file_name);
	}
	else
		write_compilo_steps(e);
	ft_memdel((void **)&file_name);
	return (1);
}
