/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetridetector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:21:37 by adstuder          #+#    #+#             */
/*   Updated: 2018/05/24 20:17:04 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

char	*subdetector(char *str, int i, int k, char *pc)
{
	int j;

	while (str[i])
	{
		j = 0;
		while (str[i + j] != '#' && str[i + j] != '\0')
			j++;
		if (str[i + j] == '#')
		{
			if (j == 2)
				pc[k] = '-';
			if (j == 3)
				pc[k] = '<';
			if (j == 4)
				pc[k] = '$';
			if (j >= 5 || j == 1)
				return (NULL);
			if (j == 2 || j == 3 || j == 4)
				k++;
			pc[k++] = '#';
		}
		i = i + j + 1;
	}
	pc[k] = '\0';
	return (pc);
}

char	*tetridetector(char *str)
{
	char	*pc;
	int		i;
	int		j;
	int		k;

	if (!str)
		return (NULL);
	if (!(pc = malloc(sizeof(char) * 8)))
		return (NULL);
	pc[7] = '\0';
	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '#' && str[i] != '\0')
		i++;
	pc[k] = '#';
	k++;
	i++;
	if (str[i])
		pc = subdetector(str, i, k, pc);
	return (pc);
}
