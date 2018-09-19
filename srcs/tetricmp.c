/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetricmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:19:07 by adstuder          #+#    #+#             */
/*   Updated: 2018/05/16 22:26:53 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		tetricmp(char *str, t_tetri *start)
{
	t_tetri	*tmp;

	tmp = start;
	if (tmp && str)
		while (tmp->piece)
		{
			if (ft_strcmp(str, tmp->piece) == 0)
				return (tmp->id);
			tmp = tmp->next;
		}
	return (-1);
}
