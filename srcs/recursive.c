/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:59:59 by adstuder          #+#    #+#             */
/*   Updated: 2018/05/30 17:33:36 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			get_start(char *sq, char c)
{
	int		i;

	i = 0;
	while (sq[i] != (c + 65) && sq[i] != '\0')
		i++;
	return (i);
}

char		*tetrisolver(char *sq, char c, int start, char **tab_pieces)
{
	char	*sqtmp;
	int		sqsize;

	sqsize = get_square_size(sq);
	while (tab_pieces[(int)c] != NULL)
	{
		if (start > ((sqsize * (sqsize + 1)) - 2))
		{
			start = c == 0 ? 0 : get_start(sq, c - 1) + 1;
			sqsize = c == 0 ? sqsize + 1 : sqsize;
			sq = c == 0 ? create_square(sqsize) : erase_piece(sq, c - 1);
			c = (c == 0) ? c : c - 1;
		}
		if ((sqtmp = place_piece(tab_pieces[(int)c], c, sq, start)))
		{
			sq = sqtmp;
			start = -1;
			c++;
		}
		start++;
	}
	return (sq);
}
