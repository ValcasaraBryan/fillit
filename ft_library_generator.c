/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tab_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:27:16 by adstuder          #+#    #+#             */
/*   Updated: 2018/05/16 22:51:26 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*library_generator(int id, char *str)
{
	char	*lib;
	int		sz;
	int		i;

	if (str)
		sz = ft_strlen(str);
	i = 0;
	if (!(lib = malloc(sizeof(char) * sz + 2)))
		return (NULL);
	lib[sz + 1] = '\0';
	while (i < sz)
	{
		lib[i] = str[i];
		i++;
	}
	lib[i] = id;
	free(str);
	return (lib);
}
