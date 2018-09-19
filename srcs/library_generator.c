/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 02:22:03 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/30 16:49:43 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*library_generator(int id, char *str)
{
	char	*lib;
	int		sz;
	int		i;

	sz = str ? ft_strlen(str) : 0;
	i = -1;
	if (!(lib = malloc(sizeof(char) * sz + 2)))
		return (NULL);
	lib[sz + 1] = '\0';
	while (++i < sz)
		lib[i] = str[i];
	lib[i] = id;
	free(str);
	return (lib);
}
