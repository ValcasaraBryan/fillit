/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:27:03 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/15 18:27:41 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*id;
	char	*str;
	char	**tab_piece;
	char 	*map;
	int 	i;
	int		index;
	int		min_square;
	int		y;

	str = ft_memalloc(BUFF_SIZE + 1);
	i = 0;
	if (argc == 2)
	{
		printf("#@%s\n", argv[1]);
		id = ft_check_file(argv[1], str);
	}
	else
	{
		printf("Too Many Arguments\n");
		return (0);
	}
	if (!str)
		free(str);
	if (id)
	{
		index = 0;
		y = 0;
		if (!(tab_piece = ft_tab_pieces(id, init_db())))
			return (0);
		min_square = min_square_finder(ft_strlen(id));
		map = create_square(min_square + index);
		while (tab_piece[y])
		{
			place_piece(tab_piece[y], y + 65, map, min_square + index);
			// index++;															// backtracking
			// carre = ft_smallest_square((nb_piece + index), tmp); 			// backtracking
			// free(map);														// backtracking
			// map = ft_strdup(tmp);											// backtracking
			// free(tmp);														// backtracking
			y++;
		}
		printf("%s", map);
	}
	return (0);
}

