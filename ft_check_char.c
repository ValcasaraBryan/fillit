/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:10:50 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/16 22:10:51 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_char(char *buf, char hashtag, char point, char backslash)
{
	int	i;
	int	hashtag_compt;
	int	point_compt;
	int	backslash_compt;

	i = -1;
	hashtag_compt = 0;
	point_compt = 0;
	backslash_compt = 0;
	while (buf[++i])
	{
		if (buf[i] == hashtag)
			++hashtag_compt;
		if (buf[i] == point)
			++point_compt;
		if (buf[i] == backslash)
			++backslash_compt;
	}
	if (((i == (hashtag_compt + point_compt + backslash_compt) &&
		hashtag_compt == 4 && backslash_compt == 5 && point_compt == 12)
		|| (i == (hashtag_compt + point_compt + backslash_compt) &&
		hashtag_compt == 4 && backslash_compt == 4 && point_compt == 12)))
		return (1);
	else
		return (0);
}
