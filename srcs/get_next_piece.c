/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:59:13 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/30 16:50:04 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*get_next_piece(int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret == 0)
		return (NULL);
	buf[ret] = '\0';
	if (ret == 21)
	{
		buf[20] = '\0';
	}
	return (ft_strdup(buf));
}
