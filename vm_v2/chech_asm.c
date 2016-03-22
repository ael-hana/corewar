/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:42:19 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/17 18:55:53 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		prog_size(unsigned char *str, int i)
{
	unsigned int	len;

	i < 140 ? error_msg("ERROR : PROG SIZE\n") : 0;
	len = str[136];
	len = len << 8;
	len += str[137];
	len = len << 8;
	len += str[138];
	len = len << 8;
	len += str[139];
	!len ? error_msg("ERROR : PROG SIZE\n") : 0;
	return (len);
}

unsigned int		check_magic(unsigned char *str, int len)
{
	len < 4 ? error_msg("ERROR : MAGIC NUM\n") : 0;
	if (str[0] == 0 && str[1] == 0xEA && str[2] == 0x83 && str[3] == 0xF3)
		return (0xea83f3);
	error_msg("ERROR : MAGIC NUM\n");
	return (0);
}

void				check_comment(unsigned char *str, char *tab, int len)
{
	int				i;

	i = 140;
	len < 2188 ? error_msg("ERROR : COMMENT\n") : 0;
	while (str[i])
	{
		tab[i - 140] = str[i];
		++i;
	}
	tab[i - 140] = '\0';
}

void				check_name(unsigned char *str, char *tab, int len)
{
	int				i;

	i = 4;
	len < 132 ? error_msg("ERROR : NAME\n") : 0;
	while (str[i])
	{
		tab[i - 4] = str[i];
		++i;
	}
	tab[i - 4] = '\0';
}

t_header			*check_buf(unsigned char *str, int len)
{
	t_header		*ptr;

	if (!(ptr = malloc(sizeof(t_header))))
		error_msg("ERROR : CAN'T MALLOC.\n");
	ptr->magic = check_magic(str, len);
	check_name(str, ptr->prog_name, len);
	ptr->prog_size = prog_size(str, len);
	check_comment(str, ptr->comment, len);
	if ((len - 2192) != ptr->prog_size)
		error_msg("ERROR : PROG SIZE\n");
	if (!(ptr->inst = malloc(sizeof(unsigned char) * ptr->prog_size)))
		error_msg("ERROR : CAN'T MALLOC.\n");
	ft_memcpy(ptr->inst, str + 2192, ptr->prog_size);
	return (ptr);
}
