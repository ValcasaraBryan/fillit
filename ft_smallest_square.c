/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:49:12 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/19 22:48:17 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*create_square(int size)
{
	char	*sq;
	int		i;
	int		j;

	i = 0;
	if (!(sq = malloc(sizeof(char) * (size * (size + 1) + 1))))
		return (NULL);
	sq[(size * (size + 1))] = '\0';
	while (i < (size * (size + 1)))
	{
		sq[i] = '.';
		i++;
	}
	sq[(size * (size + 1))] = '\0';
	j = 1;
	while (j <= size)
	{
		sq[(size * j) + (j - 1)] = '\n';
		j++;
	}
	return (sq);
}

int			min_square_finder(int len)
{
	if (len == 1)
		return (2);
	if (len == 2)
		return (3);
	if ((len == 3) || (len == 4))
		return (4);
	if ((len == 5) || (len == 6))
		return (5);
	if (len == 7 || len == 8 || len == 9)
		return (6);
	if (len == 10 || len == 11 || len == 12)
		return (7);
	if (len == 13 || len == 14 || len == 15 || len == 16)
		return (8);
	if (len == 17 || len == 18 || len == 19 || len == 20)
		return (9);
	if (len == 21 || len == 22 || len == 23 || len == 24 || len == 25)
		return (10);
	if (len == 26)
		return (11);
	if (len > 26 || len < 1)
		return (-1);
	return (0);
}
