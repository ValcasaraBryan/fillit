/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:27:03 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/30 18:37:17 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	char	buf[BUFF_SIZE + 1];
	char	*lib;
	char	**tab_pieces;
	char	*sq;
	t_tetri	*db;

	db = init_db();
	if (argc != 2)
	{
		ft_putstr("usage : fillit [file]\n");
		return (0);
	}
	if (!(lib = check_file(argv[1], buf)))
		return (0);
	sq = create_square(min_square_finder(ft_strlen(lib)));
	if (sq == NULL)
	{
		print_error();
		return (0);
	}
	tab_pieces = tab_lib_creator(lib, db);
	sq = tetrisolver(sq, 0, 0, tab_pieces);
	ft_putstr(sq);
	return (0);
}
