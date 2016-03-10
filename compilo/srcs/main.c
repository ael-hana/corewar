/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:48:49 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/10 20:13:06 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilo.h"

static int	no_args(void)
{
	ft_putendl("Usage : ./asm [-a] <sourcefile.s ...>");
	ft_putstr("\t -a : Instead of creating a .cor file, outputs a stripped ");
	ft_putendl("and annoted version of the code to the standard output");
	return (0);
}

static int	check_flag(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (!ft_strcmp(av[i], "-a"))
			return (1);
	return (0);
}

static void	print_end_comment(char *file_name, int ret, int opt)
{
	if (opt || ret == -1)
		return ;
	if (ret)
		ft_putstr("Writing output program to ");
	else
		ft_putstr("And error occured during the writing of ");
	while (*file_name && *file_name + 1)
		ft_putchar(*file_name);
	ft_putendl("cor");
}

int			main(int ac, char **av)
{
	int	i;
	int	opt;
	int	len;

	if (ac == 1)
		return (no_args());
	opt = check_flag(ac, av);
	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-a"))
			continue ;
		len = ft_strlen(av[i]);
		if (av[i][len - 2] != '.' || av[i][len - 1] != 's')
			ft_printf("%s is not a .s file\n", av[i]);
		else
			print_end_comment(av[i], my_compute(av[i], opt), opt);
	}
	return (0);
}
