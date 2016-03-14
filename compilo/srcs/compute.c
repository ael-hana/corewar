/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:40:25 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/11 20:07:41 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "compilo.h"

static int	free_and_quit(t_env *e, int ret)
{
	ft_lstdel(&e->labels, &my_label_del);
	ft_lstdel(&e->instrs, &my_instr_del);
	free(e);
	return (ret);
}

int			my_compute(char *file_name, int opt)
{
	t_env	*e;
	int		fd;
	int		ret;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		return (0);
	if ((fd = open(file_name, O_RDWR)) == -1)
	{
		ft_printf("Can't read source file %s\n", file_name);
		return (free_and_quit(e, -1));
	}
	if ((ret = analyse_file_and_fill_env(e, fd)))
		use_env_to_compile(e, opt);
	if ((fd = close(fd)) == -1)
		ft_printf("Can't close source file %s\tBe carreful !!!\n", file_name);
	return (free_and_quit(e, ret));
}
