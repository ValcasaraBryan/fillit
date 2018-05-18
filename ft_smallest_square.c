/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:49:12 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/18 07:49:13 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_smallest_square(int nb_piece, char *map)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = nb_piece - 1;
	if (map && nb_piece)
	{
		while (y != nb_piece)
		{
			map[x] = '.';
			x++;
			if (x == ((nb_piece * nb_piece) - (nb_piece * z) + y))
			{
				map[x] = '\n';
				x++;
				z--;
				y++;
			}
		}
		map[x] = '\0';
		return (nb_piece);
	}
	return (0);
}
