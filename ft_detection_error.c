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
				close(fd);
				free(str);
				ft_putstr("error\n");
				return (0);
			}
		}
		close(fd);
		return (1);
	}
	else
	{
		ft_putstr("--- Error File Descritor ---\n");
		return (-1);
	}
}

int		ft_send_error(int id_piece, char *id)
{
	if (id == NULL || id_piece == (-1))
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (0);
}

char	*ft_check_file(char *argv, char *str)
{
	char	*file;
	char	*id;
	int		id_piece;
	int		fd;

	id = 0;
	file = ft_strdup("");
	fd = open(argv, O_RDONLY);
	if (ft_detection_error(fd, str) == 1)
	{
		fd = open(argv, O_RDONLY);
		while ((str = ft_get_next_piece(fd)))
		{
			id = tetridetector(str);
			id_piece = tetricmp(id, init_db());
			if (ft_send_error(id_piece, id) == 0)
				file = library_generator(id_piece, file);
			else
				return (NULL);
			free(id);
			free(str);
		}
		return (file);
	}
	return (NULL);
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
