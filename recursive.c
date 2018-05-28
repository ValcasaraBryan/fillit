/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:59:59 by adstuder          #+#    #+#             */
/*   Updated: 2018/05/25 23:48:30 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_start(char *sq, char c)
{
	int i;

	i = 0;
	while (sq[i] != (c + 65) && sq[i] != '\0')
		i++;
	return (i);
}



char	*tetrisolver(char *sq, char c, int start, char **tab_pieces)
{
	char *sqtmp;
	int sqsize;

	sqsize = get_square_size(sq);
	if (start > ((sqsize * (sqsize + 1)) - 2))
	{
		if (c == 0)
		{
			start = 0;
			sqsize++;
			sq = create_square(sqsize);
		}
		else
		{
			c--;
			start = get_start(sq, c) + 1;
			erase_piece(sq, c);
		}
	}
	if (tab_pieces[c] == 0)
		return (sq);
	if ((sqtmp = place_piece(tab_pieces[c], c, sq, start)))
	{
		sq = sqtmp;
		if ((sqtmp = tetrisolver(sq, c + 1, 0, tab_pieces)))
			return (sqtmp);
	}
	return (tetrisolver(sq, c, start + 1, tab_pieces));
}
