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

	ret = 0;
	if ((!(buf = ft_memalloc(BUFF_SIZE + 1))
		|| (!(ret = read(fd, buf, BUFF_SIZE)))))
		return (NULL);
	if (buf)
	{
		if (ret == 21)
		{
			tmp = ft_strndup(buf, 20);
			return (tmp);
		}
	}
	return (buf);
}
