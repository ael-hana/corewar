/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parssing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:14:19 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/17 19:25:54 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void				error_msg(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

unsigned char		*mem_realloc(unsigned char *str, unsigned char *tab,
					int a, int b)
{
	void			*tmp;

	if (!(tmp = malloc(sizeof(unsigned char *) * (a + b + 1))))
		error_msg("ERROR : CAN'T MALLOC.\n");
	ft_memcpy(tmp, str, a);
	ft_memcpy(tmp + a, tab, b);
	if (a)
		free(str);
	return (tmp);
}

t_header			*create_player(char *path)
{
	int				fd;
	int				i;
	int				len;
	void			*tmp;
	unsigned char	*str;

	len = 0;
	ft_printf("|%s|\n", path);
	if ((fd = open(path, O_RDONLY)) < 0)
		error_msg("ERROR : CAN'T OPEN FILE.\n");
	if (!(tmp = malloc(sizeof(unsigned char) * 100)) ||
		!(str = (unsigned char *)ft_strdup("\0")))
		error_msg("ERROR : CAN'T MALLOC.\n");
	while ((i = read(fd, tmp, sizeof(unsigned char) * 100)) > 0)
	{
		str = mem_realloc(str, tmp, len, i);
		len += i;
	}
	free(tmp);
//	len > (MEM_SIZE / 6) ? error_msg("CHAMP TO LARGE\n") : 0;
	tmp = check_buf(str, len);
	free(str);
	return (tmp);
}
