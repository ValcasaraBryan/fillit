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

#include "../includes/fillit.h"

int			print_error(int i)
{
	if (i == USAGE)
		ft_putstr("usage: fillit [file]\n");
	else if (i == ERROR)
		ft_putstr("error\n");
	return (0);
}

int			main(int argc, char **argv)
{
	char	buf[BUFF_SIZE + 1];
	char	*lib;
	char	**tab_pieces;
	char	*sq;
	t_tetri	*db;

	db = init_db();
	sq = NULL;
	lib = NULL;
	if (argc != USAGE)
		return (print_error(USAGE));
	if (!(lib = check_file(argv[1], buf, db)))
		return (print_error(0));
	if (lib)
		sq = create_square(min_square_finder(ft_strlen(lib)));
	if (sq == NULL)
		return (print_error(ERROR));
	tab_pieces = tab_lib_creator(lib, db);
	sq = tetrisolver(sq, 0, 0, tab_pieces);
	ft_putstr(sq);
	return (0);
}
