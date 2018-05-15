/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetridetector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:21:37 by adstuder          #+#    #+#             */
/*   Updated: 2018/05/15 23:16:23 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*tetridetector(char *str)
{
	char *pc;
	int i;
	int j;
	int k;

	if (!str)
		return (NULL);
	if (!(pc = malloc(sizeof(char) * 8)))
		return (NULL);
	pc[7] = '\0';
	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '#')
		i++;
	pc[k] = '#';
	k++;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '#' && str[i + j] != '\0')
		{
			j++;
		}
		if (j == 3)
		{
			pc[k] = '-';
			k++;
		}
		if (j == 4)
		{
			pc[k] = '<';
			k++;
		}
		if (j == 5)
		{
			pc[k] = '$';
			k++;
		}
		if (str[i + j] == '#')
		{
				pc[k] = '#';
				k++;
		}
		i = i + j;
	}
	while (pc[k] != '\0')
	{
		pc[k] = '.';
		k++;
	}
	return (pc);
}

