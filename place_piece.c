/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 21:47:33 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/30 16:43:29 by adstuder         ###   ########.fr       */
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

int			get_square_size(char *sq)
{
	int		i;

	i = 0;
	while (sq[i] != '\n' && sq[i] != '\0')
		i++;
	return (i);
}

char		*sub_place_piece(int start, int sqsize, char *sq, char c)
{
	if (start <= ((sqsize * (sqsize + 1)) - 2))
	{
		if (sq[start] == '.')
			sq[start] = c + 65;
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
	return (sq);
}

char		*place_piece(char *piece, char c, char *sq, int start)
{
	int		i;
	int		j;
	int		sqsize;
	char	*sqtmp;

	i = 0;
	j = -1;
	sqsize = get_square_size(sq);
	while (piece[++j] != '\0')
	{
		if (piece[j] == '$')
			i = i + sqsize - 1;
		if (piece[j] == '<')
			i = i + sqsize - 2;
		if (piece[j] == '-')
			i = i + sqsize - 3;
		if (piece[j] == '#')
		{
			if (!(sqtmp = sub_place_piece(start + i, sqsize, sq, c)))
				return (NULL);
			sq = sqtmp;
		}
		i++;
	}
	return (sq);
}
