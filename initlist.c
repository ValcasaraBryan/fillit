/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:33:35 by adstuder          #+#    #+#             */
/*   Updated: 2018/05/15 21:38:50 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fill_lst2(t_tetri *tmp)
{
	tmp->piece = "#$##<#"; // 6
	tmp = tmp->next;
	tmp->piece = "#$##$#"; // 7
	tmp = tmp->next;
	tmp->piece = "##-##"; // 8
	tmp = tmp->next;
	tmp->piece = "##$##"; // 9
	tmp = tmp->next;
	tmp->piece = "#<##<#"; // 10
	tmp = tmp->next;
	tmp->piece = "#$#$##"; // 11
	tmp = tmp->next;
	tmp->piece = "###-#"; // 12
	tmp = tmp->next;
	tmp->piece = "##$#$#"; // 13
	tmp = tmp->next;
	tmp->piece = "#-###";// 14
	tmp = tmp->next;
	tmp->piece = "#$#<##"; // 15
	tmp = tmp->next;
	tmp->piece = "###$#"; // 16
	tmp = tmp->next;
	tmp->piece = "##<#$#"; // 17
	tmp = tmp->next;
	tmp->piece = "#$###"; // 18
}

void		fill_lst(t_tetri **start, int i)
{
	t_tetri	*tmp;
	char	*str;

	tmp = *start;
	str = "4423333333333333333";
	while (++i <= 18)
	{
		tmp->id = i;
		tmp->minsq = str[i];
		tmp = tmp->next;
	}
	tmp = *start;
	tmp->piece = "#$#$#$#"; // 0
	tmp = tmp->next;
	tmp->piece = "####"; // 1
	tmp = tmp->next;
	tmp->piece = "##<##"; // 2
	tmp = tmp->next;
	tmp->piece = "###<#"; // 3
	tmp = tmp->next;
	tmp->piece = "#<##$#";// 4
	tmp = tmp->next;
	tmp->piece = "#<###"; // 5
	tmp = tmp->next;
	fill_lst2(tmp);
}

void		addlink(t_tetri **start)
{
	t_tetri	*new;

	if (!(new = malloc(sizeof(t_tetri))))
		return ;
	new->next = NULL;
	if ((*start)->next == NULL)
		(*start)->next = new;
	else
		addlink(&(*start)->next);
}

t_tetri		*init_db(void)
{
	t_tetri	*start;
	int		i;

	if (!(start = malloc(sizeof(t_tetri))))
		return (NULL);
	start->next = NULL;
	i = 18;
	while (i > 0)
	{
		addlink(&start);
		i--;
	}
	i = -1;
	fill_lst(&start, i);
	return (start);
}
