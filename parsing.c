/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 02:16:59 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/30 17:37:42 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_char(char *buf, int ret)
{
	int	i;
	int	hashtag_compt;
	int	point_compt;
	int	newline_compt;

	i = 0;
	hashtag_compt = 0;
	point_compt = 0;
	newline_compt = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
			hashtag_compt++;
		if (buf[i] == '.')
			point_compt++;
		if (buf[i] == '\n')
			newline_compt++;
		i++;
	}
	if ((ret == 21 && (hashtag_compt != 4 || point_compt != 12 ||
		newline_compt != 5)) || (ret == 20 && (hashtag_compt != 4
		|| point_compt != 12 || newline_compt != 4)))
		return (-1);
	return (1);
}

int		check_pieces(int fd, char *buf)
{
	int ret;
	int rettmp;

	rettmp = 0;
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		rettmp = ret;
		if (check_char(buf, ret) == -1)
			return (-1);
	}
	if (ret == 0 && rettmp != 20)
		return (-1);
	return (1);
}

char	*print_error(void)
{
	ft_putstr("error\n");
	return (NULL);
}

char	*check_file(char *argv, char *buf)
{
	char	*lib;
	char	*piece_str;
	int		id_piece;
	int		fd;
	t_tetri	*start;

	start = init_db();
	lib = ft_strdup("");
	fd = open(argv, O_RDONLY);
	if (check_pieces(fd, buf) == -1)
		return (print_error());
	close(fd);
	fd = open(argv, O_RDONLY);
	while ((buf = get_next_piece(fd)))
	{
		piece_str = tetridetector(buf);
		id_piece = tetricmp(piece_str, start);
		if (id_piece == -1)
			return (print_error());
		free(piece_str);
		lib = library_generator(id_piece, lib);
	}
	return (lib);
}
