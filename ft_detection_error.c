/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:41:14 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/16 23:41:15 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_detection_error(int fd, char *str)
{
	if (fd)
	{
		while ((read(fd, str, BUFF_SIZE)))
		{
			if (!(ft_check_char(str, '#', '.', '\n')))
			{
				close (fd);
				ft_putstr("error\n");
				return (-1);
			}
		}
		close (fd);
		return (1);
	}
	else
	{
		ft_putstr("--- Error File Descritor ---\n");
		return (0);
	}
}
			