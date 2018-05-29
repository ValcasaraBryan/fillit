/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 02:22:03 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/29 02:22:05 by brvalcas         ###   ########.fr       */
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
