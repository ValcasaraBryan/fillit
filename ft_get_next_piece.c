/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:59:13 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/15 22:59:14 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_next_piece(int fd)
{
	char		*buf;
	char		*tmp;
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	if ((!(buf = ft_memalloc(BUFF_SIZE + 1))
		|| (!(ret = read(fd, buf, BUFF_SIZE)))))
		return (NULL);
	if (buf)
	{
		if ((i = ft_check_char(buf, '#', '.', '\n')))
		{
			if (ret == 21)
			{
				tmp = ft_strndup(buf, 20);
				return (tmp);
			}
		}
		else
			return (NULL);
	}
	return (buf);
}

int		ft_check_char(char *buf, char hashtag, char point, char backslash)
{
	int	i;
	int	hashtag_compt;
	int	point_compt;
	int	backslash_compt;

	i = -1;
	hashtag_compt = 0;
	point_compt = 0;
	backslash_compt = 0;
	while (buf[++i])
	{
		if (buf[i] == hashtag)
			++hashtag_compt;
		if (buf[i] == point)
			++point_compt;
		if (buf[i] == backslash)
			++backslash_compt;
	}
	if (((i == (hashtag_compt + point_compt + backslash_compt) &&
		hashtag_compt == 4 && backslash_compt == 5 && point_compt == 12)
		|| (i == (hashtag_compt + point_compt + backslash_compt) &&
		hashtag_compt == 4 && backslash_compt == 4 && point_compt == 12)))
		return (1);
	else
		return (0);
}
