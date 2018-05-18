/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:14:02 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/18 08:14:03 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_piece(unsigned int nb_piece, char *id_piece, t_tetri *list)
{
	char 	**piece;
	t_tetri *head;
	int 	i;
	int 	j;
	int 	tmp;

	i = 0;
	head = list;
	if (nb_piece && id_piece && list)
	{
		if (!(piece = (char **)malloc(sizeof(char *) * nb_piece + 1)))
			return (NULL);
		piece[nb_piece + 1] = 0;
		while (nb_piece)
		{
			j = 0;
			tmp = id_piece[i];
			list = head;
			while (++j <= tmp)
				list = list->next;
			piece[i] = ft_strdup(list->piece);
			++i;
			nb_piece--;
		}
		return (piece);
	}
	return (NULL);
}