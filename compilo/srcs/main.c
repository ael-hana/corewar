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

extern t_op	g_op_tab[17];

static void	print_instrus(void)
{
	int	i;

	i = -1;
	while (g_op_tab[++i].instr_name)
	{
		ft_printf("\t\t\"%s\" - %d arg(s)\n",
		g_op_tab[i].instr_name, g_op_tab[i].params_nb);
	}
}

static int	my_help(void)
{
	ft_putendl("Usage : ./asm [-at] <sourcefile.s ...>\n");
	ft_putendl("\t-a\n\t\tInstead of creating a .cor file, outputs a stripped");
	ft_putendl("\t\tand annoted version of the code to the standard output\n");
	ft_putendl("\t-t\n\t\tPrint this help and quit\n");
	ft_putendl("Be carreful, the expected syntax is restrictive\n");
	ft_printf("\tA comment begins by a character in \"%s\"\n\n", COMMENT_CHARS);
	ft_putendl("\tA name and a comment have to be given before the labels and");
	ft_putendl("\tthe instructions :");
	ft_printf("\t\tName : \"%s\" followed by \"The name\"\
	(max %d characters)\n", NAME_CMD_STRING, PROG_NAME_LENGTH);
	ft_printf("\t\tComment : \"%s\" followed by \"The comment\"\
	(max %d characters)\n\n", COMMENT_CMD_STRING, COMMENT_LENGTH);
	ft_putendl("\tMany labels can't be on the same line & have the same name");
	ft_printf("\tIts name has to be created with the characters : \"%s\"\n",
	LABEL_CHARS);
	ft_printf("\tand it has to be directly followed by the character : '%c'",
	LABEL_CHAR);
	ft_putendl("\n\n\tInstructions :");
	print_instrus();
	ft_putendl("\tMany instructions can't be on the same line, label names");
	ft_printf("\thave to exist and each argument are separated by a '%c'\n",
	SEPARATOR_CHAR);
	return (0);
}

static int	check_flag(int ac, char **av)
{
	int	i;
	int	opt;

	i = 0;
	opt = 0;
	while (++i < ac)
	{
		if (*av[i] != '-' || av[i][1] == '-')
			continue ;
		if (is_in_buf('h', av[i] + 1))
			return (2);
		if (is_in_buf('a', av[i] + 1))
			opt = 1;
	}
	return (opt);
}

static void	print_end_comment(char *file_name, int ret, int opt)
{
	if (opt || ret == -1)
		return ;
	if (ret)
		ft_putstr("Writing output program to ");
	else
		ft_putstr("An error occured during the writing of ");
	while (*file_name && *(file_name + 1))
		ft_putchar(*(file_name++));
	ft_putendl("cor");
}

int			main(int ac, char **av)
{
	int	i;
	int	j;
	int	opt;
	int	len;

	if (!(j = 0) && ac == 1)
		return (my_help());
	if ((opt = check_flag(ac, av)) == 2)
		return (my_help());
	i = ac;
	while (--i > 0)
	{
		if (*av[i] == '-' && av[i][1] != '-'
			&& is_in_buf('a', av[i] + 1))
			continue ;
		j++;
		len = ft_strlen(av[i]);
		if (av[i][len - 2] != '.' || av[i][len - 1] != 's')
			ft_printf("%s is not a .s file\n", av[i]);
		else
			print_end_comment(av[i], my_compute(av[i], opt), opt);
	}
	if (!j)
		return (my_help());
	return (0);
}
