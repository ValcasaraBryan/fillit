/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 02:20:55 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/29 02:20:58 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char				**add_piece(char *id_piece, t_tetri *list, char **piece)
{
	t_tetri			*head;
	int				i;
	int				j;
	int				tmp;
	unsigned int	nb_piece;

	i = 0;
	nb_piece = ft_strlen(id_piece) + 1;
	head = list;
	if (nb_piece && id_piece && list)
	{
		while (--nb_piece)
		{
			j = 1;
			tmp = id_piece[i];
			list = head;
			while (++j <= tmp)
				list = list->next;
			if (list->piece)
				piece[i++] = ft_strdup(list->piece);
		}
		piece[i] = NULL;
		return (piece);
	}
	return (NULL);
}

char				**tab_lib_creator(char *id_piece, t_tetri *list)
{
	char			**piece;
	unsigned int	nb_piece;

	if (id_piece)
	{
		nb_piece = ft_strlen(id_piece);
		if (!(piece = (char **)malloc(sizeof(char *) * nb_piece + 1)))
			return (NULL);
		piece[nb_piece + 1] = 0;
		if (!(piece = add_piece(id_piece, list, piece)))
			return (NULL);
		else
			return (piece);
	}
	return (NULL);
}
