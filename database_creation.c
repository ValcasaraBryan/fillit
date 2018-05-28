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
	tmp->piece = "#$##<#";
	tmp = tmp->next;
	tmp->piece = "#$##$#";
	tmp = tmp->next;
	tmp->piece = "##-##";
	tmp = tmp->next;
	tmp->piece = "##$##";
	tmp = tmp->next;
	tmp->piece = "#<##<#";
	tmp = tmp->next;
	tmp->piece = "#$#$##";
	tmp = tmp->next;
	tmp->piece = "###-#";
	tmp = tmp->next;
	tmp->piece = "##$#$#";
	tmp = tmp->next;
	tmp->piece = "#-###";
	tmp = tmp->next;
	tmp->piece = "#$#<##";
	tmp = tmp->next;
	tmp->piece = "###$#";
	tmp = tmp->next;
	tmp->piece = "##<#$#";
	tmp = tmp->next;
	tmp->piece = "#$###";
}

void		fill_lst(t_tetri **start, int i)
{
	t_tetri	*tmp;
	char	*str;

	tmp = *start;
	str = "4423333333333333333";
	while (++i <= 19)
	{
		tmp->id = i;
		tmp->minsq = str[i];
		tmp = tmp->next;
	}
	tmp = *start;
	tmp->piece = "#$#$#$#";
	tmp = tmp->next;
	tmp->piece = "####";
	tmp = tmp->next;
	tmp->piece = "##<##";
	tmp = tmp->next;
	tmp->piece = "###<#";
	tmp = tmp->next;
	tmp->piece = "#<##$#";
	tmp = tmp->next;
	tmp->piece = "#<###";
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
	i = 19;
	while (i > 0)
	{
		addlink(&start);
		i--;
	}
	i = 0;
	fill_lst(&start, i);
	return (start);
}
