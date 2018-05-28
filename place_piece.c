/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 21:47:33 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/25 22:29:29 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*erase_piece(char *sq, char c)
{
	int		i;

	i = 0;
	while (sq[i] != '\0')
	{
		if (sq[i] == c + 65)
			sq[i] = '.';
		i++;
	}
	return (sq);
}

int		get_square_size(char *sq)
{
	int i;

	i = 0;
	while (sq[i] != '\n' && sq[i] != '\0')
		i++;
	return (i);
}

char *place_piece(char *piece, char c, char *sq, int start)
{
	int i;
	int j;
	int sqsize;

	i = 0;
	j = 0;
	sqsize = get_square_size(sq);
	while (piece[j] != '\0')
	{
		if (piece[j] == '$')
			i = i + sqsize - 1;
		if (piece[j] == '<')
			i = i + sqsize - 2;
		if (piece[j] == '-')
			i = i + sqsize - 3;
		if (piece[j] == '#')
		{
			if (start + i <= ((sqsize * (sqsize + 1)) - 2))
			{
				if (sq[start + i] == '.')
				{
					sq[start + i] = c + 65;
				}
				else
				{
					erase_piece(sq, c);
					return (NULL);
				}
			}
			else
			{
				erase_piece(sq, c);
				return (NULL);
			}
		}
		i++;
		j++;
	}
	return (sq);
}
