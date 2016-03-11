/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parssing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:14:19 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/11 19:55:10 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void				error_msg(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

unsigned int		check_magic(unsigned char *str)
{
	ft_strlen((char *)str) < 4 ? error_msg("ERROR : MAGIC NUM\n") : 0;
	if (str[0] == 0 && str[1] == 0xEA && str[2] == 0x83 && str[3] == 0xF3)
		return (0xea83f3);
	error_msg("ERROR : MAGIC NUM\n");
	return (0);
}

unsigned int		prog_size(unsigned char *str)
{
	unsigned int	len;

	ft_strlen((char *)str) < 136 ? error_msg("ERROR : PROG SIZE\n") : 0;
	len = str[132];
	len = len << 4;
	len = str[133];
	len = len << 4;
	len = str[134];
	len = len << 4;
	len = str[135];
	!len ? error_msg("ERROR : PROG SIZE\n") : 0;
	return (len);
}

void				check_comment(unsigned char *str, char *tab)
{
	int				i;

	i = 136;
	ft_strlen((char *)str) < 2184 ? error_msg("ERROR : COMMENT\n") : 0;
	while (str[i])
	{
		tab[i - 136] = str[i];
		++i;
	}
	tab[i - 136] = '\0';
}

void				check_name(unsigned char *str, char *tab)
{
	int				i;

	i = 4;
	ft_strlen((char *)str) < 132 ? error_msg("ERROR : NAME\n") : 0;
	while (str[i])
	{
		tab[i - 4] = str[i];
		++i;
	}
	tab[i - 4] = '\0';
}

t_header			*check_buf(unsigned char *str)
{
	t_header		*ptr;

	if (!(ptr = malloc(sizeof(t_header))))
		error_msg("ERROR : CAN'T MALLOC.\n");
	ptr->magic = check_magic(str);
	check_name(str, ptr->prog_name);
	ptr->prog_size = prog_size(str);
	check_comment(str, ptr->comment);
	if (ft_strlen((char *)(str + 2184)) != ptr->prog_size)
		error_msg("ERROR : PROG SIZE\n");
	ptr->inst = str + 2184;
	return (ptr);
}

t_header			*ft_parssing(char *path)
{
	int				fd;
	int				len;
	void			*tmp;
	unsigned char	*str;
	char			*buf;

	if ((fd = open(path, O_RDONLY)) < 0)
		error_msg("ERROR : CAN'T OPEN FILE.\n");
	if (!(buf = malloc(sizeof(unsigned char) * 100)) ||
		!(str = (unsigned char *)ft_strdup("\0")))
		error_msg("ERROR : CAN'T MALLOC.\n");
	while ((len = read(fd, buf, 99)) > 0)
	{
		buf[len] = '\0';
		str = (unsigned char *)ft_strjoin((tmp = str), buf);
		free(tmp);
	}
	return (check_buf(str));
}
