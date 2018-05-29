/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:59:13 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/29 02:10:27 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_next_piece(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*piece;
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
